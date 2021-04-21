#pragma once

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