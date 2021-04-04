#pragma once
#include "Lua.hpp"
#include "Script.h"

/*
	This file should eventually have a different name, or LuaFunctions.h/cpp should have a different name, cause it's gonna cause some confusion
*/

class retInfo
{
public:
	lua_State* pL;
	int retcount;
	// Unk size
};

namespace CLuaFunctions
{
	namespace EntityFunctions
	{
		int CreateBody(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int CreateShape(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int LoadVox(ScriptCore* pSC, lua_State*& L, retInfo* ret);
		int InitializeBody(ScriptCore* pSC, lua_State*& L, retInfo* ret);
	}

	void RegisterCFunctions(ScriptCore_LuaState* pSCLS);
}