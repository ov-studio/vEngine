#pragma once
#include "Core/Scripting/Lua/vLuaBooter.h"
#include "Core/Input/wiInput.h"

namespace wi::lua
{

	class Input_BindLua
	{
	public:
		static const char className[];
		static Luna<Input_BindLua>::FunctionType methods[];
		static Luna<Input_BindLua>::PropertyType properties[];

		Input_BindLua(lua_State* L) {}

		int Down(lua_State* L);
		int Press(lua_State* L);
		int Hold(lua_State* L);
		int GetPointer(lua_State* L);
		int SetPointer(lua_State* L);
		int GetPointerDelta(lua_State* L);
		int HidePointer(lua_State* L);
		int GetAnalog(lua_State* L);
		int GetTouches(lua_State* L);
		int SetControllerFeedback(lua_State* L);

		static void Bind(lua_State* L);
	};

	class Touch_BindLua
	{
	public:
		wi::input::Touch touch;
		static const char className[];
		static Luna<Touch_BindLua>::FunctionType methods[];
		static Luna<Touch_BindLua>::PropertyType properties[];

		Touch_BindLua(lua_State* L) {}
		Touch_BindLua(const wi::input::Touch& touch) :touch(touch) {}

		int GetState(lua_State* L);
		int GetPos(lua_State* L);

		static void Bind(lua_State* L);
	};

	class ControllerFeedback_BindLua
	{
	public:
		wi::input::ControllerFeedback feedback;
		static const char className[];
		static Luna<ControllerFeedback_BindLua>::FunctionType methods[];
		static Luna<ControllerFeedback_BindLua>::PropertyType properties[];

		ControllerFeedback_BindLua(lua_State* L) {}
		ControllerFeedback_BindLua(const wi::input::ControllerFeedback& feedback) :feedback(feedback) {}

		int SetVibrationLeft(lua_State* L);
		int SetVibrationRight(lua_State* L);
		int SetLEDColor(lua_State* L);

		static void Bind(lua_State* L);
	};

}
