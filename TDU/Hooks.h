#pragma once

namespace Hooks
{
	namespace BaseHooks
	{
		void HookCW();
		void HookMain();
	}
	
	namespace MiscHooks
	{
		void HookLogFunction();
	}

	namespace InputHooks
	{
		void HookWndProc();
		void HookCursorPos();
	}

	namespace LuaHooks
	{
		void HookLoadBuffer();
		void HookRegisterGameFunctions();
	}

	namespace GLHooks
	{
		void HookGlewInit();
		void HookSwapBuffers();
	}

	namespace PlayerHooks
	{
		inline bool doUpdateCamera = true;
		inline bool doUpdateCollisions = true;
		void HookUpdateCamera();
		void HookUpdateCollisions();
	}

	void InitHooks();
}