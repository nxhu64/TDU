#pragma once

#include "Signatures.h"
#include "Memory.h"
#include "Logger.h"
#include "tdf_Memory.h"
#include "Entities.h"
#include "Script.h"

namespace Teardown
{
	namespace Constructors
	{
		namespace
		{
			typedef void* (*tCreateEntity)				(void* pAlloc, void* pParent);
		}

		inline tCreateEntity tdCreateBody;
		inline tCreateEntity tdCreateShape;
		inline tCreateEntity tdCreateLight;
		inline tCreateEntity tdCreateLocation;
		inline tCreateEntity tdCreateWater;
		//inline tCreateEntity tdCreateEnemy;
		inline tCreateEntity tdCreateJoint;
		inline tCreateEntity tdCreateVehicle;
		inline tCreateEntity tdCreateWheel;
		inline tCreateEntity tdCreateScreen;
		inline tCreateEntity tdCreateTrigger;
		inline tCreateEntity tdCreateScript;

		inline Body* CreateBody(Entity* pParent)
		{
			void* Alloc = Teardown::MemoryFunctions::Alloc(sizeof(Body));
			return (Body*)tdCreateBody(Alloc, pParent);;
		}

		inline Shape* CreateShape(Entity* pParent)
		{
			void* Alloc = Teardown::MemoryFunctions::Alloc(sizeof(Shape));
			return (Shape*)tdCreateShape(Alloc, pParent);;
		}

		inline Script* CreateScript(Entity* pParent)
		{
			void* pAlloc = Teardown::MemoryFunctions::Alloc(sizeof(Script));
			return (Script*)tdCreateScript(pAlloc, pParent);
		}

		inline void GetAddresses()
		{
			tdCreateBody = (tCreateEntity)Memory::dwFindPattern(Signatures::Constructors::Body);
			tdCreateShape = (tCreateEntity)Memory::dwFindPattern(Signatures::Constructors::Shape);
			tdCreateLight = (tCreateEntity)Memory::dwFindPattern(Signatures::Constructors::Light);
			tdCreateLocation = (tCreateEntity)Memory::dwFindPattern(Signatures::Constructors::Location);
			tdCreateWater = (tCreateEntity)Memory::dwFindPattern(Signatures::Constructors::Water);
			//tdCreateEnemy = (tCreateEntity)Memory::dwFindPattern(Signatures::Constructors::Enemy);
			tdCreateJoint = (tCreateEntity)Memory::dwFindPattern(Signatures::Constructors::Joint);
			tdCreateVehicle = (tCreateEntity)Memory::dwFindPattern(Signatures::Constructors::Vehicle);
			tdCreateWheel = (tCreateEntity)Memory::dwFindPattern(Signatures::Constructors::Wheel);
			tdCreateScreen = (tCreateEntity)Memory::dwFindPattern(Signatures::Constructors::Screen);
			tdCreateTrigger = (tCreateEntity)Memory::dwFindPattern(Signatures::Constructors::Trigger);
			tdCreateScript = (tCreateEntity)Memory::dwFindPattern(Signatures::Constructors::Script);


			WriteLog(ELogType::Address, "===== Entity constructors =====");
			WriteLog(ELogType::Address, "Body: 0x%p", tdCreateBody);
			WriteLog(ELogType::Address, "Shape: 0x%p", tdCreateShape);
			WriteLog(ELogType::Address, "Light: 0x%p", tdCreateLight);
			WriteLog(ELogType::Address, "Location: 0x%p", tdCreateLocation);
			WriteLog(ELogType::Address, "Water: 0x%p", tdCreateWater);
			//WriteLog(ELogType::Address, "Enemy", tdCreateEnemy);
			WriteLog(ELogType::Address, "Joint: 0x%p", tdCreateJoint);
			WriteLog(ELogType::Address, "Vehicle: 0x%p", tdCreateVehicle);
			WriteLog(ELogType::Address, "Wheel: 0x%p", tdCreateWheel);
			WriteLog(ELogType::Address, "Screen: 0x%p", tdCreateScreen);
			WriteLog(ELogType::Address, "Trigger: 0x%p", tdCreateTrigger);
			WriteLog(ELogType::Address, "Script: 0x%p", tdCreateScript);

		}
	}
}