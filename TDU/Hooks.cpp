#include "Hooks.h"
#include "Logger.h"
#include "TeardownFunctions.h"

void Hooks::InitHooks()
{
	Hooks::GLHooks::HookGlewInit();
	Hooks::GLHooks::HookSwapBuffers();

	Hooks::PlayerHooks::HookUpdateCamera();
	Hooks::PlayerHooks::HookUpdateCollisions();

	Hooks::LuaHooks::HookLoadBuffer();
	Hooks::LuaHooks::HookRegisterGameFunctions();

	Hooks::InputHooks::HookCursorPos();
	Hooks::MiscHooks::HookLogFunction();
}