#include "Hooks.h"
#include "Logger.h"
#include "TeardownFunctions.h"

void Hooks::InitHooks()
{
	Teardown::Functions::GetAddresses();

	Hooks::GLHooks::HookGlewInit();
	Hooks::GLHooks::HookSwapBuffers();

	Hooks::PlayerHooks::HookUpdateCamera();
	Hooks::PlayerHooks::HookUpdateCollisions();

	Hooks::InputHooks::HookCursorPos();
	Hooks::MiscHooks::HookLogFunction();
	Hooks::LuaHooks::HookLoadBuffer();
}