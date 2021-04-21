#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Entities.h"

class Tool
{
public:
	char* m_ModelPath;		//0x0000
	char pad_0008[8];		//0x0008
	float m_ModelRecoil;	//0x0010
	float m_ViewPunch;		//0x0014
	glm::vec3 m_Position;	//0x0018 Relative to camera / player
	glm::quat m_Rotation;	//0x0024
	float m_Cooldown;		//0x0034
}; //Size: 0x0038

/*
	A lot of irrelevant stuff / stuff i didn't finish reversing was removed
*/
class CPlayer
{
	glm::vec3 m_Position;			//0x0000
	char pad_0028[60];				//0x000C
	glm::vec3 m_Velocity;			//0x0038
	char pad_0044[12];				//0x0044
	glm::vec3 m_Velocity2;			//0x0050
	int m_lastInteratedShapeId;		//0x005C
	glm::vec3 m_CamPosition;		//0x0060
	glm::quat m_CamRot;				//0x006C
	glm::vec3 m_CamPosition2;		//0x007C
	glm::quat m_CamRot2;			//0x0088
	glm::vec3 m_CamPosition3;		//0x0098
	glm::quat m_CamRot3;			//0x00A4
	glm::vec2 m_MovementMult;		//0x00B4
	float m_TravelDist;				//0x00BC
	float m_TravelDist2;			//0x00C0
	glm::vec2 m_TotalMouseDelta;	//0x00C4
	glm::vec2 m_MouseMovement;		//0x00CC
	glm::vec2 m_Input;				//0x00D4
	glm::vec2 m_MouseDelta;			//0x00DC
	char pad_00E4[1];				//0x00E4
	bool m_Crouching;				//0x00E5
	char pad_00E6[1];				//0x00E6
	bool m_M1Down;					//0x00E7
	bool m_Shooting;				//0x00E8
	bool m_M2Down;					//0x00E9
	char pad_00EA[35];				//0x00EA
	float m_CrouchCompletino;		//0x010C
	char pad_0110[8];				//0x0110
	Body* m_GrabbedBody;			//0x118
	char pad_0120[48];				//0x0120
	float m_GrabDist;				//0x0148
	float m_GrabDist2;				//0x014C
	Body* m_GrabbedBody2;			//0x0150
	bool m_Throwing;				//0x0158
	char pad_0159[3];				//0x0159
	float m_Health;					//0x015C
	char pad_0160[56];				//0x0160
	Tool m_Sledge;					//0x0198
	Tool m_Spraycan;				//0x01D0
	Tool m_Extinguisher;			//0x0208
	Tool m_Blowtorch;				//0x0240
	Tool m_Shotgun;					//0x0278
	Tool m_Plank;					//0x02B0
	Tool m_Pipebomb;				//0x02E8
	Tool m_Gun;						//0x0320
	Tool m_Bomb;					//0x0358
	Tool m_Rocket;					//0x0390
	char m_EquippedToolName[16];	//0x03C8
	Body* m_ToolBody;				//0x03D8
	char pad_03E0[28];				//0x03E0
	glm::vec3 m_ToolPos;			//0x03FC
	glm::quat m_ToolRot;			//0x0408
	char pad_0418[8];				//0x0418
	float m_Recoil;					//0x0420
	float m_EquipTransition;		//0x0424
	float m_ToolCooldown;			//0x0428
	float m_OnGround;				//0x042C (Why is this a float?)
	float m_AirTime;				//0x0430
	float m_OnGround2;				//0x0434
	float m_AirTime2;				//0x0438
	glm::vec3 m_GroundSlope;		//0x043C Seems related to slope, it's weird that it's not a quaternion though
	glm::vec3 m_GroundPos;			//0x0448
	char pad_0454[4];				//0x0454
	Body* m_GroundBody;				//0x0458
	int32_t m_GroundMaterialId;		//0x0460
	float m_GroundR;				//0x0464
	float m_GroundG;				//0x0468
	float m_GroundB;				//0x046C
	char pad_0470[20];				//0x0470
	bool m_StandingOnModPalette;	//0x0484 Named like this for lack of a better name, it's set to one whenever the player is standing on a surface that has been sprayed or burnt
	char pad_0485[7];				//0x0485
	float m_TimeSinceLastJump;		//0x048C
	char pad_0490[4];				//0x0490
	float m_ViewpunchFast;			//0x0494
	float m_ViewPunchSlow;			//0x0498
	char pad_049C[12];				//0x049C
	Shape* m_CursorShape;			//0x04A8
	float m_CursorDist;				//0x04B0
	glm::vec3 m_CursorPos;			//0x04B4
	char pad_04C0[12];				//0x04C0
	bool m_CanGrab;					//0x04CC
	char pad_04CD[3];				//0x04CD
	Shape* m_GrabbedShape;			//0x04D0
	Shape* m_InteractableShape;		//0x04D8
	char pad_04E0[52];				//0x04E0
	float m_JumpHeight;				//0x0514
	char pad_0518[8];				//0x0518
	Water* m_SwimmingWater;			//0x0520
	float m_WaterAltitude;			//0x0528
	bool m_IsUnderwater;			//0x052C
	char pad_052D[3];				//0x052D
	float m_ElapsedSinceLastDive;	//0x0530 
	float m_ElapsedSinceLastSwim;	//0x0534
	float m_UnderwaterTime;			//0x0538 Starts drowning at 10s	
	char pad_053C[5];				//0x053C
	bool m_CanUseTool;				//0x0541
	char pad_0542[12398];			//0x0542
}; //Size: 0x35B0

inline CPlayer* g_Player;