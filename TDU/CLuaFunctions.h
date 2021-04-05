#pragma once
#include "Lua.hpp"
#include "Script.h"

/*
	This file should eventually have a different name, or LuaFunctions.h/cpp should have a different name, cause it's gonna cause some confusion
*/

class retInfo
{
public:
	lua_State* pL;
	int retcount;
	// Unk size
};

namespace CLuaFunctions
{
	namespace EntityFunctions
	{
		int CreateBody(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int CreateShape(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int LoadVox(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int InitializeBody(ScriptCore* pSC, lua_State*& L, retInfo* ret);
	}

	namespace EnvFunctions
	{
		int SetSunColorTint(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetSunBrightness(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetSunSpread(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetSunLength(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetSunFogScale(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetSunGlare(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetAmbient(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetBrightness(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetExposure(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetFogColor(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetFogParams(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetWetness(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetPuddleAmount(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetPuddleSize(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetRain(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int SetNightLight(ScriptCore* pSC, lua_State*& L, retInfo* ret);
	}

	void RegisterCFunctions(ScriptCore_LuaState* pSCLS);
}