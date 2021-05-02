#pragma once
#include "Types.h"
#include "Script.h"
#include "Game.h"

#include "Memory.h"
#include "Signatures.h"

namespace Teardown
{
	namespace UtilFunctions
	{
		namespace {
			typedef small_string* (*tGetFilePath)			(void* pFileManager, small_string* sRet, small_string* ssPath, small_string* sFileType);
			typedef small_string* (*tGetFilePathLua)		(void* pSC, small_string* sRet, small_string* ssPath);

			typedef void (*tUpdateEnvironment)						(void* pEnvironment);
		}

		inline tGetFilePath tdGetFilePath;
		inline tGetFilePathLua tdGetFilePathLua;

		inline tUpdateEnvironment tdUpdateEnvironment;

		inline void UpdateEnvironment()
		{
			tdUpdateEnvironment(&g_Game->m_Scene->m_Environment);
		}

		inline const char* GetFilePath(const char* ccPath)
		{
			small_string ssRet(ccPath);
			small_string ssType;
			small_string ssPath(ccPath);

			tdGetFilePath(g_Game->m_PathMgr, &ssRet, &ssPath, &ssType);
			return ssRet.c_str();
		}

		inline const char* GetFilePathLua(CScriptCore* pSC, const char* cPath)
		{
			small_string ssRet(cPath);
			small_string ssPath(cPath);

			tdGetFilePathLua(pSC, &ssRet, &ssPath);
			return ssRet.c_str();
		}

		inline void GetAddresses()
		{
			tdGetFilePath = (tGetFilePath)Memory::dwFindPattern(Signatures::GetFilePath);
			tdGetFilePathLua = (tGetFilePathLua)Memory::dwFindPattern(Signatures::GetFilePathLua);
			tdUpdateEnvironment = (tUpdateEnvironment)Memory::dwFindPattern(Signatures::UpdateEnvironment);
		}
	}
}