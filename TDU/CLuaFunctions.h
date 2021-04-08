#pragma once
#include "Lua.hpp"
#include "Script.h"

class retInfo
{
public:
	lua_State* L;
	int retCount;
	int maxRet;
};

namespace CLuaFunctions
{
	namespace EntityFunctions
	{
		void CreateBody(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void CreateShape(ScriptCore* pSC, lua_State*& L, retInfo* ret);

		void LoadVox(ScriptCore* pSC, lua_State*& L, retInfo* ret);

		void InitializeBody(ScriptCore* pSC, lua_State*& L, retInfo* ret);

		void SetLightPos(ScriptCore* pSC, lua_State*& L, retInfo* ret);
	}

	namespace EnvFunctions
	{
		void SetSunColor(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetSunColorTint(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetSunBrightness(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetSunSpread(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetSunLength(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetSunFogScale(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetSunGlare(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetAmbient(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetBrightness(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetExposure(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetFogColor(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetFogParams(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetWetness(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetPuddleAmount(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetPuddleSize(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetRain(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetNightLight(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void UpdateEnvironment(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetSkybox(ScriptCore* pSC, lua_State*& L, retInfo* ret);
	}

	namespace PlayerFunctions
	{
		void SetRecoilSlow(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetRecoilFast(ScriptCore* pSC, lua_State*& L, retInfo* ret);

		void SetFlashlightColor(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetFlashlightIntensity(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetFlashlightReach(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetFlashlightFogScale(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		void SetFlashlightFogIter(ScriptCore* pSC, lua_State*& L, retInfo* ret);
	}

	void RegisterCFunctions(ScriptCore_LuaState* pSCLS);
}