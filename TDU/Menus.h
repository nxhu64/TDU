#pragma once
#include "Globals.h"

namespace TDU
{
	namespace Menus
	{
		void DrawScriptEditor();

		inline void DrawMenus()
		{
			if (g_FreeCursor)
			{
				DrawScriptEditor();
			}
		}
	}
}