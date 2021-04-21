#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Types.h"

//////////////////////////////////////////////////////////
//  //  //  //  //  //	 Size info   //  //  //  //  //  /
//////////////////////////////////////////////////////////
// Entity name	| Hex size	| Size in bytes	| Entity ID //
// Body			|	0xE8	|	232 bytes	|	1		//
// Shape		|	0xD0	|	208 bytes	|	2		//
// Light		|	f0x1360	|	4960 bytes	|	3		//
// Location		|	0x48	|	72 bytes	|	4		//
// Water		|	0x370	|	880 bytes	|	5		//
// Enemy		|	0x440	|	1088 bytes	|	6		//
// Joint		|	0xC8	|	200 bytes	|	7		//
// Vehicle		|	0x288	|	648 bytes	|	8		//
// Wheel		|	0xF0	|	240 bytes	|	9		//
// Screen		|	0xC78	|	3192 bytes	|	10		//
// Trigger		|	0x110	|	272 bytes	|	11		//
// Script		|	0xBE0	|	3040 bytes	|	12		//
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//  //  //  //  //  //   Other sizes//	 //	 //	 //	 //	 /
//////////////////////////////////////////////////////////
//	Entity		|	0x28	|	40 bytes				//
//	Vox			|	0x60	|	96 bytes				//
//	Convex		|	0x2B8	|	696 bytes				//
//	HUD			|	0xA90	|	2704 bytes				//
//////////////////////////////////////////////////////////

enum class EEntityType : int8_t
{
	Body = 1,
	Shape = 2,
	Light = 3,
	Location = 4,
	Water = 5,
	Enemy = 6,
	Joint = 7,
	Vehicle = 8,
	Wheel = 9,
	Screen = 10,
	Trigger = 11,
	Script = 12
};

static const char* cEntityType[] = {
	"Body",
	"Shape",
	"Light",
	"Location",
	"Water",
	"Enemy",
	"Joint",
	"Vehicle",
	"Wheel",
	"Screen",
	"Trigger",
	"Script"
};

class Vox
{
public:
	int32_t m_SizeX;		//0x0000
	int32_t m_SizeY;		//0x0004
	int32_t m_SizeZ;		//0x0008
	char pad_000C[4];		//0x000C
	void* m_MatBuffer;		//0x0010
	void* m_PhysBuffer;		//0x0018
	float m_Scale;			//0x0020
	char pad_0024[56];		//0x0024
	int32_t m_VoxelCount;	//0x005C
}; //Size: 0x0060

class Entity
{
public:
	EEntityType	m_Type;			//0x08
	int8_t		m_Flags;		//0x09
	char		pad_000A[2];	//0x0A
	int16_t		m_Id;			//0x0C
	char		pad_000E[2];	//0x0E
	Entity* m_Parent;		//0x10
	Entity* m_Sibling;		//0x18
	Entity* m_Child;		//0x20

	virtual void	Destroy(Entity* entity, bool freeMemory);
	virtual Entity* SetParent(Entity* entity, Entity* parent);
	virtual void	Function2();
	virtual void	Function3();
}; // Size: 0x28

class Water : public Entity
{
public:
	char pad_0028[28];	//0x0028
	float m_Depth;		//0x0044
	char pad_0048[792]; //0x0048
	float m_Wave;		//0x0360
	float m_Ripple;		//0x0364
	float m_Motion;		//0x0368
	float m_Foam;		//0x036C
}; //Size: 0x370

class Light : public Entity
{
public:
	bool m_Active;			//0x0028
	char pad_0029[3];		//0x0029
	int8_t m_SourceType;	//0x002C 1 - Sphere | 2 - Cone | 3 - Area
	char pad_002D[3];		//0x002D
	glm::vec3 m_Position;	//0x0030
	glm::quat m_Rotation;	//0x003C
	glm::vec3 m_Colour;		//0x004C
	char pad_0058[4];		//0x0058
	float m_Intensity;		//0x005C
	float m_Reach;			//0x0060
	float m_Size;			//0x0064
	float m_Unshadowed;		//0x0068
	float m_Angle;			//0x006C
	float m_Penumbra;		//0x0070
	float m_FogIter;		//0x0074
	float m_FogScale;		//0x0078
	glm::vec2 m_AreaSize;	//0x007C
	float m_Glare;			//0x0084
	float VisibleGlare;		//0x0088
	char pad_008C[16];		//0x008C
	float m_IntensityMult;	//0x009C
	char pad_00A0[4800];	//0x00A0
}; //Size: 0x1360

class Shape : public Entity
{
public:
	glm::vec3 m_PosOffset; //0x0028 These are really glitchy, as they don't affect physics
	glm::vec4 m_RotOffset; //0x0034 ^
	glm::vec3 m_Min; //0x0044
	glm::vec3 m_Max; //0x0050
	char pad_005C[4]; //0x005C
	void* m_DormantBuffer; //0x0060
	void* m_ActiveBuffer; //0x0068
	char pad_0070[4]; //0x0070
	float m_Density; //0x0074
	float m_Hardness; //0x0078
	int32_t m_Texture; //0x007C
	char pad_0080[12]; //0x0080
	float m_TextureIntensity; //0x008C
	void* m_Vox; //0x0090
	char pad_0098[24]; //0x0098
	glm::vec3 m_Position; //0x00B0
	glm::vec4 m_Rotation; //0x00BC
	char pad_00CC[4]; //0x00CC
}; //Size: 0x00D0

class Body : public Entity
{
public:
	glm::vec3 m_Position;		//0x0028
	glm::quat m_Rotation;		//0x0034
	glm::vec3 m_Position2;		//0x0044
	glm::quat m_Rotation2;		//0x0050
	glm::vec3 m_Position3;		//0x0060
	glm::quat m_Rotation3;		//0x006C
	glm::vec3 m_Velocity;		//0x007C
	glm::vec3 m_RotVelocity;	//0x0088
	char pad_0094[12];			//0x0094
	float m_Lightness;			//0x00A0 Dunno what this is actually
	char pad_00A4[24];			//0x00A4
	float m_Integrity;			//0x00BC
	char pad_00C0[28];			//0x00C0
	bool m_Dynamic;				//0x00DC
	char pad_00DD[8];			//0x00DD
	bool m_Colliding;			//0x00E5
	char pad_00E6[2];			//0x00E6
}; //Size: 0xE8

class Vehicle;

class Wheel : public Entity
{
public:
	Vehicle* m_Vehicle;			//0x0028
	Body* m_VehicleBody;		//0x0030
	Body* m_WheelBody;			//0x0038
	Shape* m_WheelShape;		//0x0040
	char pad_0048[56];			//0x0048
	float m_Steer;				//0x0080
	float m_Drive;				//0x0084
	glm::vec3 m_Travel;			//0x0088
	char pad_0094[24];			//0x0094
	float m_TurnSpeed;			//0x00AC
	char pad_00B0[64];			//0x00B0
}; //Size: 0x00F0

class Vehicle : public Entity
{
public:
	Body* m_Body;								//0x0028
	glm::vec3 m_Position;						//0x0030
	glm::quat m_Rotation;						//0x003C
	char pad_004C[28];							//0x004C
	small_vector<Wheel*> m_Wheels;	//0x0068
	char pad_0078[68];							//0x0078
	float m_TopSpeed;							//0x00BC
	char pad_00C0[4];							//0x00C0
	float m_Spring;								//0x00C4
	float m_Damping;							//0x00C8
	float m_Acceleration;						//0x00CC
	float m_Strength;							//0x00D0
	float m_Friction;							//0x00D4
	char pad_00D8[4];							//0x00D8
	bool m_Driven;								//0x00DC
	char pad_00DD[3];							//0x00DD
	float m_Antispin;							//0x00E0
	float m_SteerAssist;						//0x00E4
	char pad_00E8[4];							//0x00E8
	float m_Antiroll;							//0x00EC
	float m_Difflock;							//0x00F0
	char pad_00F4[4];							//0x00F4
	char* m_Sound;								//0x00F8
	char pad_0100[60];							//0x0100
	glm::vec2 m_MoveInput;						//0x013C
	float m_Handbrake;							//0x0144
	float m_M1Down;								//0x0148
	float m_M2Down;								//0x014C
	char pad_0150[8];							//0x0150
	float m_Turn;								//0x0158
	float m_AccelerationCompletion;				//0x015C
	char pad_0160[4];							//0x0160
	float m_AccelerationCompletion2;			//0x0164
	char pad_0168[4];							//0x0168
	float m_VehicleCondition;					//0x016C
	char pad_0170[276]; 						//0x0170
	bool m_Braking; 							//0x0284
	char pad_0285[3];							//0x0285
}; //Size: 0x0288

class Screen : public Entity
{
	char pad_0028[24];		//0x0028
	glm::vec3 m_Size;		//0x0040
	float m_Bulge;			//0x004C
	int32_t m_ResX;			//0x0050
	int32_t m_ResY;			//0x0054
	char* m_ScriptPath;		//0x0058
	char pad_0060[8];		//0x0060
	bool m_Enabled;			//0x0068
	bool m_Interactive;		//0x0069
	char pad_006A[2];		//0x006A
	float m_Emissive;		//0x006C
	float m_fxRaster;		//0x0070
	float m_fxCA;			//0x0074
	float m_fxNoise;		//0x0078
	float m_fxGlitch;		//0x007C
	char pad_0080[2296];	//0x0080
	int32_t m_ShaderUniform;//0x0978
	char pad_097C[708];		//0x097C
}; // Size: 0x0C78