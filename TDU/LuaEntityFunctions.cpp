#include "CLuaFunctions.h"

#include "Entities.h"
#include "tdf_Entities.h"
#include "tdf_Constructors.h"
#include "tdf_Utils.h"

void TDU::CLua::EntityFunctions::CreateBody(CScriptCore* pSC, lua_State*& L, CRetInfo* pRet)
{
	int iTop = lua_gettop(L);
	Entity* pParent = 0;

	if (iTop >= 1)
	{
		int iParentId = lua_tointeger(L, 1);
		if (iParentId > 0)
			pParent = Teardown::EntityFunctions::GetEntityById(iParentId);
	}

	Body* pBody = Teardown::Constructors::CreateBody(pParent);

	lua_pop(L, iTop);

	lua_pushinteger(L, pBody->m_Id);
	pRet->retCount = 1;
}

void TDU::CLua::EntityFunctions::CreateShape(CScriptCore* pSC, lua_State*& L, CRetInfo* pRet)
{
	int iTop = lua_gettop(L);
	Entity* pParent = 0;

	if (iTop >= 1)
	{
		int iParentId = lua_tointeger(L, 1);
		if (iParentId > 0)
			pParent = Teardown::EntityFunctions::GetEntityById(iParentId);
	}

	Shape* pShape = Teardown::Constructors::CreateShape(pParent);

	lua_pop(L, iTop);

	lua_pushinteger(L, pShape->m_Id);
	pRet->retCount = 1;
}

void TDU::CLua::EntityFunctions::LoadVox(CScriptCore* pSC, lua_State*& L, CRetInfo* pRet)
{
	int iTop = lua_gettop(L);
	int iShape = luaL_checknumber(L, 1);

	const char* cVoxPath = luaL_checkstring(L, 2);
	const char* cObjName = NULL;

	Shape* pShape = (Shape*)Teardown::EntityFunctions::GetEntityById(iShape);

	if (!pShape || pShape->m_Type != EEntityType::Shape)
	{
		lua_pushliteral(L, "invalid handle");
		lua_error(L);
		return;
	}

	float fScale = 1.f;

	if (iTop >= 3)
		fScale = luaL_checknumber(L, 3);

	if (iTop >= 4)
		cObjName = luaL_checkstring(L, 4);

	const char* cRealPath = Teardown::UtilFunctions::GetFilePathLua(pSC, cVoxPath);
	cRealPath = Teardown::UtilFunctions::GetFilePath(cRealPath);

	small_string ssRealPath(cRealPath);
	small_string ssObjName(cObjName);

	Vox* pVox = Teardown::EntityFunctions::LoadVox(&ssRealPath, &ssObjName, fScale);
	Teardown::EntityFunctions::GenVoxTexture(pVox);
	Teardown::EntityFunctions::InitializeVox(pVox);

	if (pVox)
		pShape->m_Vox = pVox;
	else
	{
		lua_pushliteral(L, "unable to load vox file");
		lua_error(L);
		return;
	}

	lua_pop(L, iTop);
}

void TDU::CLua::EntityFunctions::InitializeBody(CScriptCore* pSC, lua_State*& L, CRetInfo* pRet)
{
	int iTop = lua_gettop(L);

	int iShapeId = luaL_checknumber(L, 1);

	Body* pBody = (Body*)Teardown::EntityFunctions::GetEntityById(iShapeId);

	if (!pBody || pBody->m_Type != EEntityType::Body)
		return;

	bool bDynamic = false;
	if (iTop >= 2)
		bDynamic = lua_toboolean(L, 2);

	Teardown::EntityFunctions::SetBodyDynamic(pBody, bDynamic);
	Teardown::EntityFunctions::InitializeBody(pBody);

	lua_pop(L, iTop);
}