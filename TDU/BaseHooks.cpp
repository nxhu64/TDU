#include "Hooks.h"
#include "Game.h"
#include "Logger.h"
#include "Globals.h"
#include "Signatures.h"
#include "Memory.h"
#include "Teardown.h"

#include <detours.h>
#include <mutex>

/*
	CreateWindow hook
	- Used to rename the window
	- Used to hook WndProc automatically when changing resolution (Window is created again everytime display settings are changed)
	- Used to initialize everything, since it's called after SteamStub is done unpacking the game's exe (Prior to that, sigscans will fail)
	- Used to hook Main again to re-obtain Game's pointer
	- It was used for was manually handling the game's built in ImGui context, no longer doing that though
*/

std::once_flag hasHookedFunctions;

typedef HWND(*tCreateWindowExA)	(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
tCreateWindowExA oCreateWindowExA;

HWND hCreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
	std::call_once(hasHookedFunctions, Hooks::InitHooks);

	if (!lstrcmp(lpWindowName, "Teardown"))
	{
		Hooks::BaseHooks::HookMain();
		char windowName[100] = "TDU ";
		strcat(windowName, Globals::version.c_str());

		Globals::HWnd = oCreateWindowExA(dwExStyle, lpClassName, windowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
		Hooks::InputHooks::HookWndProc();

		return Globals::HWnd;
	}

	return oCreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

void Hooks::BaseHooks::HookCW()
{
	HMODULE USER32 = GetModuleHandle("USER32.dll");
	oCreateWindowExA = (tCreateWindowExA)GetProcAddress(USER32, "CreateWindowExA");

	WriteLog(LogType::Address, "CreateWindowExA: 0x%p | hook: 0x%p", oCreateWindowExA, hCreateWindowExA);

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)oCreateWindowExA, hCreateWindowExA);
	DetourTransactionCommit();
}

/*
	Main hook
	- Used to get pGame pointer dynamically (to make it more update friendly)
	- Works for automatically loading levels, or doing anything the moment the game starts, like skipping the splash screen
*/

typedef void	(*tMain)			(Game* game, void* a2);
tMain Main;

void hMain(Game* pGame, void* pCamSystem)
{
	Teardown::pGame = pGame;
	Main(pGame, pCamSystem);

	#ifdef _DEBUG
		Teardown::pGame->StateTransition = Teardown::gameState::menu;
	#endif

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)Main, hMain);
	DetourTransactionCommit();
}

void Hooks::BaseHooks::HookMain()
{
	DWORD64 dwMain = Memory::FindPattern(Signatures::Main.pattern, Signatures::Main.mask, Globals::HModule);
	Main = (tMain)Memory::readPtr(dwMain, 1);

	WriteLog(LogType::Address, "Main: 0x%p | hook: 0x%p", Main, hMain);

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)Main, hMain);
	DetourTransactionCommit();
}