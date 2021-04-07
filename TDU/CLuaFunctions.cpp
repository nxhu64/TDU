#include "CLuaFunctions.h"
#include "Config.h"
#include "TeardownFunctions.h"

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

	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "CreateBody", &CLuaFunctions::EntityFunctions::CreateBody);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "CreateShape", &CLuaFunctions::EntityFunctions::CreateShape);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "LoadVox", &CLuaFunctions::EntityFunctions::LoadVox);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "InitializeBody", &CLuaFunctions::EntityFunctions::InitializeBody);


	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetNightLight", &CLuaFunctions::EnvFunctions::SetNightLight);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetRain", &CLuaFunctions::EnvFunctions::SetRain);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetPuddleSize", &CLuaFunctions::EnvFunctions::SetPuddleSize);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetPuddleAmount", &CLuaFunctions::EnvFunctions::SetPuddleAmount);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetWetness", &CLuaFunctions::EnvFunctions::SetWetness);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetFogParams", &CLuaFunctions::EnvFunctions::SetFogParams);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetFogColor", &CLuaFunctions::EnvFunctions::SetFogColor);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetExposure", &CLuaFunctions::EnvFunctions::SetExposure);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetBrightness", &CLuaFunctions::EnvFunctions::SetBrightness);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetAmbient", &CLuaFunctions::EnvFunctions::SetAmbient);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetSunGlare", &CLuaFunctions::EnvFunctions::SetSunGlare);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetSunFogScale", &CLuaFunctions::EnvFunctions::SetSunFogScale);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetSunLength", &CLuaFunctions::EnvFunctions::SetSunLength);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetSunSpread", &CLuaFunctions::EnvFunctions::SetSunSpread);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetSunBrightness", &CLuaFunctions::EnvFunctions::SetSunBrightness);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetSunColorTint", &CLuaFunctions::EnvFunctions::SetSunColorTint);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetSunColor", &CLuaFunctions::EnvFunctions::SetSunColor);

	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "UpdateEnvironment", &CLuaFunctions::EnvFunctions::UpdateEnvironment);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "SetSkybox", &CLuaFunctions::EnvFunctions::SetSkybox);
}