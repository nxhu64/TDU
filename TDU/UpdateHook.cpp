#include "Hooks.h"
#include "Globals.h"
#include "Logger.h"
#include "Memory.h"
#include "Signatures.h"
#include "Game.h"
#include "Logger.h"
#include "Loader.h"

#include "tdf_Constructors.h"
#include "tdf_Memory.h"
#include "tdf_Lua.h"

#include <detours.h>
#include <mutex>

std::once_flag hasGamePtr;

typedef void (*tUpdate)				(CGame* Game, void* a2);
tUpdate Update;

void hUpdate(CGame* pGame, void* a2)
{
	g_Game = pGame;
	g_Player = pGame->m_Player;

	Update(pGame, a2);

#ifdef _DEBUG
	pGame->m_TargetState = eGameState::Menu;
#endif

	WriteLog(ELogType::Address, "Game: 0x%p", g_Game);
	WriteLog(ELogType::Address, "Player: 0x%p", g_Player);

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)Update, hUpdate);
	DetourTransactionCommit();
}

void Hooks::HookUpdate()
{
	Update = (tUpdate)Memory::dwFindPattern(Signatures::Update);

	WriteLog(ELogType::Address, "Update: 0x%p", Update, hUpdate);

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)Update, hUpdate);
	DetourTransactionCommit();
}