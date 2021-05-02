#pragma once

#include "Environment.h"
#include "Entities.h"
#include "Script.h"

class CScene
{
public:
	char pad_0008[136];									//0x0008
	small_vector<void*> m_Projectiles;					//0x0090
	CEnvironment* m_Environment;						//0x00A0
	glm::vec3 m_SpawnPos;								//0x00A8
	char pad_00D4[20];									//0x00B4
	Light* m_Flashlight;								//0x00C8
	char pad_00D0[56];									//0x00D0
	void* m_CurrentVehicle;								//0x0108
	void* m_CurrentScreen;								//0x0110
	glm::vec3 m_ShadowVolumeSize;						//0x0118
	char pad_0124[252];									//0x0124
	small_vector<Body*>* m_Bodies;						//0x0220
	small_vector<Shape*>* m_Shapes;						//0x0228
	small_vector<void*>* m_Lights;						//0x0230
	small_vector<void*>* m_Locations;					//0x0238
	small_vector<Water*>* m_Waters;						//0x0240
	small_vector<void*>* m_Enemies;						//0x0248
	small_vector<void*>* m_Joints;						//0x0250
	small_vector<Vehicle*>* m_Vehicles;					//0x0258
	small_vector<Wheel*>* m_Wheels;						//0x0260
	small_vector<void*>* m_Screens;						//0x0268
	small_vector<void*>* m_Triggers;					//0x0270
	small_vector<Script*>* m_Scripts;					//0x0278
	char pad_0280[664];									//0x0280
	small_vector<glm::vec2*> m_Boundaries;				//0x0530
	char pad_0528[864];									//0x0528
	small_vector<Entity*> m_Entities;					//0x0888
	char pad_0898[8];									//0x0898
	glm::vec4 m_ColorBalance; 							//0x08A0
	float m_Saturation; 								//0x08B0
	float m_Gamma; 										//0x08B4
	float m_Bloom; 										//0x08B8
	char pad_08BC[4]; 									//0x08BC

	virtual void Function0();
	virtual void Function1();
}; //Size: 0x8C0