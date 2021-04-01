#include "TeardownFunctions.h"
#include "Types.h"
#include "Signatures.h"
#include "Memory.h"
#include "Logger.h"
#include "Globals.h"
#include "Teardown.h"

/*
	W.I.P Path references
	 - Issues:
			LEVEL causes an access violation
			MOD points to the level's path, not the mod that contains the script
*/

typedef Teardown::small_string* (*tGetFilePath)		(void* pFileManager, Teardown::small_string* unk, Teardown::small_string* path, Teardown::small_string* fileType);
tGetFilePath tdGetFilePath;

typedef Teardown::small_string* (*tGetFilePathLua)	(lua_State* L, Teardown::small_string* ssPath, const char* ccPath);
tGetFilePathLua tdGetFilePathLua;

Teardown::small_string* Teardown::Functions::Utils::GetFilePath(Teardown::small_string ssPath)
{
	Teardown::small_string retStr;

	tdGetFilePath(Teardown::pGame->pDataManager, &retStr, &ssPath, 0);
	return &retStr;
}


Teardown::small_string* Teardown::Functions::Utils::GetFilePathLua(lua_State* L, const char* ccPath)
{
	Teardown::small_string ret;
	tdGetFilePathLua(L, &ret, ccPath);
	return &ret;
}

void Teardown::Functions::Utils::GetAddresses()
{
	DWORD64 dwGetFilePath = Memory::FindPattern(Signatures::GetFilePath.pattern, Signatures::GetFilePath.mask, Globals::HModule);
	tdGetFilePath = (tGetFilePath)Memory::readPtr(dwGetFilePath, 1);

	DWORD64 dwGetFilePathLua = Memory::FindPattern(Signatures::GetFilePathLua.pattern, Signatures::GetFilePathLua.mask, Globals::HModule);
	tdGetFilePathLua = (tGetFilePathLua)Memory::readPtr(dwGetFilePathLua, 1);

	WriteLog(LogType::Address, "GetFilePath: 0x%p", tdGetFilePath);
	WriteLog(LogType::Address, "GetFilePathLua: 0x%p", tdGetFilePathLua);
}