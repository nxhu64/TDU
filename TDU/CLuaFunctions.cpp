#include "CLuaFunctions.h"
#include "Config.h"
#include "TeardownFunctions.h"

void reg(ScriptCore_LuaState* pSCLS, const char* name, void* pFunction)
{
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, name, pFunction);
}

void CLuaFunctions::RegisterCFunctions(ScriptCore_LuaState* pSCLS)
{
	lua_State* L = pSCLS->pLSInfo->pLuaState;

	#ifdef ENABLE_DEBUG_LIB
		luaopen_debug(L);
	#endif

	#ifdef ENABLE_OS_LIB
		luaopen_os(L);
	#endif

	#ifdef ENABLE_IO_LIB
		luaopen_io(L);
	#endif

	/*
		Register your functions here
	*/

	reg(pSCLS, "CreateBody", &CLuaFunctions::EntityFunctions::CreateBody);
	reg(pSCLS, "CreateShape", &CLuaFunctions::EntityFunctions::CreateShape);
	reg(pSCLS, "LoadVox", &CLuaFunctions::EntityFunctions::LoadVox);
	reg(pSCLS, "InitializeBody", &CLuaFunctions::EntityFunctions::InitializeBody);


	reg(pSCLS, "SetNightLight", &CLuaFunctions::EnvFunctions::SetNightLight);
	reg(pSCLS, "SetRain", &CLuaFunctions::EnvFunctions::SetRain);
	reg(pSCLS, "SetPuddleSize", &CLuaFunctions::EnvFunctions::SetPuddleSize);
	reg(pSCLS, "SetPuddleAmount", &CLuaFunctions::EnvFunctions::SetPuddleAmount);
	reg(pSCLS, "SetWetness", &CLuaFunctions::EnvFunctions::SetWetness);
	reg(pSCLS, "SetFogParams", &CLuaFunctions::EnvFunctions::SetFogParams);
	reg(pSCLS, "SetFogColor", &CLuaFunctions::EnvFunctions::SetFogColor);
	reg(pSCLS, "SetExposure", &CLuaFunctions::EnvFunctions::SetExposure);
	reg(pSCLS, "SetBrightness", &CLuaFunctions::EnvFunctions::SetBrightness);
	reg(pSCLS, "SetAmbient", &CLuaFunctions::EnvFunctions::SetAmbient);
	reg(pSCLS, "SetSunGlare", &CLuaFunctions::EnvFunctions::SetSunGlare);
	reg(pSCLS, "SetSunFogScale", &CLuaFunctions::EnvFunctions::SetSunFogScale);
	reg(pSCLS, "SetSunLength", &CLuaFunctions::EnvFunctions::SetSunLength);
	reg(pSCLS, "SetSunSpread", &CLuaFunctions::EnvFunctions::SetSunSpread);
	reg(pSCLS, "SetSunBrightness", &CLuaFunctions::EnvFunctions::SetSunBrightness);
	reg(pSCLS, "SetSunColorTint", &CLuaFunctions::EnvFunctions::SetSunColorTint);
	reg(pSCLS, "SetSunColor", &CLuaFunctions::EnvFunctions::SetSunColor);
	reg(pSCLS, "UpdateEnvironment", &CLuaFunctions::EnvFunctions::UpdateEnvironment);
	reg(pSCLS, "SetSkybox", &CLuaFunctions::EnvFunctions::SetSkybox);

	reg(pSCLS, "SetRecoilSlow", &CLuaFunctions::PlayerFunctions::SetRecoilSlow);
	reg(pSCLS, "SetRecoilFast", &CLuaFunctions::PlayerFunctions::SetRecoilFast);

	reg(pSCLS, "SetFlashlightColor", &CLuaFunctions::PlayerFunctions::SetFlashlightColor);
	reg(pSCLS, "SetFlashlightIntensity", &CLuaFunctions::PlayerFunctions::SetFlashlightIntensity);
	reg(pSCLS, "SetFlashlightReach", &CLuaFunctions::PlayerFunctions::SetFlashlightReach);
	reg(pSCLS, "SetFlashlightFogScale", &CLuaFunctions::PlayerFunctions::SetFlashlightFogScale);
	reg(pSCLS, "SetFlashlightFogIter", &CLuaFunctions::PlayerFunctions::SetFlashlightFogIter);
}