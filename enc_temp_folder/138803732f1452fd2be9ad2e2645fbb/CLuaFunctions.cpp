#include "CLuaFunctions.h"
#include "Config.h"
#include "TeardownFunctions.h"

int testFunction(ScriptCore* pSC, lua_State*& L, lua_State*& L2)
{
	lua_pushinteger(L, 1337);
	lua_pushinteger(L2, 1337);
	return 2;
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

	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "CreateBody", &CLuaFunctions::EntityFunctions::CreateBody);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "CreateShape", &CLuaFunctions::EntityFunctions::CreateShape);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "LoadVox", &CLuaFunctions::EntityFunctions::LoadVox);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "InitializeBody", &CLuaFunctions::EntityFunctions::InitializeBody);
	Teardown::Functions::LuaFunctions::RegisterLuaFunction(pSCLS, "TestFunc", testFunction);

	//lua_pushcfunction(L, CLuaFunctions::EntityFunctions::CreateBody);
	//lua_setglobal(L, "CreateBody");

	//lua_pushcfunction(L, CLuaFunctions::EntityFunctions::CreateShape);
	//lua_setglobal(L, "CreateShape");

	//lua_pushcfunction(L, CLuaFunctions::EntityFunctions::LoadVox);
	//lua_setglobal(L, "LoadVox");

	//lua_pushcfunction(L, CLuaFunctions::EntityFunctions::InitializeBody);
	//lua_setglobal(L, "InitializeBody");

	//lua_pushcfunction(L, CLuaFunctions::UtilFunctions::Wait);
	//lua_setglobal(L, "Wait");
}