#include "CLuaFunctions.h"
#include "Config.h"

void CLuaFunctions::RegisterCFunctions(lua_State* L)
{
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

	lua_pushcfunction(L, CLuaFunctions::EntityFunctions::CreateBody);
	lua_setglobal(L, "CreateBody");

	lua_pushcfunction(L, CLuaFunctions::EntityFunctions::CreateShape);
	lua_setglobal(L, "CreateShape");

	lua_pushcfunction(L, CLuaFunctions::EntityFunctions::LoadVox);
	lua_setglobal(L, "LoadVox");

	lua_pushcfunction(L, CLuaFunctions::EntityFunctions::InitializeBody);
	lua_setglobal(L, "InitializeBody");

	lua_pushcfunction(L, CLuaFunctions::UtilFunctions::Wait);
	lua_setglobal(L, "Wait");
}