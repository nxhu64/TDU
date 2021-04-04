#include "CLuaFunctions.h"
#include "TeardownFunctions.h"
#include <Windows.h>

int CLuaFunctions::EntityFunctions::CreateBody(lua_State* L)
{
	int argCount = lua_gettop(L);
	DWORD64 parent = 0;

	bool isDynamic = false;

	if (argCount >= 1)
	{
		int parentId = luaL_checknumber(L, 1);
		if (parentId > 0)
			parent = (DWORD64)Teardown::Functions::EntityFunctions::GetEntityById(parentId);
	
		if (argCount >= 3)
			isDynamic = lua_toboolean(L, 2);
	}

	Body* newBody = Teardown::Functions::Constructors::newBody((Entity*)parent);
	newBody->Dynamic = isDynamic;

	lua_pushnumber(L, newBody->Id);
	return 1;
}

int CLuaFunctions::EntityFunctions::CreateShape(lua_State* L)
{
	int argCount = lua_gettop(L);
	Entity* parent = 0;
	if (argCount >= 1)
	{
		int parentId = luaL_checknumber(L, 1);
		parent = Teardown::Functions::EntityFunctions::GetEntityById(parentId);
	}

	Shape* newShape = Teardown::Functions::Constructors::newShape(parent);

	lua_pushnumber(L, newShape->Id);
	return 1;
}

int CLuaFunctions::EntityFunctions::LoadVox(lua_State* L)
{
	int argCount = lua_gettop(L);

	int shapeId = luaL_checknumber(L, 1);

	const char* voxPath = luaL_checkstring(L, 2);
	const char* objName = NULL;

	Shape* pShape = (Shape*)Teardown::Functions::EntityFunctions::GetEntityById(shapeId);

	if (!pShape || pShape->Type != entityType::Shape)
		return 0;

	float scale = 1.f;

	if (argCount >= 3)
		scale = luaL_checknumber(L, 3);

	if (argCount >= 4)
		objName = luaL_checkstring(L, 4);

	Teardown::small_string* finalVoxPath = Teardown::Functions::Utils::GetFilePath(voxPath);

	Vox* newVox = Teardown::Functions::EntityFunctions::LoadVox(finalVoxPath, objName, scale);

	if (newVox)
		pShape->pVox = newVox;
	else
	{
		lua_pushliteral(L, "Unable to load vox file");
		lua_error(L);
	}

	return 0;
}

int CLuaFunctions::EntityFunctions::InitializeBody(lua_State* L)
{
	int argCount = lua_gettop(L);

	int shapeId = luaL_checknumber(L, 1);

	Body* pBody= (Body*)Teardown::Functions::EntityFunctions::GetEntityById(shapeId);

	if (!pBody || pBody->Type != entityType::Body)
		return 0;

	bool Dynamic = false;
	if (argCount >= 2)
		Dynamic = lua_toboolean(L, 2);

	Teardown::Functions::EntityFunctions::SetBodyDynamic(pBody, Dynamic);
	Teardown::Functions::EntityFunctions::InitializeBody(pBody);
	
	return 0;
}