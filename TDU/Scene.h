#pragma once
#include "Types.h"
#include "Entities.h"
#include "Script.h"
#include "Environment.h"

class Scene
{
public:
	char pad_0008[8]; //0x0008
	class ppScene* ppScene; //0x0010
	char pad_0018[88]; //0x0018
	void* pParticleSystem; //0x0070
	char pad_0078[48]; //0x0078
	class fireSystem* pFireSystem; //0x00A8
	Teardown::small_vector<Projectile*> projectileList;
	Environment* pEnvironment; //0x00C0
	glm::vec3 spawnPos; //0x00C8
	char pad_00D4[20]; //0x00D4
	Light* pFlashlight; //0x00E8
	char pad_00F0[48]; //0x00F0
	class Vehicle* pCurrentVehicle; //0x0120
	class Screen* pCurrentScreen; //0x0128
	char pad_0130[248]; //0x0130
	Teardown::small_vector<Entity*> entityList; //0x0228
	Teardown::small_vector<Body*>* pBodyList; //0x0238
	Teardown::small_vector<Shape*>* pShapeList; //0x0240
	Teardown::small_vector<void*>* pLightList; //0x0248
	Teardown::small_vector<void*>* pLocationList; //0x0250
	Teardown::small_vector<Water*>* pWaterList; //0x0258
	Teardown::small_vector<void*>* pEnemyList; //0x0260
	Teardown::small_vector<void*>* pJointList; //0x0268
	Teardown::small_vector<Vehicle*>* pVehicleList; //0x0270
	Teardown::small_vector<Wheel*>* pWheelList; //0x0278
	Teardown::small_vector<void*>* pScreenList; //0x0280
	Teardown::small_vector<void*>* pTriggerList; //0x0288
	Teardown::small_vector<Script*>* pScriptList; //0x0290
	char pad_0298[48]; //0x0298
	float distanceToBoundary; //0x02C8
	char pad_02CC[612]; //0x02CC
	Teardown::small_vector<glm::vec2*> Boundaries; //0x0530
	char pad_0540[864]; //0x0540
	Teardown::small_vector<Entity*> entityList2; //0x08A0
	char pad_08B0[8624]; //0x08B0
	void* (*pSomethingArray)[150]; //0x2A60
	char pad_2A68[1792]; //0x2A68

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x3168