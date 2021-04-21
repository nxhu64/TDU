#include "Hooks.h"
#include "Logger.h"
#include "Memory.h"
#include "Signatures.h"
#include "Config.h"
#include "Types.h"

#include <detours.h>
void hLog(small_string* msg)
{
#ifndef PRINT_ERRORS_ONLY
	std::cout << "\033[97;42;1m[Game log]\033[0m " << msg->c_str();
#endif
}

void Hooks::HookLog()
{
	DWORD64 Log = Memory::dwFindPattern(Signatures::Log);
	WriteLog(ELogType::Address, "Log: 0x%p", Log);

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)Log, hLog);
	DetourTransactionCommit();
}