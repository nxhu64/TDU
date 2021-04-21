#pragma once
#include "Script.h"
#include "tdf_Lua.h"

class CRetInfo
{
public:
	lua_State* L;
	int retCount;
	int maxRet;
};

namespace TDU
{
	namespace CLua
	{
		namespace EntityFunctions
		{
			void CreateBody(CScriptCore* pSC, lua_State*& L, CRetInfo* ret);
			void CreateShape(CScriptCore* pSC, lua_State*& L, CRetInfo* ret);
			void LoadVox(CScriptCore* pSC, lua_State*& L, CRetInfo* ret);
			void InitializeBody(CScriptCore* pSC, lua_State*& L, CRetInfo* ret);
		}

		inline void RegisterCFunctions(CScriptCore_LuaState* pSCLS)
		{
			Teardown::LuaFunctions::RegisterLuaFunction(pSCLS, "CreateBody", EntityFunctions::CreateBody);
			Teardown::LuaFunctions::RegisterLuaFunction(pSCLS, "CreateShape", EntityFunctions::CreateShape);
			Teardown::LuaFunctions::RegisterLuaFunction(pSCLS, "LoadVox", EntityFunctions::LoadVox);
			Teardown::LuaFunctions::RegisterLuaFunction(pSCLS, "InitializeBody", EntityFunctions::InitializeBody);
		}
	}
}