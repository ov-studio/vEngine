#pragma once
#include "Core/Scripting/Lua/vLuaBooter.h"
#include "Core/Interfaces/wiRenderPath3D.h"
#include "Core/Scripting/Lua/wiRenderPath2D_BindLua.h"

namespace wi::lua
{

	class RenderPath3D_BindLua : public RenderPath2D_BindLua
	{
	private:
		RenderPath3D renderpath;
	public:
		static const char className[];
		static Luna<RenderPath3D_BindLua>::FunctionType methods[];
		static Luna<RenderPath3D_BindLua>::PropertyType properties[];

		RenderPath3D_BindLua() = default;
		RenderPath3D_BindLua(RenderPath3D* component)
		{
			this->component = component;
		}
		RenderPath3D_BindLua(lua_State* L)
		{
			this->component = &renderpath;
		}

		int SetAO(lua_State* L);
		int SetSSREnabled(lua_State* L);
		int SetRaytracedReflectionsEnabled(lua_State* L);
		int SetShadowsEnabled(lua_State* L);
		int SetReflectionsEnabled(lua_State* L);
		int SetFXAAEnabled(lua_State* L);
		int SetBloomEnabled(lua_State* L);
		int SetBloomThreshold(lua_State* L);
		int SetColorGradingEnabled(lua_State* L);
		int SetVolumeLightsEnabled(lua_State* L);
		int SetLightShaftsEnabled(lua_State* L);
		int SetLensFlareEnabled(lua_State* L);
		int SetMotionBlurEnabled(lua_State* L);
		int SetDitherEnabled(lua_State* L);
		int SetDepthOfFieldEnabled(lua_State* L);
		int SetEyeAdaptionEnabled(lua_State* L);
		int SetMSAASampleCount(lua_State* L);
		int SetSharpenFilterEnabled(lua_State* L);
		int SetSharpenFilterAmount(lua_State* L);
		int SetExposure(lua_State* L);
		int SetMotionBlurStrength(lua_State* L);
		int SetDepthOfFieldStrength(lua_State* L);

		static void Bind(lua_State* L);
	};

}
