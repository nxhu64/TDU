#include "TDLua.h"
#include "Signatures.h"
#include "Entities.h"
#include "Script.h"
#include "Memory.h"
#include "Globals.h"
#include "Logger.h"
#include "TeardownFunctions.h"
#include "CLuaFunctions.h"

#include "Lua.hpp"

#include <detours.h>

bool hasFunction(lua_State* L, const char* funcName)
{
	lua_getglobal(L, "_G");
	lua_getfield(L, -1, funcName);
	bool isNil = lua_isnil(L, -1);

	lua_pop(L, 2);
	return !isNil;
}

const char* luaL_tolstring(lua_State* L, int idx, size_t* len)
{
	if (!luaL_callmeta(L, idx, "__tostring")) {
		switch (lua_type(L, idx)) {
		case LUA_TNUMBER:
		case LUA_TSTRING:
			lua_pushvalue(L, idx);
			break;
		case LUA_TBOOLEAN: {
			int val = lua_toboolean(L, idx);
			lua_pushstring(L, val ? "true" : "false");
			break;
		}
		case LUA_TNIL:
			lua_pushliteral(L, "nil");
			break;
		default:
			lua_pushfstring(L, "%s: %p", luaL_typename(L, idx),
				lua_topointer(L, idx));
		}
	}

	return lua_tolstring(L, -1, len);
}

void Teardown::Lua::RunScript(std::string script)
{
	Script* newScript = Teardown::Functions::Constructors::newScript(0);

	lua_State* L = newScript->scriptCore.SC_LuaState.pLSInfo->pLuaState;

	Teardown::Functions::LuaFunctions::RegisterGameFunctions(&newScript->scriptCore);
	
	CLuaFunctions::RegisterCFunctions(&newScript->scriptCore.SC_LuaState);

	if (luaL_loadbuffer(L, script.c_str(), script.length(), "TDU Lua script") || lua_pcall(L, 0, LUA_MULTRET, 0))
	{
		const char* lastError = luaL_tolstring(L, -1, NULL);
		WriteLog(LogType::Error, "Script error: %s", lastError);
		lua_pop(L, 2);
	}

	lua_pop(L, 1);

	newScript->scriptCore.hasTick = hasFunction(L, "tick");
	newScript->scriptCore.hasInit = hasFunction(L, "init");
	newScript->scriptCore.hasUpdate = hasFunction(L, "update");

	/*
		UI Functions are currently not available, as that'd require reversing the HUD class, initializing it, setting the pointer at ScriptCore + 0x1C0 then calling RegisterUIFunctions
		once that's done, uncomment this
		
		newScript->scriptCore.hasDraw = hasFunction(L, "draw");
	*/

	if (newScript->scriptCore.hasTick || newScript->scriptCore.hasInit || newScript->scriptCore.hasUpdate)
		newScript->scriptCore.hasCallbacks = true;

	WriteLog(LogType::Generic, "Ran script (size: %d) | tick: %d | update: %d | init: %d | draw: %d", script.length(), hasFunction(L, "tick"), hasFunction(L, "update"), hasFunction(L, "init"), hasFunction(L, "draw"));
}