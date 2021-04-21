#include "Hooks.h"
#include "Logger.h"
#include "Globals.h"

#include <detours.h>
#include <imgui.h>

typedef bool(*tSetCursorPos)(int X, int Y);
tSetCursorPos	oSetCursorPos;

bool hSetCursorPos(int X, int Y)
{
	if (!g_FreeCursor)
		return oSetCursorPos(X, Y);
	return true;
}

void Hooks::InputHooks::HookCursor()
{
	HMODULE hUSER32 = GetModuleHandle("USER32.dll");
	oSetCursorPos = (tSetCursorPos)GetProcAddress(hUSER32, "SetCursorPos");

	WriteLog(ELogType::Address, "SetCursorPos: 0x%p", SetCursorPos);

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)oSetCursorPos, hSetCursorPos);
	DetourTransactionCommit();
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
WNDPROC	WndProc;

LRESULT	APIENTRY hWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYDOWN:
		if (wParam == VK_INSERT)
			g_FreeCursor = !g_FreeCursor;
		break;
	case WM_KEYUP:
		CallWindowProc(WndProc, hWnd, uMsg, wParam, lParam);
		break;
	}

	if (g_FreeCursor && GetForegroundWindow() == g_Wnd)
	{
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
		return true;
	}

	return CallWindowProc(WndProc, hWnd, uMsg, wParam, lParam);
}

void Hooks::InputHooks::HookWndProc()
{
	WndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtrW(g_Wnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(hWndProc)));
}