#pragma once
#include <glm/glm.hpp>
#include "Types.h"

class CEnvironment
{
public:
	char* m_Skybox; //0x0000
	char pad_0008[8]; //0x0008
	glm::vec3 m_SkyboxTint; //0x0010
	float m_SkyboxBrightness; //0x001C
	float m_SkyboxRot; //0x0020
	char pad_0024[12]; //0x0024
	glm::vec3 m_SunColorTint; //0x0030
	char pad_003C[16]; //0x003C
	float m_SunBrightness; //0x004C
	float m_SunSpread; //0x0050
	float m_SunLength; //0x0054
	char pad_0058[4]; //0x0058
	float m_SunGlare; //0x005C
	char pad_0060[4]; //0x0060
	glm::vec4 m_Constant; //0x0064
	float m_Ambient; //0x0074
	float m_AmbienetExponent; //0x0078
	glm::vec2 m_Exposure; //0x007C min, max
	float m_Brightness; //0x0084
	glm::vec3 m_FogColor; //0x0088
	char pad_0094[4]; //0x0094
	glm::vec4 m_FogParams; //0x0098
	float m_Wetness; //0x00A8
	float m_PuddleAmount; //0x00AC
	float m_Puddlesize; //0x00B0
	float m_Rain; //0x00B4
	bool m_Nightlight; //0x00B8
	char pad_00B9[87]; //0x00B9
	small_string m_Ambience; //0x0110
	float m_Slippery; //0x0128
	float m_FogScale; //0x012C
}; //Size: 0x0130