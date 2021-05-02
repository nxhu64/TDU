#pragma once
#include "Memory.h"
#include "Types.h"
#include "Signatures.h"
#include "Entities.h"
#include "Game.h"

namespace Teardown
{
	namespace EntityFunctions
	{
		namespace {
			typedef Vox* (*tLoadVox)						(small_string* ssPath, small_string* ssObject, float fScale);

			typedef void (*tInitializeBody)					(Body* pBody);
			typedef void (*tSetBodyDynamic)					(Body* pBody, bool bDynamic);

			typedef Vox* (*tVoxFunction)					(Vox* pVox);
		}

		inline tLoadVox LoadVox;

		inline tInitializeBody InitializeBody;
		inline tSetBodyDynamic SetBodyDynamic;

		inline tVoxFunction GenVoxTexture;
		inline tVoxFunction InitializeVox;

		inline Entity* GetEntityById(uint16_t iEntityId)
		{
			if (!iEntityId || iEntityId > g_Game->m_Scene->m_Entities.size() || iEntityId <= 0)
				return 0;

			DWORD64 dwEntityPointer = (DWORD64)g_Game->m_Scene->m_Entities.begin() + (0x8 * iEntityId);
			return *(Entity**)dwEntityPointer;
		}

		inline void GetAddresses()
		{
			LoadVox = (tLoadVox)Memory::dwFindPattern(Signatures::EntityFunctions::LoadVox);

			InitializeBody = (tInitializeBody)Memory::dwFindPattern(Signatures::EntityFunctions::InitializeBody);
			SetBodyDynamic = (tSetBodyDynamic)Memory::dwFindPattern(Signatures::EntityFunctions::SetBodyDynamic);

			GenVoxTexture = (tVoxFunction)Memory::dwFindPattern(Signatures::EntityFunctions::GenVoxTexture);
			InitializeVox = (tVoxFunction)Memory::dwFindPattern(Signatures::EntityFunctions::InitializeVox);

			WriteLog(ELogType::Address, "LoadVox: 0x%p", LoadVox);
			WriteLog(ELogType::Address, "InitializeBody: 0x%p", InitializeBody);
			WriteLog(ELogType::Address, "SetBodyDynamic: 0x%p", SetBodyDynamic);
			WriteLog(ELogType::Address, "GenVoxTexture: 0x%p", GenVoxTexture);
			WriteLog(ELogType::Address, "InitializeVox: 0x%p", InitializeVox);
		}
	}
}