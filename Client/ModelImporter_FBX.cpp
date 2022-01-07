#include "stdafx.h"
#include "Core/Systems/wiScene.h"
#include "ModelImporter.h"

#include <fbxsdk.h>
#include <fbxsdk/fileio/fbxiosettings.h>

#include <string>
#include <istream>
#include <streambuf>

using namespace wi::graphics;
using namespace wi::scene;
using namespace wi::ecs;

void ImportModel_FBX(const std::string& fileName, Scene& scene)
{
	std::string directory = wi::helper::GetDirectoryFromPath(fileName);
	std::string name = wi::helper::GetFileNameFromPath(fileName);
	std::string error;

	wi::vector<uint8_t> filedata;
	bool success = wi::helper::FileRead(fileName, filedata);

	if (success)
	{
		FbxManager* lSdkManager = FbxManager::Create();
		FbxIOSettings* ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
		lSdkManager->SetIOSettings(ios);

        // Create an importer.
        FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");
        // Initialize the importer.
		const char* lFilename = fileName.c_str();
        success = lImporter->Initialize(lFilename, -1, lSdkManager->GetIOSettings());
        if (!success) {
            wi::backlog::post("Call to FbxImporter::Initialize() failed.\n", wi::backlog::LogLevel::Error);
            wi::backlog::post(lImporter->GetStatus().GetErrorString(), wi::backlog::LogLevel::Error);
        }
		else {
			// Create a new scene so it can be populated by the imported file.
			FbxScene* lScene = FbxScene::Create(lSdkManager, lFilename);
			// Import the contents of the file into the scene.
			lImporter->Import(lScene);
			wi::backlog::post("Tron: Loaded into importer!.\n");
		}
	}
	else
	{
		error = "Failed to read file: " + fileName;
	}

	if (!error.empty())
	{
		wi::backlog::post(error, wi::backlog::LogLevel::Error);
	}

	if (success)
	{
		/*
		Entity rootEntity = CreateEntity();
		scene.transforms.Create(rootEntity);
		scene.names.Create(rootEntity) = name;
		// Load material library:
		wi::vector<Entity> materialLibrary = {};
		for (auto& obj_material : obj_materials)
		{
			Entity materialEntity = scene.Entity_CreateMaterial(obj_material.name);
			MaterialComponent& material = *scene.materials.GetComponent(materialEntity);

			material.baseColor = XMFLOAT4(obj_material.diffuse[0], obj_material.diffuse[1], obj_material.diffuse[2], 1);
			material.textures[MaterialComponent::BASECOLORMAP].name = obj_material.diffuse_texname;
			material.textures[MaterialComponent::DISPLACEMENTMAP].name = obj_material.displacement_texname;
			material.emissiveColor.x = obj_material.emission[0];
			material.emissiveColor.y = obj_material.emission[1];
			material.emissiveColor.z = obj_material.emission[2];
			material.emissiveColor.w = std::max(obj_material.emission[0], std::max(obj_material.emission[1], obj_material.emission[2]));
			//material.refractionIndex = obj_material.ior;
			material.metalness = obj_material.metallic;
			material.textures[MaterialComponent::NORMALMAP].name = obj_material.normal_texname;
			material.textures[MaterialComponent::SURFACEMAP].name = obj_material.specular_texname;
			material.roughness = obj_material.roughness;

			if (material.textures[MaterialComponent::NORMALMAP].name.empty())
			{
				material.textures[MaterialComponent::NORMALMAP].name = obj_material.bump_texname;
			}
			if (material.textures[MaterialComponent::SURFACEMAP].name.empty())
			{
				material.textures[MaterialComponent::SURFACEMAP].name = obj_material.specular_highlight_texname;
			}

			for (auto& x : material.textures)
			{
				if (!x.name.empty())
				{
					x.name = directory + x.name;
				}
			}

			material.CreateRenderData();

			materialLibrary.push_back(materialEntity); // for subset-indexing...
		}

		if (materialLibrary.empty())
		{
			// Create default material if nothing was found:
			Entity materialEntity = scene.Entity_CreateMaterial("OBJImport_defaultMaterial");
			MaterialComponent& material = *scene.materials.GetComponent(materialEntity);
			materialLibrary.push_back(materialEntity); // for subset-indexing...
		}

		// Load objects, meshes:
		for (auto& shape : obj_shapes)
		{
			Entity objectEntity = scene.Entity_CreateObject(shape.name);
			scene.Component_Attach(objectEntity, rootEntity);
			Entity meshEntity = scene.Entity_CreateMesh(shape.name + "_mesh");
			ObjectComponent& object = *scene.objects.GetComponent(objectEntity);
			MeshComponent& mesh = *scene.meshes.GetComponent(meshEntity);

			object.meshID = meshEntity;

			wi::unordered_map<int, int> registered_materialIndices = {};
			wi::unordered_map<size_t, uint32_t> uniqueVertices = {};

			for (size_t i = 0; i < shape.mesh.indices.size(); i += 3)
			{
				tinyobj::index_t reordered_indices[] = {
					shape.mesh.indices[i + 0],
					shape.mesh.indices[i + 1],
					shape.mesh.indices[i + 2],
				};

				// todo: option param would be better
				bool flipCulling = false;
				if (flipCulling)
				{
					reordered_indices[1] = shape.mesh.indices[i + 2];
					reordered_indices[2] = shape.mesh.indices[i + 1];
				}

				for (auto& index : reordered_indices)
				{
					XMFLOAT3 pos = XMFLOAT3(
						obj_attrib.vertices[index.vertex_index * 3 + 0],
						obj_attrib.vertices[index.vertex_index * 3 + 1],
						obj_attrib.vertices[index.vertex_index * 3 + 2]
					);

					XMFLOAT3 nor = XMFLOAT3(0, 0, 0);
					if (!obj_attrib.normals.empty())
					{
						nor = XMFLOAT3(
							obj_attrib.normals[index.normal_index * 3 + 0],
							obj_attrib.normals[index.normal_index * 3 + 1],
							obj_attrib.normals[index.normal_index * 3 + 2]
						);
					}

					XMFLOAT2 tex = XMFLOAT2(0, 0);
					if (index.texcoord_index >= 0 && !obj_attrib.texcoords.empty())
					{
						tex = XMFLOAT2(
							obj_attrib.texcoords[index.texcoord_index * 2 + 0],
							1 - obj_attrib.texcoords[index.texcoord_index * 2 + 1]
						);
					}

					int materialIndex = std::max(0, shape.mesh.material_ids[i / 3]); // this indexes the material library
					if (registered_materialIndices.count(materialIndex) == 0)
					{
						registered_materialIndices[materialIndex] = (int)mesh.subsets.size();
						mesh.subsets.push_back(MeshComponent::MeshSubset());
						mesh.subsets.back().materialID = materialLibrary[materialIndex];
						mesh.subsets.back().indexOffset = (uint32_t)mesh.indices.size();
					}

					if (transform_to_LH)
					{
						pos.z *= -1;
						nor.z *= -1;
					}

					// eliminate duplicate vertices by means of hashing:
					size_t vertexHash = 0;
					wi::helper::hash_combine(vertexHash, index.vertex_index);
					wi::helper::hash_combine(vertexHash, index.normal_index);
					wi::helper::hash_combine(vertexHash, index.texcoord_index);
					wi::helper::hash_combine(vertexHash, materialIndex);

					if (uniqueVertices.count(vertexHash) == 0)
					{
						uniqueVertices[vertexHash] = (uint32_t)mesh.vertex_positions.size();
						mesh.vertex_positions.push_back(pos);
						mesh.vertex_normals.push_back(nor);
						mesh.vertex_uvset_0.push_back(tex);
					}
					mesh.indices.push_back(uniqueVertices[vertexHash]);
					mesh.subsets.back().indexCount++;
				}
			}
			mesh.CreateRenderData();
		}
		*/
	}
	else
	{
		wi::helper::messageBox("FBX import failed! Check backlog for errors!", "Error!");
	}
}
