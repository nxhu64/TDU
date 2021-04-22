#pragma once
#include "Config.h"
#include "Globals.h"
#include "Logger.h"

#include "Hooks.h"

#include "tdf_Constructors.h"
#include "tdf_Lua.h"
#include "tdf_Memory.h"
#include "tdf_Entities.h"
#include "tdf_Utils.h"

namespace TDU
{
	namespace Loader
	{
		inline void Init()
		{
			if (c_ConEnabled)
			{
				// allocate console for logging
				AllocConsole();
				freopen("CONOUT$", "w", stdout);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

				// enable escape sequences
				DWORD dwMode = 0;
				GetConsoleMode(hConsole, &dwMode);
				dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
				SetConsoleMode(hConsole, dwMode);
			}

			#ifndef _DEBUG
				strcat(g_Version, " release build");
			#else
				strcat(g_Version, " debug build");
			#endif

			WriteLog(ELogType::Special, " _________  ______   __  __      ");
			WriteLog(ELogType::Special, "/________/\\/_____/\\ /_/\\/_/\\     ");
			WriteLog(ELogType::Special, "\\__.::.__\\/\\:::_ \\ \\\\:\\ \\:\\ \\    ");
			WriteLog(ELogType::Special, "   \\::\\ \\   \\:\\ \\ \\ \\\\:\\ \\:\\ \\   ");
			WriteLog(ELogType::Special, "    \\::\\ \\   \\:\\ \\ \\ \\\\:\\ \\:\\ \\  ");
			WriteLog(ELogType::Special, "     \\::\\ \\   \\:\\/.:| |\\:\\_\\:\\ \\ ");
			WriteLog(ELogType::Special, "      \\__\\/    \\____/_/ \\_____\\/ ");
			WriteLog(ELogType::Special, "Teardown unleashed - %s", g_Version);
			WriteLog(ELogType::Special, "Shout-out to Xorberax - SK83RJOSH - Knebb\n");

			g_Module = GetModuleHandle(NULL);

			Hooks::HookCW();
		}


		/*
			Called after CreateWindow call, when this is called it means SteamStub has loaded the exe into memory
			This is a placeholder until i reverse SteamStub
		*/
		inline void InitUnpacked()
		{
			Teardown::LuaFunctions::GetAddresses();
			Teardown::MemoryFunctions::GetAddresses();
			Teardown::Constructors::GetAddresses();
			Teardown::EntityFunctions::GetAddresses();
			Teardown::UtilFunctions::GetAddresses();

			Hooks::Init();
		}
	}
}