#pragma once
#include "Types.h"

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

class Tool
{
public:
	char* modelPath; //0x0000
	int32_t unk; //0x0008
	char pad_000C[4]; //0x000C
	float modelRecoil; //0x0010
	float cameraRecoil; //0x0014
	glm::vec3 Position; //0x0018 Relative to camera / player
	glm::quat Rotation; //0x0024
	float cooldown; //0x0034
}; //Size: 0x0038

class Player
{
public:
	glm::vec3 Position; //0x0000
	glm::quat vehicleRotation; //0x000C
	char pad_0028[28]; //0x001C
	glm::vec3 Velocity; //0x0038
	char pad_0044[12]; //0x0044
	glm::vec3 Velocity2; //0x0050
	int32_t lastInteractedShapeIdx; //0x005C
	glm::vec3 cameraPositionProcessed; //0x0060
	glm::quat cameraRotationProcessed; //0x006C
	glm::vec3 cameraPosition2; //0x007C
	glm::quat cameraRotation2; //0x0088
	glm::vec3 cameraPosition3; //0x0098
	glm::quat cameraRotation3; //0x00A4
	float fwdDelta; //0x00B4
	float sideDelta; //0x00B8
	float travelDist; //0x00BC
	float travelDist2; //0x00C0 resets after hitting 1
	glm::vec2 totalProcessedMouseDelta; //0x00C4
	glm::vec2 totalMouseDelta; //0x00CC
	glm::vec2 moveKeys; //0x00D4
	glm::vec2 mouseDelta; //0x00DC
	char pad_00E4[1]; //0x00E4
	bool isCrouched; //0x00E5
	char pad_00E6[1]; //0x00E6
	bool isMouse2Down; //0x00E7
	char pad_00E8[1]; //0x00E8
	bool isMouse1Down; //0x00E9
	char pad_00EA[2]; //0x00EA
	float playerHeight; //0x00EC
	char pad_00F0[28]; //0x00F0
	float crouchCompletion; //0x010C
	char pad_0110[8]; //0x0110
	class Body* pGrabbedBody; //0x0118
	char pad_0120[40]; //0x0120
	float grabDist1; //0x0148
	float grabDist2; //0x014C
	class Body* pGrabbedBody2; //0x0150
	bool isThrowing; //0x0158
	char pad_0159[3]; //0x0159
	float Health; //0x015C
	char pad_0160[56]; //0x0160
	Tool sledge; //0x0198
	Tool spraycan; //0x01D0
	Tool extinguisher; //0x0208
	Tool blowtorch; //0x0240
	Tool Shotgun; //0x0278
	Tool Plank; //0x02B0
	Tool Pipebomb; //0x02E8
	Tool Gun; //0x0320
	Tool Bomb; //0x0358
	Tool Rocket; //0x0390
	Teardown::small_string equippedToolName; //0x03C8
	class Body* pToolBody; //0x03D8
	char pad_03E0[28]; //0x03E0
	glm::vec3 toolPos; //0x03FC
	glm::quat toolRot; //0x0408
	char pad_0418[8]; //0x0418
	float recoil; //0x0420
	float equipAnimation; //0x0424 Something related to equipping
	float toolCooldown; //0x0428
	float onGround; //0x042C
	float airTime; //0x0430
	float onGround2; //0x0434
	float airTime2; //0x0438
	glm::vec3 groundNormal; //0x043C Uncertain
	glm::vec3 lastWalkedPos; //0x0448
	char pad_0454[4]; //0x0454
	class Body* pLastCollidedBody; //0x0458
	int32_t groundSurfaceId; //0x0460
	float groundR; //0x0464
	float groundG; //0x0468
	float groundB; //0x046C
	char pad_0470[20]; //0x0470
	bool isStandingOnAlteredPalette; //0x0484 Long name, i should come up with something better for this
	char pad_0485[7]; //0x0485
	float timeSinceLastJump; //0x048C
	char pad_0490[4]; //0x0490
	float recoilFast; //0x0494
	float recoilSlow; //0x0498
	char pad_049C[12]; //0x049C
	class Shape* pTargetShape; //0x04A8
	float raycastDist; //0x04B0
	glm::vec3 raycastHit; //0x04B4
	char pad_04C0[12]; //0x04C0
	bool canGrab; //0x04CC
	char pad_04CD[3]; //0x04CD
	class Shape* pGrabbedShape; //0x04D0
	class Shape* pInteractableShape; //0x04D8
	char pad_04E0[52]; //0x04E0
	float jumpHeight; //0x0514
	char pad_0518[8]; //0x0518
	class Water* pSwimmingWater; //0x0520
	float underwaterDepth; //0x0528 Only updates when player is touching water
	bool isUnderwater; //0x052C
	char pad_052D[3]; //0x052D
	float playedTime2; //0x0530 Starts at 3, counts total play time (resets on restart / level load)
	float playedTime; //0x0534
	float underwaterTime; //0x0538 Starts drowning at 10s
	char pad_053C[5]; //0x053C
	bool canUseTool; //0x0541
	char pad_0542[12398]; //0x0542
}; //Size: 0x35B0