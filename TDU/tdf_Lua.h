#pragma once
#include "Script.h"
#include "Memory.h"
#include "Types.h"
#include "Signatures.h"

namespace Teardown
{
	namespace LuaFunctions
	{
		namespace {
			typedef void (*tRegisterGameFunctions)		(CScriptCore* pScriptCore);
			typedef void (*tRegisterLuaFunction)		(CScriptCore_LuaState* pSCLS, small_string* sFunctionName, void* pFunction);
		}

		inline tRegisterGameFunctions RegisterGameFunctions;
		inline tRegisterLuaFunction tdRegisterLuaFunction;

		inline void RegisterLuaFunction(CScriptCore_LuaState* pSCLS, const char* cFunctionName, void* pFunction)
		{
			small_string sFuncName(cFunctionName);
			tdRegisterLuaFunction(pSCLS, &sFuncName, pFunction);
		}

		inline void GetAddresses()
		{
			RegisterGameFunctions = (tRegisterGameFunctions)Memory::dwFindPattern(Signatures::Lua::RegisterGameFunctions);
			tdRegisterLuaFunction = (tRegisterLuaFunction)Memory::dwFindPattern(Signatures::Lua::RegisterLuaFunctionSC);
			WriteLog(ELogType::Address, "RegisterGameFunctions: 0x%p", RegisterGameFunctions);
			WriteLog(ELogType::Address, "RegisterLuaFunction: 0x%p", tdRegisterLuaFunction);
		}
	}
}