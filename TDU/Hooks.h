#pragma once

namespace Hooks
{
	void HookCW();
	void HookUpdate();

	void HookLog();

	namespace InputHooks
	{
		void HookCursor();
		void HookWndProc();
	}

	namespace GLHooks
	{
		void HookSB();
		void HookGlewInit();
	}

	namespace LuaHooks
	{
		void HookLoadBuffer();
		void HookRegisterGameFunctions();
	}

	inline void Init()
	{
		Hooks::HookLog();

		Hooks::InputHooks::HookCursor();

		Hooks::GLHooks::HookSB();
		Hooks::GLHooks::HookGlewInit();

		Hooks::LuaHooks::HookLoadBuffer();
		Hooks::LuaHooks::HookRegisterGameFunctions();
	}
}