#pragma once

#include "Memory.h"
#include "Signatures.h"
#include "Logger.h"

typedef void	(*tfree)		(void* memBlock);
typedef void* (*tmalloc_base)	(size_t size);

namespace Teardown
{
	namespace MemoryFunctions
	{
		inline tfree Free;
		inline tmalloc_base Alloc;

		inline void GetAddresses()
		{
			Free = (tfree)Memory::dwFindPattern(Signatures::Mem::free_base);
			Alloc = (tmalloc_base)Memory::dwFindPattern(Signatures::Mem::malloc_base);

			WriteLog(ELogType::Address, "free: 0x%p", Free);
			WriteLog(ELogType::Address, "alloc: 0x%p", Alloc);
		}
	}
}