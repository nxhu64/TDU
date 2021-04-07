#pragma once
#include <Windows.h>

class Signature
{
public:
	Signature(const char* nPattern, const char* nMask)
	{
		pattern = (PBYTE)nPattern; mask = nMask;
	}
	PBYTE pattern;
	const char* mask;
};

/*
	All signatures are stored here, if you implement any new functions / hooks / signatures, i suggest you keep the signatures here, so that it's easier to update whenever Teardown updates
	"direct reference" means the sig does not point to the function itself, but to a pointer of the function (a place where it's being called)
	In order to get that address, you'll have to call Memory::readPtr(sigAddress, 1), or just dereference it, whichever you prefer

	The ones that are uncommented are because it'd make a really long comment or something, if you still wanna find them, ask
*/

namespace Signatures
{

	// Game's Main function, which is called before the SwapBuffers call inside Teardown's init function, which is called on WinMain 
	inline Signature Main("\xE8\x00\x00\x00\x00\x48\x8D\x4D\xA7\xE8\x00\x00\x00\x00\xEB\x1D", "x????xxxxx????xx"); // direct reference
		
	// Log function, can be found by xref-ing "Starting up in resolution:" then getting the function 5 calls below
	inline Signature Log("\x80\x79\x0F\x00\x74\x03\x48\x8B\x09\x48\x8B\xD1\x48\x8D\x0D\x00\x00\x00\x00", "xxxxxxxxxxxxxxx????");

	// Right below the wglMakeCurrent call on the function that creates the window, xref "Failed to call wglMakeCurrent for OpenGL context 3.3" for context
	inline Signature glewInit("\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x85\xC0\x75\x09", "xxxxx????xxxx");

	inline Signature GetFilePath("\xE8\x00\x00\x00\x00\x90\x48\x8B\x4B\x78", "x????xxxxx"); // direct reference
	inline Signature GetFilePathLua("\xE8\x00\x00\x00\x00\x90\x44\x88\x7C\x24\x00", "x????xxxxx?"); // direct reference

	inline Signature UpdateEnvironment("\xE8\x00\x00\x00\x00\x48\x8B\x87\x00\x00\x00\x00\x8B\x10", "x????xxx????xx"); // direct reference

	namespace LuaFunctions {
		// You can find it by searching any functions that are not from the UI lib (i.e. SetTag, or IsBodyBroken)
		inline Signature RegisterGameFunctions("\x40\x55\x48\x8D\xAC\x24\x00\x00\x00\x00\x48\x81\xEC\x00\x00\x00\x00\x48\xC7\x85\x00\x00\x00\x00\x00\x00\x00\x00", "xxxxxx????xxx????xxx????????");

		// You can find called a whole lot inside RegisterGameFunctions
		inline Signature RegisterLuaFunctionSC("\xE8\x00\x00\x00\x00\x90\x48\x8D\x4D\x60\xE8\x00\x00\x00\x00\x48\x8B\x9C\x24\x00\x00\x00\x00", "x????xxxxxx????xxxx????"); // direct reference

		inline Signature luaL_loadbuffer("\xE8\x00\x00\x00\x00\x85\xC0\x75\x07\xB8\x00\x00\x00\x00\xEB\x57", "x????xxxxx????xx"); // direct reference
	}

	namespace PlayerFunctions {
		// Found by seeing what writes to the camera's position pointer on CE
		inline Signature UpdateCamera("\xE8\x00\x00\x00\x00\x48\x8B\x4B\x70\xF3\x0F\x10\x8B\x00\x00\x00\x00", "x????xxxxxxxx????"); // direct reference

		// Found by seeing what writes to the Player->Position.Y position
		inline Signature UpdatePlayerCollisions("\xE8\x00\x00\x00\x00\x41\x8B\xF4\x48\x8B\x07\x48\x8B\x88\x00\x00\x00\x00\x83\x39\x00\x7E\x31", "x????xxxxxxxxx????xxxxx"); // direct reference

		// Found by seeing what writes to Player->pInteractableShape
		inline Signature InteractionHandler("\xE8\x00\x00\x00\x00\x41\x0F\x28\xD4\x48\x8B\xD6\x48\x8B\xCF\xE8\x00\x00\x00\x00\x41\x0F\x28\xD4", "x????xxxxxxxxxxx????xxxx"); // direct reference
	}

	namespace EntityFunctions
	{
		/*
			Vox functions
		*/
		// Found by xref-ing "vox/bomb.vox", it's 2 calls after that
		inline Signature LoadVox("\x4C\x8B\xDC\x57\x48\x81\xEC\x00\x00\x00\x00\x48\xC7\x44\x24\x00\x00\x00\x00\x00\x49\x89\x5B\x08", "xxxxxxx????xxxx?????xxxx");

		// Found by xref-ing "game.tool.pipebomb.damage" and going 3 calls before that
		inline Signature GenVoxTexture("\xE8\x00\x00\x00\x00\xFF\xC3\x48\x8D\x76\x08\x3B\x1F", "x????xxxxxxxx"); // direct reference

		// Right below GenVoxTexture call
		inline Signature InitializeVox("\xE8\x00\x00\x00\x00\x41\xFF\xC7\x48\x83\xC7\x1C", "x????xxxxxxx"); // direct reference

		/*
			Body functions
		*/

		inline Signature SetBodyDynamic("\x88\x91\x00\x00\x00\x00\x4C\x8B\xC1", "xx????xxx");

		inline Signature InitializeBody("\xE8\x00\x00\x00\x00\x41\x80\xBF\x00\x00\x00\x00\x00", "x????xxx?????"); // direct reference
	}

	// There's a couple ways to find these, easiest way to find them is to look in the function that parses the level's xml and spawns every entity in it
	namespace ClassConstructors {

		inline Signature Body("\xE8\x00\x00\x00\x00\xEB\x03\x49\x8B\xC5", "x????xxxxx"); // direct reference

		inline Signature Shape("\xE8\x00\x00\x00\x00\x48\x8B\xF8\x48\x89\x7D\x88", "x????xxxxxxx"); // direct reference

		inline Signature Light("\xE8\x00\x00\x00\x00\x48\x8B\xF8\x48\x89\x45\x88\x48\x8D\x8D\x00\x00\x00\x00", "x????xxxxxxxxxx????"); // direct reference

		inline Signature Location("\x40\x53\x48\x83\xEC\x20\x4C\x8B\xC2\x48\x8B\xD9\xBA\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8D\x05\x00\x00\x00\x00\x48\x89\x03\x33\xC0\x48\x89\x43\x28\x48\x89\x43\x30\x48\x89\x43\x38\x48\x8B\xC3", "xxxxxxxxxxxxx????x????xxx????xxxxxxxxxxxxxxxxxxxx"); // direct reference

		inline Signature Water("\xE8\x00\x00\x00\x00\x48\x8B\xF8\x48\x89\x45\x88\x48\x8B\x85\x00\x00\x00\x00\x0F\x10\x00\x0F\x11\x47\x28\xF2\x0F\x10\x48\x00\xF2\x0F\x11\x4F\x00\x8B\x40\x18\x89\x47\x40\x48\x8D\x15\x00\x00\x00\x00", "x????xxxxxxxxxx????xxxxxxxxxxx?xxxx?xxxxxxxxx????"); // direct reference

		inline Signature Enemy("\x40\x53\x48\x83\xEC\x20\x4C\x8B\xC2\x48\x8B\xD9\xBA\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x45\x33\xC0", "xxxxxxxxxxxxx????x????xxx");

		inline Signature Joint("\xE8\x00\x00\x00\x00\x48\x8B\xD8\x45\x33\xED", "x????xxxxxx"); // direct reference

		inline Signature Vehicle("\xE9\x00\x00\x00\x00\xB9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x6D", "x????x????x????xxxxx"); // direct reference
			
		inline Signature Wheel("\xE9\x00\x00\x00\x00\xB9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x4E", "x????x????x????xxxxx"); // direct reference

		inline Signature Screen("\xE8\x00\x00\x00\x00\x48\x8B\xF8\x48\x89\x45\x88\xBB\x00\x00\x00\x00", "x????xxxxxxxx????"); // direct reference

		inline Signature Trigger("\xE9\x00\x00\x00\x00\xB9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x10", "x????x????x????xxxxx"); // direct reference

		inline Signature Script("\xE8\x00\x00\x00\x00\x48\x8B\xD8\x33\xFF", "x????xxxxx"); // direct reference
	}

	// Really important functions
	namespace InternalFunctions {
		// Malloc can be found xref-ing any of the class constructors
		inline Signature malloc_base("\xE8\x00\x00\x00\x00\x49\x89\x47\x10", "x????xxxx"); // direct reference

		// Can be found called on the destroy functions of any Entity vtable (1st function on Entity, ScriptCore, etc)
		inline Signature j_free("\xE8\x00\x00\x00\x00\x4C\x8B\xF5", "x????xxx"); // direct reference
	}
}