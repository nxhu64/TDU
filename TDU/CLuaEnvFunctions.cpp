#include "CLuaFunctions.h"
#include "Teardown.h"
#include "TeardownFunctions.h"

/*
	FIXME:
	 - This looks like a mess, there must be a way more efficient way to do this rather than defining the function every time
*/

void CLuaFunctions::EnvFunctions::SetSkybox(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	const char* path = luaL_checkstring(L, 1);
	Teardown::pGame->pScene->pEnvironment->skyboxpath = path;
}

void CLuaFunctions::EnvFunctions::UpdateEnvironment(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::Functions::Utils::UpdateEnvironment();
}

void CLuaFunctions::EnvFunctions::SetSunColorTint(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float r = luaL_checknumber(L, 1);
	float g = luaL_checknumber(L, 2);
	float b = luaL_checknumber(L, 3);
	Teardown::pGame->pScene->pEnvironment->sunColorTint = glm::vec3(r, g, b);
}

void CLuaFunctions::EnvFunctions::SetSunColor(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float r = luaL_checknumber(L, 1);
	float g = luaL_checknumber(L, 2);
	float b = luaL_checknumber(L, 3);
	Teardown::pGame->pScene->pEnvironment->sunColor = glm::vec3(r, g, b);
}

void CLuaFunctions::EnvFunctions::SetSunBrightness(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->sunBrightness = luaL_checknumber(L, 1);
}

void CLuaFunctions::EnvFunctions::SetSunSpread(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->sunSpread = luaL_checknumber(L, 1);
}

void CLuaFunctions::EnvFunctions::SetSunLength(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->sunLength = luaL_checknumber(L, 1);
}

void CLuaFunctions::EnvFunctions::SetSunFogScale(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->sunFogScale = luaL_checknumber(L, 1);
}

void CLuaFunctions::EnvFunctions::SetSunGlare(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->sunGlare = luaL_checknumber(L, 1);
}

void CLuaFunctions::EnvFunctions::SetAmbient(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->ambient = luaL_checknumber(L, 1);
}

void CLuaFunctions::EnvFunctions::SetExposure(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float min = luaL_checknumber(L, 1);
	float max = luaL_checknumber(L, 2);
	Teardown::pGame->pScene->pEnvironment->exposure = glm::vec2(min, max);
}

void CLuaFunctions::EnvFunctions::SetBrightness(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->brightness = luaL_checknumber(L, 1);;
}

void CLuaFunctions::EnvFunctions::SetFogColor(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float r = luaL_checknumber(L, 1);
	float g = luaL_checknumber(L, 2);
	float b = luaL_checknumber(L, 3);
	Teardown::pGame->pScene->pEnvironment->fogColor = glm::vec3(r, g, b);
}

void CLuaFunctions::EnvFunctions::SetFogParams(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float fogStart = luaL_checknumber(L, 1);
	float fogEnd = luaL_checknumber(L, 2);
	float fogAmount = luaL_checknumber(L, 3);
	float fogExponent = luaL_checknumber(L, 4);

	Teardown::pGame->pScene->pEnvironment->fogParams = glm::vec4(fogStart, fogEnd, fogAmount, fogExponent);
}

void CLuaFunctions::EnvFunctions::SetWetness(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->puddleamount = luaL_checknumber(L, 1);;
}

void CLuaFunctions::EnvFunctions::SetPuddleAmount(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->puddleamount = luaL_checknumber(L, 1);;
}

void CLuaFunctions::EnvFunctions::SetPuddleSize(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->puddlesize = luaL_checknumber(L, 1);;
}

void CLuaFunctions::EnvFunctions::SetRain(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->rain = luaL_checknumber(L, 1);;
}

void CLuaFunctions::EnvFunctions::SetNightLight(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->nightlight = luaL_checkint(L, 1);
}
