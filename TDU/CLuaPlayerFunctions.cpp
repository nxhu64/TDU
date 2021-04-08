#include "CLuaFunctions.h"
#include "Teardown.h"

void CLuaFunctions::PlayerFunctions::SetRecoilSlow(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float recoil = luaL_checknumber(L, 1);
	Teardown::pGame->pPlayer->recoilSlow = recoil;
}

void CLuaFunctions::PlayerFunctions::SetRecoilFast(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float recoil = luaL_checknumber(L, 1);
	Teardown::pGame->pPlayer->recoilFast = recoil;
}

void CLuaFunctions::PlayerFunctions::SetFlashlightColor(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float r = luaL_checknumber(L, 1);
	float g = luaL_checknumber(L, 2);
	float b = luaL_checknumber(L, 3);

	Teardown::pGame->pScene->pFlashlight->Color = glm::vec3(r, g, b);
}

void CLuaFunctions::PlayerFunctions::SetFlashlightIntensity(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float intensity = luaL_checknumber(L, 1);
	Teardown::pGame->pScene->pFlashlight->Intensity = intensity;
}

void CLuaFunctions::PlayerFunctions::SetFlashlightReach(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float reach = luaL_checknumber(L, 1);
	Teardown::pGame->pScene->pFlashlight->Reach = reach;
}

void CLuaFunctions::PlayerFunctions::SetFlashlightFogScale(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float fogscale = luaL_checknumber(L, 1);
	Teardown::pGame->pScene->pFlashlight->fogScale = fogscale;
}

void CLuaFunctions::PlayerFunctions::SetFlashlightFogIter(ScriptCore* pSC, lua_State*& L, retInfo* ret)
{
	float fogiter = luaL_checknumber(L, 1);
	Teardown::pGame->pScene->pFlashlight->fogIter = fogiter;
}