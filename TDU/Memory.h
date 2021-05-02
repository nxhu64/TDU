#pragma once

#include <Windows.h>
#include <Psapi.h>
#include <processthreadsapi.h>
#include <assert.h>

#include "CSignature.h"
#include "Globals.h"
#include "Logger.h"

namespace Memory
{
	inline SIZE_T lReadPtr(SIZE_T Address, UINT Offset)
	{
		if (Address == 0)
			assert(!"ReadPtr address == nullptr");

		if (sizeof(SIZE_T) == 8)
			return Address + (INT)((*(INT*)(Address + Offset) + Offset) + sizeof(INT));

		return (SIZE_T) * (DWORD*)(Address + Offset);
	}

	inline bool bCompare(const BYTE* pData, PBYTE bPattern, const char* cMask)
	{
		for (; *cMask; ++cMask, ++pData, ++bPattern)
		{
			if (*cMask == 'x' && *pData != *bPattern)
				return false;
		}
		return true;
	}

	inline DWORD64 dwFindPattern(CSignature Sig)
	{
		MODULEINFO moduleInfo = { 0 };
		GetModuleInformation(GetCurrentProcess(), g_Module, &moduleInfo, sizeof(MODULEINFO));

		DWORD64 dwBaseAddress = (DWORD64)g_Module;
		DWORD64 dwModuleSize = (DWORD64)moduleInfo.SizeOfImage;

		for (DWORD64 i = 0; i < dwModuleSize; i++)
		{
			if (bCompare((BYTE*)(dwBaseAddress + i), Sig.m_Pattern, Sig.m_Mask))
			{
				if (!Sig.m_DirectRef)
					return (DWORD64)(dwBaseAddress + i);

				return (DWORD64)lReadPtr(dwBaseAddress + i, 1);
			}
		}

		assert(!"dwFindPattern return == nullptr");
		return 0;
	}
}