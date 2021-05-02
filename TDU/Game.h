#pragma once
#include <stdint.h>

#include "Player.h"
#include "Scene.h"
#include "Types.h"

enum eGameState : int8_t
{
	Splash = 1,
	Menu = 2,
	UIStart = 3,
	Playing = 4,
	Editor = 5,
	Quitting = 6
};

inline static const char* cGameState[] = {
	"Splash Screen",
	"Menu",
	"UI Startup",
	"In-Game",
	"Editing",
	"Quitting"
};

class CMatrices
{
public:
	glm::mat4x4 m_ProjectionMatrix; //0x0000
	glm::mat4x4 m_ViewMatrix; //0x0040
}; //Size: 0x0080

class CGameSettings
{
public:
	int m_RenderScale;		//0x0000
	int m_RenderQuality;	//0x0004
	int m_GammaCorrection;	//0x0008
	int m_FOV;				//0x000C
	int m_MotionBlur;		//0x0010
	int m_BarrelDist;		//0x0014
	int m_DOF;				//0x0018
	int m_VSync;			//0x001C
	int m_SoundVol;			//0x0020
	int m_AmbienceVol;		//0x0024 (Unused?)
	int m_MusicVol;			//0x0028
	int m_MouseSmoothing;	//0x002C
	int m_MouseSensitivity; //0x0030
	int m_InvertLook;		//0x0034
	int m_HeadBob;			//0x0038
}; //Size: 0x003C

class CGame
{
public:
	int32_t m_ResX;					//0x0000
	int32_t m_ResY;					//0x0004
	int32_t m_State;				//0x0008
	int32_t m_TargetState;			//0x000C
	float m_LoadingEffect;			//0x000D
	bool m_Playing;					//0x0014
	char pad_0015[3];				//0x0015
	float m_LoadingEffect2;			//0x0018
	bool m_MapOpen;					//0x001C
	char pad_001D[43];				//0x001D
	CScene* m_Scene;				//0x0048
	char pad_0058[40];				//0x0058
	void* m_MenuScript;				//0x0080
	char pad_0088[24];				//0x0088
	CPlayer* m_Player;				//0x00A0
	void* m_PathMgr;				//0x00A8
	char pad_00A8[48];				//0x00B0
	void* m_SteamInterface;			//0x00E0 - To be used for mod sync
	char pad_00E8[48];				//0x00E8
	bool m_Paused;					//0x0118
	char pad_0119[3];				//0x0119
	int32_t m_iElapsedTime;			//0x011C
	int32_t m_iPlayedTime;			//0x0120
	float m_SoundTimeScale;			//0x0124
	float m_Timescale;				//0x0128
	float m_TimeStep;				//0x012C
	float m_TimeDelta;				//0x0130
	float m_fElapsedTime;			//0x0134
	float m_fPlayedTime;			//0x0138
	float m_TimeDelta2;				//0x013C
	char pad_0140[28];				//0x0140
	CMatrices m_GameMatrix;			//0x015C
	CMatrices m_UIMatrix;			//0x01DC
	char pad_025C[36];				//0x025C
	CGameSettings m_GameSettings;	//0x0280
	char pad_02BC[4];				//0x02BC
	small_string m_LevelId;			//0x02C0
	small_string m_LevelLayer;		//0x02D8
	char pad_02F0[56];				//0x02F0
	small_string m_LevelId2;		//0x0328
	small_string m_LevelLayer2;		//0x0340
	char pad_0358[80];				//0x0358
	class small_string m_TempPath;	//0x03A8
};

inline CGame* g_Game;