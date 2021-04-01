#pragma once
#include "Script.h"
#include "Entities.h"
#include "Types.h"
#include "Lua.hpp"

namespace Teardown
{
	namespace Functions
	{
		namespace Utils
		{
			Teardown::small_string* GetFilePath(Teardown::small_string ssPath);
			Teardown::small_string* GetFilePathLua(lua_State* L, const char* ccPath);
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
			void RegisterGameFunctions(ScriptCore* pScriptCore);
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