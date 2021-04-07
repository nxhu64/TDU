#include "Hooks.h"
#include "Signatures.h"
#include "Logger.h"
#include "Memory.h"
#include "Player.h"
#include "Globals.h"
#include "Cheats.h"

#include <detours.h>

/*
	UpdateCamera hook
	- Used to call the noclip's code
	- Preventing calls to the original function because they interfere with the noclip's camera positions
*/
typedef void	(*tUpdateCamera)				(Player* Ply, void* unk1, void* unk2, void* unk3);
tUpdateCamera UpdateCamera;

void hUpdateCamera(Player* Ply, void* unk1, void* unk2, void* unk3)
{
	Cheats::Noclip::Run();
	if (Hooks::PlayerHooks::doUpdateCamera)
		UpdateCamera(Ply, unk1, unk2, unk3);
}

void Hooks::PlayerHooks::HookUpdateCamera()
{
	DWORD64 dwUpdateCamera = Memory::FindPattern(Signatures::PlayerFunctions::UpdateCamera.pattern, Signatures::PlayerFunctions::UpdateCamera.mask, Globals::HModule);
	UpdateCamera = (tUpdateCamera)Memory::readPtr(dwUpdateCamera, 1);
	WriteLog(LogType::Address, "UpdateCamera: 0x%p | hook: 0x%p", UpdateCamera, hUpdateCamera);

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)UpdateCamera, hUpdateCamera);
	DetourTransactionCommit();
}