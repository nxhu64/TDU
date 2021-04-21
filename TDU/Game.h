#pragma once
#include <stdint.h>

#include "GameSettings.h"

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

class CGame
{
public:
	char pad_0000[8];				//0x0000
	int32_t m_State;				//0x0008
	int32_t m_TargetState;			//0x000C
	float m_LoadingEffect;			//0x000D
	bool m_Playing;					//0x0014
	char pad_0015[3];				//0x0015
	float m_LoadingEffect2;			//0x0018
	int32_t m_MapOpen;				//0x001C
	char pad_001D[32];				//0x001D
	CScene* m_Scene;				//0x0040
	char pad_0048[64];				//0x0048
	char m_Debugger[8];				//0x0088
	char pad_0090[8];				//0x0090
	CPlayer* m_Player;				//0x0098
	void* pPathManager;				//0x00A0
	char pad_00A0[16];				//0x00A0
	void* m_Data;					//0x00B8 (Not reversed yet)
	char pad_00C0[80];				//0x00C0
	bool m_Paused;					//0x0110
	char pad_0111[3];				//0x0111
	int32_t m_iElapsedTime;			//0x0114
	int32_t m_iPlayedTime;			//0x0118
	char pad_011C[4];				//0x011C
	float m_TimeScale;				//0x0120
	float m_TimeStep;				//0x0124 Limited to 1/60 (without patching)
	float m_TimeDelta;				//0x0128 Not limited to < 1/60
	float m_fElapsedTime;			//0x012C
	float m_fPlayedTime;			//0x0130
	float m_TimeDelta2;				//0x0134
	char pad_0138[284];				//0x0138
	bool m_LoadingSave;				//0x0254
	bool m_Saving;					//0x0255
	bool m_ApplyingSettings;		//0x0256
	bool m_RespawningPlayer;		//0x0257
	float m_CameraTransition;		//0x0258
	char pad_0268[16];				//0x0268
	CGameSettings m_GameSettings;	//0x0274
	char pad_02B0[24];				//0x02B0
	char m_LevelXMLPath[8];			//0x02C8
	char pad_02D0[88];				//0x02D0
	char m_LevelXMLPath2[8];		//0x0330
	char pad_0338[80];				//0x0338
	char m_LevelEditorPath[16];		//0x0388
	int m_CanReturnToEditor;		//0x0398
	char pad_0399[4];				//0x039C
	char* m_EditorTempPath;			//0x03A0
	char pad_03A8[9];				//0x03A8
	bool m_IsUpdatingPlayer;		//0x03B1
	char pad_03B2[22];				//0x03B2
	int32_t m_FinalRTProgram;		//0x03C8
	char pad_03CC[40];				//0x03CC
	int32_t screenResX;				//0x03F4
	int32_t screenResY;				//0x03F8
	char pad_03FC[20];				//0x03FC
};

inline CGame* g_Game;