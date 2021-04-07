#include "TeardownFunctions.h"

#include "Teardown.h"
#include "Memory.h"
#include "Globals.h"
#include "Signatures.h"
#include "Logger.h"
#include "Editor.h"

typedef Vox* (*tLoadVox)						(Teardown::small_string* path, Teardown::small_string* object, float Scale);
tLoadVox tdLoadVox;

typedef void (*tInitializeBody)					(Body* pBody);
typedef void (*tSetBodyDynamic)					(Body* pBody, bool Dynamic);
tInitializeBody tdInitializeBody;
tSetBodyDynamic tdSetBodyDynamic;

typedef Vox* (*tVoxFunction)					(Vox* pVox);
tVoxFunction GenVoxTexture;
tVoxFunction InitializeVox;

Vox* Teardown::Functions::EntityFunctions::LoadVox(Teardown::small_string* voxPath, const char* object, float Scale)
{
	Teardown::small_string objss(object);

	Vox* newVox = tdLoadVox(voxPath, &objss, Scale);

	if (!newVox)
	{
		WriteLog(LogType::Error, "Couldn't load vox with path %s / object: %s", voxPath->c_str(), object);
		return 0;
	}

	GenVoxTexture(newVox);
	InitializeVox(newVox);

	return newVox;
}

Entity* Teardown::Functions::EntityFunctions::GetEntityById(uint16_t entityId)
{
	Teardown::small_vector<Entity*>* entList = &Teardown::pGame->pScene->entityList2;

	if (!entityId || entityId > entList->size() || entityId <= 0)
		return 0;

	DWORD64 dwEntityPointer = (DWORD64)entList->begin() + (0x8 * entityId);
	return *(Entity**)dwEntityPointer;
}

void Teardown::Functions::EntityFunctions::InitializeBody(Body* pBody)
{
	tdInitializeBody(pBody);
}

void Teardown::Functions::EntityFunctions::SetBodyDynamic(Body* pBody, bool Dynamic)
{
	tdSetBodyDynamic(pBody, Dynamic);
}

void Teardown::Functions::EntityFunctions::GetAddresses()
{
	tdLoadVox = (tLoadVox)Memory::FindPattern(Signatures::EntityFunctions::LoadVox.pattern, Signatures::EntityFunctions::LoadVox.mask, Globals::HModule);

	DWORD64 dwGenVoxTexture = Memory::FindPattern(Signatures::EntityFunctions::GenVoxTexture.pattern, Signatures::EntityFunctions::GenVoxTexture.mask, Globals::HModule);
	GenVoxTexture = (tVoxFunction)Memory::readPtr(dwGenVoxTexture, 1);

	DWORD64 dwInitializeVox = Memory::FindPattern(Signatures::EntityFunctions::InitializeVox.pattern, Signatures::EntityFunctions::InitializeVox.mask, Globals::HModule);
	InitializeVox = (tVoxFunction)Memory::readPtr(dwInitializeVox, 1);

	tdSetBodyDynamic = (tSetBodyDynamic)Memory::FindPattern(Signatures::EntityFunctions::SetBodyDynamic.pattern, Signatures::EntityFunctions::SetBodyDynamic.mask, Globals::HModule);

	DWORD64 dwInitializeBody = Memory::FindPattern(Signatures::EntityFunctions::InitializeBody.pattern, Signatures::EntityFunctions::InitializeBody.mask, Globals::HModule);
	tdInitializeBody = (tInitializeBody)Memory::readPtr(dwInitializeBody, 1);

	WriteLog(LogType::Address, "LoadVox: 0x%p", tdLoadVox);
	WriteLog(LogType::Address, "InitializeVox: 0x%p", GenVoxTexture);
	WriteLog(LogType::Address, "GenVoxTexture: 0x%p", InitializeVox);

	WriteLog(LogType::Address, "SetBodyDynamic: 0x%p", tdSetBodyDynamic);
	WriteLog(LogType::Address, "InitializeBody: 0x%p", tdInitializeBody);
}
