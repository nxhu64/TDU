#pragma once
#include "Script.h"
#include "Entities.h"
#include "Types.h"
#include "Lua.hpp"

namespace Teardown
{
	namespace Functions
	{
		namespace {
			typedef void (*tRegisterGameFunctions)		(ScriptCore* pScriptCore);
		};

		namespace Utils
		{
			const char* GetFilePath(const char* ccPath);
			const char* GetFilePathLua(ScriptCore* pSC, const char* ccPath);
			void GetAddresses();
		}

		namespace Constructors
		{
			void GetAddresses();
			Script* newScript(Entity* Parent);
			Body* newBody(Entity* Parent);
			Shape* newShape(Entity* Parent);
		}

		namespace LuaFunctions
		{
			void GetAddresses();
			void RegisterLuaFunction(ScriptCore_LuaState* pSCLS, const char* funcName, void* pFunction);
			inline tRegisterGameFunctions RegisterGameFunctions;
		}

		namespace EntityFunctions
		{
			void GetAddresses();
			Entity* GetEntityById(uint16_t entityId);

			Vox* LoadVox(Teardown::small_string* voxPath, const char* object, float Scale);

			void InitializeBody(Body* pBody);
			void SetBodyDynamic(Body* pBody, bool Dynamic);
		}

		void GetAddresses();
	}
}