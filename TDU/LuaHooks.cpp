#include "Hooks.h"
#include "Lua.hpp"
#include "tdf_Lua.h"
#include "CLuaFunctions.h"

#include "Memory.h"
#include "Signatures.h"


#include <Windows.h>
#include <detours.h>

typedef int	(*tluaL_loadbuffer)				(lua_State* L, const char* buff, size_t size, const char* name);
tluaL_loadbuffer oluaL_loadbuffer;

int hluaL_loadbuffer(lua_State* L, const char* buff, size_t size, const char* name)
{
	return oluaL_loadbuffer(L, buff, size, name);
}

void Hooks::LuaHooks::HookLoadBuffer()
{
	oluaL_loadbuffer = (tluaL_loadbuffer)Memory::dwFindPattern(Signatures::Lua::luaL_loadbuffer);
	WriteLog(ELogType::Address, "luaL_loadbuffer: 0x%p", oluaL_loadbuffer);

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)oluaL_loadbuffer, hluaL_loadbuffer);
	DetourTransactionCommit();
}

void hRegisterGameFunctions(CScriptCore* pSC)
{
	Teardown::LuaFunctions::RegisterGameFunctions(pSC);
	TDU::CLua::RegisterCFunctions(&pSC->m_SCLuaState);
}

void Hooks::LuaHooks::HookRegisterGameFunctions()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)Teardown::LuaFunctions::RegisterGameFunctions, hRegisterGameFunctions);
	DetourTransactionCommit();
}