#pragma once
#include "Types.h"
#include "Player.h"
#include "ShaderSystem.h"
#include "Scene.h"

class GameSettings

{
public:
	int renderScale; //0x0000
	int renderQuality; //0x0004
	int gammaCorrection; //0x0008
	int FOV; //0x000C
	int motionBlur; //0x0010
	int barrelDistortion; //0x0014
	int DOF; //0x0018
	int VSync; //0x001C
	int soundVolume; //0x0020
	int ambienceVolume; //0x0024 (Unused?)
	int musicVolume; //0x0028
	int mouseSmoothing; //0x002C
	int mouseSensitivity; //0x0030
	int invertLook; //0x0034
	int headBob; //0x0038
}; //Size: 0x003C

class UISettings
{
public:
	float UIXRescale; //0x0000
	float BTLSkew; //0x0004 Bottom to left skew
	float RTLCutoff; //0x0008 Right to left cutoff
	float MTLSkew; //0x000C Middle to left skew
	float BRSkew; //0x0010 Bottom right skew
	float UIYRescale; //0x0014
	float BTTClip; //0x0018 Bottom to top clip
	float BMSkew; //0x001C Bottom middle skew
	float cursorXOffset; //0x0020
	float cursorYOffset; //0x0024
	float N0000697C; //0x0028 Unknown, breaks cursor, values < -2 completely halt UI rendering
	float UIShrink; //0x002C
	float LTROffset; //0x0030 Left to right offset
	float TTBOffset; //0x0034 Top to bototm offset
	float N0000697E; //0x0038 Unknown, same behaviour as prev unknown value
	float UIScale; //0x003C
	float UIScaleX; //0x0040
	float RTBRSkew; //0x0044 Right to bottom right skew
	float RTLOffset; //0x0048 Right to left offset
	float LFTMSkew; //0x004C Left to top middle skew
	float BLTBRSkew; //0x0050 Bottom left to bottom right skew
	float UIYSize; //0x0054 Scale is relative to screen size
	float TTBClip; //0x0058 Top to bototm clip
	float BRTTLSkew; //0x005C Bottom right to top left skew
	float N0000698D; //0x0060 Unknown, doesn't seem to change anything
	float N00002B92; //0x0064 Unknown, doesn't seem to change anything
	float N00006993; //0x0068 Unknown, if you set it to 0 it makes you click on the last created elements
	float CursorYOffset; //0x006C
	float UIXOffset; //0x0070 In pixels
	float UIYOffset; //0x0074 Also in pixels
	float N00006996; //0x0078 Unknown, doesn't seem to change anything.
	float shrinkFromTopRight; //0x007C
}; //Size: 0x0080

class Game
{
public:
	char pad_0000[8]; //0x0000
	int8_t State; //0x0008 6: quitting | 5: editor | 4: in game | 3: starting ui | 2: in menu | 1: splash
	char pad_0009[3]; //0x0009
	int8_t StateTransition; //0x000C
	char pad_000D[3]; //0x000D
	float loadingFade; //0x0010
	bool isPlaying; //0x0014
	char pad_0015[3]; //0x0015
	float loadingFade2; //0x0018
	bool isMapOpen; //0x001C
	char pad_001D[11]; //0x001D
	class GameGLProgram* pGameGLProgram; //0x0028 No idea if they're programs, devices, or whatever, I'd love to know though
	class UIGLProgram* pUIGLProgram; //0x0030 cause i seriously don't know anything regarding this
	ShaderSystem* pShaderSystem; //0x0038
	class Scene* pScene; //0x0040
	class SoundSystem* pSoundSystem; //0x0048
	class CameraSystem* pCameraSystem; //0x0050
	class EditorUndoable* pEditorUndoable; //0x0058
	char pad_0060[8]; //0x0060
	void* pHud; //0x0068
	void* pHud2; //0x0070
	void* pHud3; //0x0078
	class HUD* pHud4; //0x0080
	class Debugger* pDebugging; //0x0088
	class Device* pDevice; //0x0090
	Player* pPlayer; //0x0098
	void* pDataManager; //0x00A0
	char pad_00A8[16]; //0x00A8
	void* pData; //0x00B8
	class modMgr* pModMgr; //0x00C0
	char pad_00C8[72]; //0x00C8
	bool isPaused; //0x0110
	char pad_0111[3]; //0x0111
	int32_t levelTime; //0x0114
	int32_t playTime; //0x0118
	char pad_011C[4]; //0x011C
	float timeScale; //0x0120
	float timeStep; //0x0124 1 / 59-ish = default val
	float totalDelta; //0x0128
	float totalTime; //0x012C
	float gameTime; //0x0130
	float gameDelta; //0x0134
	char pad_0138[156]; //0x0138
	UISettings HUDShaderSettings; //0x01D4
	bool isLoadingSave; //0x0254
	bool isSaving; //0x0255
	bool applyGraphics; //0x0256
	bool respawnPlayer; //0x0257
	float weirdEffect; //0x0258
	char pad_025C[24]; //0x025C
	GameSettings gameSettings; //0x0274
	char pad_02B0[24]; //0x02B0
	Teardown::small_string levelXMLPath; //0x02C8
	char pad_02D0[88]; //0x02D0
	char* levelXMLPath2; //0x0330
	char pad_0338[80]; //0x0338
	Teardown::small_string currentlyEditingXMLPath; //0x0388
	bool canReturnToEditor; //0x0398
	char pad_0399[7]; //0x0399
	char* editorTempXML; //0x03A0
	char pad_03A8[9]; //0x03A8
	bool updatingPlayer; //0x03B1
	char pad_03B2[22]; //0x03B2
	int32_t finalGLProgram; //0x03C8 Final renderTarget
	char pad_03CC[40]; //0x03CC
	int32_t screenResX; //0x03F4
	int32_t screenResY; //0x03F8
	char pad_03FC[20]; //0x03FC
}; //Size: 0x0410 / Verified