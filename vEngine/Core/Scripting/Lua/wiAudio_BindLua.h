#pragma once
#include "Core/Scripting/Lua/vLuaBooter.h"
#include "Core/Audio/wiAudio.h"

namespace wi::lua
{
	class Audio_BindLua
	{
	public:
		static const char className[];
		static Luna<Audio_BindLua>::FunctionType methods[];
		static Luna<Audio_BindLua>::PropertyType properties[];

		Audio_BindLua(lua_State* L) {}

		int CreateSound(lua_State* L);
		int CreateSoundInstance(lua_State* L);
		int Play(lua_State* L);
		int Pause(lua_State* L);
		int Stop(lua_State* L);
		int GetVolume(lua_State* L);
		int SetVolume(lua_State* L);
		int ExitLoop(lua_State* L);

		int GetSubmixVolume(lua_State* L);
		int SetSubmixVolume(lua_State* L);

		int Update3D(lua_State* L);
		int SetReverb(lua_State* L);

		static void Bind(lua_State* L);
	};

	class Sound_BindLua
	{
	public:
		wi::audio::Sound sound;

		static const char className[];
		static Luna<Sound_BindLua>::FunctionType methods[];
		static Luna<Sound_BindLua>::PropertyType properties[];

		Sound_BindLua(lua_State* L) {}
		Sound_BindLua(const wi::audio::Sound& sound) :sound(sound) {}

		static void Bind(lua_State* L);
	};

	class SoundInstance_BindLua
	{
	public:
		wi::audio::SoundInstance soundinstance;

		static const char className[];
		static Luna<SoundInstance_BindLua>::FunctionType methods[];
		static Luna<SoundInstance_BindLua>::PropertyType properties[];

		SoundInstance_BindLua(lua_State* L) { }
		~SoundInstance_BindLua() { }

		int SetSubmixType(lua_State* L);

		static void Bind(lua_State* L);
	};

	class SoundInstance3D_BindLua
	{
	public:
		wi::audio::SoundInstance3D soundinstance3D;

		static const char className[];
		static Luna<SoundInstance3D_BindLua>::FunctionType methods[];
		static Luna<SoundInstance3D_BindLua>::PropertyType properties[];

		SoundInstance3D_BindLua(lua_State* L) { }
		SoundInstance3D_BindLua(const wi::audio::SoundInstance3D& soundinstance3D) : soundinstance3D(soundinstance3D) {}
		~SoundInstance3D_BindLua() { }

		int SetListenerPos(lua_State* L);
		int SetListenerUp(lua_State* L);
		int SetListenerFront(lua_State* L);
		int SetListenerVelocity(lua_State* L);
		int SetEmitterPos(lua_State* L);
		int SetEmitterUp(lua_State* L);
		int SetEmitterFront(lua_State* L);
		int SetEmitterVelocity(lua_State* L);
		int SetEmitterRadius(lua_State* L);

		static void Bind(lua_State* L);
	};
}
