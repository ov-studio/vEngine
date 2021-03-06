#pragma once

namespace wi::lua
{
	//register function to use in scripts
	bool RegisterFunc(lua_State* L, const std::string& name, lua_CFunction function);
	// Registers Namespace
	void RegisterNamespace(lua_State* L, const char* namespac, const wi::vector<std::string>& namespaceIndex);
	// Registers Library
	void RegisterLibrary(lua_State* L, const std::string& tableName, const luaL_Reg* functions, const char* namespac = NULL, const wi::vector<std::string>& namespaceIndex = {});
	// Registers Object
	bool RegisterObject(lua_State* L, const std::string& tableName, void* object, const char* namespac = NULL, const wi::vector<std::string>& namespaceIndex = {});
	// Add function to the previously registered object
	void AddFunc(lua_State* L, const std::string& name, lua_CFunction function);
	// Add function array to the previously registered object
	void AddFuncs(lua_State* L, const luaL_Reg* functions);
	// Add int member to registered object
	void AddInt(lua_State* L, const std::string& name, int data);

	//get string from lua on stack position
	std::string SGetString(lua_State* L, int stackpos);
	//check if a value is string on the stack position
	bool SIsString(lua_State* L, int stackpos);
	//check if a value is number on the stack position
	bool SIsNumber(lua_State* L, int stackpos);
	//get int from lua on stack position
	int SGetInt(lua_State* L, int stackpos);
	//get long from lua on stack position
	long SGetLong(lua_State* L, int stackpos);
	//get long long from lua on stack position
	long long SGetLongLong(lua_State* L, int stackpos);
	//get float from lua on stack position
	float SGetFloat(lua_State* L, int stackpos);
	//get float2 from lua on stack position
	XMFLOAT2 SGetFloat2(lua_State* L, int stackpos);
	//get float3 from lua on stack position
	XMFLOAT3 SGetFloat3(lua_State* L, int stackpos);
	//get float4 from lua on stack position
	XMFLOAT4 SGetFloat4(lua_State* L, int stackpos);
	//get double from lua on stack position
	double SGetDouble(lua_State* L, int stackpos);
	//get bool from lua on stack position
	bool SGetBool(lua_State* L, int stackpos);
	//get number of elements in the stack, or index of the top element
	int SGetArgCount(lua_State* L);
	//get class context information
	void* SGetUserData(lua_State* L);
	
	//push int to lua stack
	void SSetInt(lua_State* L, int data);
	//push long to lua stack
	void SSetLong(lua_State* L, long data);
	//push long long to lua stack
	void SSetLongLong(lua_State* L, long long data);
	//push float to lua stack
	void SSetFloat(lua_State* L, float data);
	//push float2 to lua stack
	void SSetFloat2(lua_State* L, const XMFLOAT2& data);
	//push float3 to lua stack
	void SSetFloat3(lua_State* L, const XMFLOAT3& data);
	//push float4 to lua stack
	void SSetFloat4(lua_State* L, const XMFLOAT4& data);
	//push double to lua stack
	void SSetDouble(lua_State* L, double data);
	//push string to lua stack
	void SSetString(lua_State* L, const std::string& data);
	//push bool to lua stack
	void SSetBool(lua_State* L, bool data);
	//push pointer (light userdata) to lua stack
	void SSetPointer(lua_State* L, void* data);
	//push null to lua stack
	void SSetNull(lua_State* L);

	//throw error
	void SError(lua_State* L, const std::string& error = "");
	//add new metatable
	void SAddMetatable(lua_State* L, const std::string& name);
};

