#include "CLuaFunctions.h"
#include "Teardown.h"

/*
	FIXME:
	 - This looks like a mess, there must be a way more efficient way to do this rather than defining the function every time
*/

int CLuaFunctions::EnvFunctions::SetSunColorTint(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float r = luaL_checknumber(L, 1);
	float g = luaL_checknumber(L, 2);
	float b = luaL_checknumber(L, 3);
	Teardown::pGame->pScene->pEnvironment->sunColorTint = glm::vec3(r, g, b);
	return 0;
}

int CLuaFunctions::EnvFunctions::SetSunBrightness(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->sunBrightness = luaL_checknumber(L, 1);
	return 0;
}

int CLuaFunctions::EnvFunctions::SetSunSpread(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->sunSpread = luaL_checknumber(L, 1);
	return 0;
}

int CLuaFunctions::EnvFunctions::SetSunLength(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->sunLength = luaL_checknumber(L, 1);
	return 0;
}

int CLuaFunctions::EnvFunctions::SetSunFogScale(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->sunFogScale = luaL_checknumber(L, 1);
	return 0;
}

int CLuaFunctions::EnvFunctions::SetSunGlare(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->sunGlare = luaL_checknumber(L, 1);
	return 0;
}

int CLuaFunctions::EnvFunctions::SetAmbient(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->ambient = luaL_checknumber(L, 1);
	return 0;
}

int CLuaFunctions::EnvFunctions::SetExposure(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float min = luaL_checknumber(L, 1);
	float max = luaL_checknumber(L, 2);
	Teardown::pGame->pScene->pEnvironment->exposure = glm::vec2(min, max);
	return 0;
}

int CLuaFunctions::EnvFunctions::SetBrightness(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->brightness = luaL_checknumber(L, 1);;
	return 0;
}

int CLuaFunctions::EnvFunctions::SetFogColor(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float r = luaL_checknumber(L, 1);
	float g = luaL_checknumber(L, 2);
	float b = luaL_checknumber(L, 3);
	Teardown::pGame->pScene->pEnvironment->fogColor = glm::vec3(r, g, b);
	return 0;
}

int CLuaFunctions::EnvFunctions::SetFogParams(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float fogStart = luaL_checknumber(L, 1);
	float fogEnd = luaL_checknumber(L, 2);
	float fogAmount = luaL_checknumber(L, 3);
	float fogExponent = luaL_checknumber(L, 4);

	Teardown::pGame->pScene->pEnvironment->fogParams = glm::vec4(fogStart, fogEnd, fogAmount, fogExponent);

	return 0;
}

int CLuaFunctions::EnvFunctions::SetWetness(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->puddleamount = luaL_checknumber(L, 1);;
	return 0;
}

int CLuaFunctions::EnvFunctions::SetPuddleAmount(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->puddleamount = luaL_checknumber(L, 1);;
	return 0;
}

int CLuaFunctions::EnvFunctions::SetPuddleSize(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->puddlesize = luaL_checknumber(L, 1);;
	return 0;
}

int CLuaFunctions::EnvFunctions::SetRain(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->rain = luaL_checknumber(L, 1);;
	return 0;
}

int CLuaFunctions::EnvFunctions::SetNightLight(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	Teardown::pGame->pScene->pEnvironment->nightlight = luaL_checkint(L, 1);
	return 0;
}
