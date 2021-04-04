#include "TeardownFunctions.h"
#include "Signatures.h"
#include "Memory.h"
#include "Globals.h"
#include "Logger.h"
#include "Script.h"


typedef void (*tRegisterLuaFunctionSC)		(ScriptCore_LuaState* SCLS, Teardown::small_string* funcName, void* pFunction);
tRegisterLuaFunctionSC RegisterLuaFunctionSC;



void Teardown::Functions::LuaFunctions::RegisterLuaFunction(ScriptCore_LuaState* SCLS, const char* funcName, void* pFunction)
{
	Teardown::small_string ssFuncName(funcName);
	RegisterLuaFunctionSC(SCLS, &ssFuncName, pFunction);
}

void Teardown::Functions::LuaFunctions::GetAddresses()
{
	Teardown::Functions::LuaFunctions::RegisterGameFunctions = (tRegisterGameFunctions)Memory::FindPattern(Signatures::LuaFunctions::RegisterGameFunctions.pattern, Signatures::LuaFunctions::RegisterGameFunctions.mask, Globals::HModule);
	
	DWORD64 dwRegisterLuaFuncSC = Memory::FindPattern(Signatures::LuaFunctions::RegisterLuaFunctionSC.pattern, Signatures::LuaFunctions::RegisterLuaFunctionSC.mask, Globals::HModule);
	RegisterLuaFunctionSC = (tRegisterLuaFunctionSC)Memory::readPtr(dwRegisterLuaFuncSC, 1);

	WriteLog(LogType::Address, "RegisterGameFunctions: 0x%p", Teardown::Functions::LuaFunctions::RegisterGameFunctions);
	WriteLog(LogType::Address, "RegisterLuaFunctionSC: 0x%p", RegisterLuaFunctionSC);
}