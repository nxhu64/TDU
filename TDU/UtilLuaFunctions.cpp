#include "CLuaFunctions.h"
#include <Windows.h>


/*
	DISCLAIMER
	 - Don't use this on any callback functions, it's gonna freeze your game
*/
int CLuaFunctions::UtilFunctions::Wait(lua_State* L)
{
	lua_Number waitTime = luaL_checknumber(L, 1) * 1000;
	Sleep(waitTime);
	return 0;
}