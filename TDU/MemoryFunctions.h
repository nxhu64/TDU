#pragma once
#include "Memory.h"
#include "Signatures.h"
#include "Globals.h"

#include "Logger.h"

typedef void	(*tfree)		(void* memBlock);
typedef void*	(*tmalloc_base)	(size_t size);

namespace Teardown
{
	namespace Mem
	{
		inline tfree Free;
		inline tmalloc_base Alloc;
		inline void GetAddresses()
		{
			DWORD64 dwMalloc = Memory::FindPattern(Signatures::InternalFunctions::malloc_base.pattern, Signatures::InternalFunctions::malloc_base.mask, Globals::HModule);
			Alloc = (tmalloc_base)Memory::readPtr(dwMalloc, 1);

			DWORD64 dwFree = Memory::FindPattern(Signatures::InternalFunctions::j_free.pattern, Signatures::InternalFunctions::j_free.mask, Globals::HModule);
			Free = (tfree)Memory::readPtr(dwFree, 1);

			WriteLog(LogType::Address, "Alloc: 0x%p", Alloc);
			WriteLog(LogType::Address, "Free: 0x%p", Free);
		}
	}
}