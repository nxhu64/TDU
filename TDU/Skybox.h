#pragma once
#include "Types.h"
#include <glm/glm.hpp>

class Skybox
{
public:
	Teardown::small_string path;
	char pad_0018[16]; //0x0018
	float skyboxrot; //0x0020
	char pad_0024[12]; //0x0024
	glm::vec3 sunColorTint; //0x0030
	char pad_003C[16]; //0x003C
	float sunBrightness; //0x004C
	float sunSpread; //0x0050
	float sunLength; //0x0054
	float sunFogScale; //0x0058
	float sunGlare; //0x005C
	char pad_0060[4]; //0x0060
	float ambient; //0x0064
	glm::vec2 exposure; //0x0068
	float brightness;
	glm::vec3 fogColor; //0x0074
	char pad_0080[4]; //0x0080
	glm::vec4 fogParams; //0x0084
	float wetness; //0x0094
	float puddleamount; //0x0098
	float puddlesize; //0x009C
	float rain; //0x00A0
	bool nightlight; //0x00A4
	char pad_00A5[83]; //0x00A5
	Teardown::small_string ambience; //0x00F8
	float slippery; //0x0110
}; //Size: 0x0114