#include "Hooks.h"
#include "Globals.h"
#include "Logger.h"
#include "Loader.h"
#include "tdf_Memory.h"

#include <detours.h>
#include <mutex>

/*
	CreateWindow hook
	- Used to hook WndProc automatically when changing resolution (Window is created again everytime display settings are changed)
	- Used to initialize everything, since it's called after SteamStub is done unpacking the game's exe (Prior to that, sigscans and other stuff will fail)
	- Used to rename the window
	- Used to get the game's window handle
*/

typedef HWND(*tCreateWindowExA)	(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
tCreateWindowExA oCreateWindowExA;

void OnFirstCWCall()
{
	TDU::Loader::InitUnpacked();
}

std::once_flag fFirstCall;

HWND hCreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
	std::call_once(fFirstCall, OnFirstCWCall);

	if (!lstrcmp(lpWindowName, "Teardown"))
	{
		size_t cBuffSize = strlen(g_Version) + 6;
		char* windowName = (char*)Teardown::MemoryFunctions::Alloc(cBuffSize);
		memcpy(windowName, "TDU - ", 6);
		memcpy(windowName + 6, g_Version, strlen(g_Version));
		windowName[cBuffSize] = 0;

		g_Wnd = oCreateWindowExA(dwExStyle, lpClassName, windowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
		
		Hooks::InputHooks::HookWndProc();
		Hooks::HookUpdate();


		return g_Wnd;
	}

	return oCreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

void Hooks::HookCW()
{
	HMODULE USER32 = GetModuleHandle("USER32.dll");
	oCreateWindowExA = (tCreateWindowExA)GetProcAddress(USER32, "CreateWindowExA");

	WriteLog(ELogType::Address, "CreateWindowExA: 0x%p", oCreateWindowExA);

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)oCreateWindowExA, hCreateWindowExA);
	DetourTransactionCommit();
}
