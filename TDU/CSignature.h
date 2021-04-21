#pragma once
#include <minwindef.h>
class CSignature
{
public:
	CSignature(const char* nPattern, const char* nMask, bool bDirectRef)
	{
		m_Pattern = (PBYTE)nPattern; m_Mask = nMask; m_DirectRef = bDirectRef;
	}

	PBYTE m_Pattern;
	const char* m_Mask;
	bool m_DirectRef;
};