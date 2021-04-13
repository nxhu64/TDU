#include "CLuaFunctions.h"
#include "Config.h"
#include "TeardownFunctions.h"

#define regLuaFunc(pSCLS, funcName, funcPointer) Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, funcName, funcPointer)

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

	regLuaFunc(pSCLS, "CreateBody", &CLuaFunctions::EntityFunctions::CreateBody);
	regLuaFunc(pSCLS, "CreateShape", &CLuaFunctions::EntityFunctions::CreateShape);
	regLuaFunc(pSCLS, "LoadVox", &CLuaFunctions::EntityFunctions::LoadVox);
	regLuaFunc(pSCLS, "InitializeBody", &CLuaFunctions::EntityFunctions::InitializeBody);

	regLuaFunc(pSCLS, "SetNightLight", &CLuaFunctions::EnvFunctions::SetNightLight);
	regLuaFunc(pSCLS, "SetRain", &CLuaFunctions::EnvFunctions::SetRain);
	regLuaFunc(pSCLS, "SetPuddleSize", &CLuaFunctions::EnvFunctions::SetPuddleSize);
	regLuaFunc(pSCLS, "SetPuddleAmount", &CLuaFunctions::EnvFunctions::SetPuddleAmount);
	regLuaFunc(pSCLS, "SetWetness", &CLuaFunctions::EnvFunctions::SetWetness);
	regLuaFunc(pSCLS, "SetFogParams", &CLuaFunctions::EnvFunctions::SetFogParams);
	regLuaFunc(pSCLS, "SetFogColor", &CLuaFunctions::EnvFunctions::SetFogColor);
	regLuaFunc(pSCLS, "SetExposure", &CLuaFunctions::EnvFunctions::SetExposure);
	regLuaFunc(pSCLS, "SetBrightness", &CLuaFunctions::EnvFunctions::SetBrightness);
	regLuaFunc(pSCLS, "SetAmbient", &CLuaFunctions::EnvFunctions::SetAmbient);
	regLuaFunc(pSCLS, "SetSunGlare", &CLuaFunctions::EnvFunctions::SetSunGlare);
	regLuaFunc(pSCLS, "SetSunFogScale", &CLuaFunctions::EnvFunctions::SetSunFogScale);
	regLuaFunc(pSCLS, "SetSunLength", &CLuaFunctions::EnvFunctions::SetSunLength);
	regLuaFunc(pSCLS, "SetSunSpread", &CLuaFunctions::EnvFunctions::SetSunSpread);
	regLuaFunc(pSCLS, "SetSunBrightness", &CLuaFunctions::EnvFunctions::SetSunBrightness);
	regLuaFunc(pSCLS, "SetSunColorTint", &CLuaFunctions::EnvFunctions::SetSunColorTint);
	regLuaFunc(pSCLS, "SetSunColor", &CLuaFunctions::EnvFunctions::SetSunColor);
	regLuaFunc(pSCLS, "UpdateEnvironment", &CLuaFunctions::EnvFunctions::UpdateEnvironment);
	regLuaFunc(pSCLS, "SetSkybox", &CLuaFunctions::EnvFunctions::SetSkybox);

	regLuaFunc(pSCLS, "SetRecoilSlow", &CLuaFunctions::PlayerFunctions::SetRecoilSlow);
	regLuaFunc(pSCLS, "SetRecoilFast", &CLuaFunctions::PlayerFunctions::SetRecoilFast);

	regLuaFunc(pSCLS, "SetFlashlightColor", &CLuaFunctions::PlayerFunctions::SetFlashlightColor);
	regLuaFunc(pSCLS, "SetFlashlightIntensity", &CLuaFunctions::PlayerFunctions::SetFlashlightIntensity);
	regLuaFunc(pSCLS, "SetFlashlightReach", &CLuaFunctions::PlayerFunctions::SetFlashlightReach);
	regLuaFunc(pSCLS, "SetFlashlightFogScale", &CLuaFunctions::PlayerFunctions::SetFlashlightFogScale);
	regLuaFunc(pSCLS, "SetFlashlightFogIter", &CLuaFunctions::PlayerFunctions::SetFlashlightFogIter);
}