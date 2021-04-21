#pragma once

/*
	To-do: Reverse these classes a bit more
*/

#include "Entities.h"
#include "Lua.hpp"

class CScriptCore_LuaStateInfo
{
public:
	lua_State* m_LuaState;	//0x0000
	char pad_0008[80];		//0x0008
}; //Size: 0x0058

class CScriptCore_LuaState
{
public:
	char pad_0000[56];							//0x0000
	CScriptCore_LuaStateInfo* m_LuaStateInfo;	//0x0038
}; //Size: 0x0040

class CScriptCore
{
public:
	char pad_0008[40];					//0x0008
	CScriptCore_LuaState m_SCLuaState;	//0x0030
	bool m_HasCallbacks;				// run init, tick, update or draw
	bool m_HasInit;						//0x0071
	bool m_HasTick;						//0x0072
	bool m_HasUpdate;					//0x0073
	bool m_HasDraw;						//0x0074
	char pad_0075[2867];				//0x0075

	virtual void Destroy(CScriptCore* pScriptCore, bool freeMemory);
	virtual void RegisterGameFunctions(CScriptCore* pScriptCore);
	virtual void LoadScript();
	virtual void Function3();
	virtual void callInit();
	virtual void callTick();
	virtual void callUpdate();
	virtual void Function7();
	virtual void Function8();
}; //Size: 0xBA8


class Script : public Entity
{
public:
	char* m_ScriptName;			//0x0028
	char pad_0030[8];			//0x0030
	CScriptCore m_ScriptCore;	//0x0038
}; //Size: 0xBE0