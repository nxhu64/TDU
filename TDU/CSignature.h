#pragma once
#include <minwindef.h>
class CSignature
{
public:
	CSignature(const char* cPattern, const char* cMask, bool bDirectRef)
	{
		size_t lLength = strlen(cMask);

		m_Pattern = (PBYTE)malloc(lLength + 1);
		memcpy(m_Pattern, (PBYTE)cPattern, lLength);

		m_Mask = (char*)malloc(lLength + 1);
		strcpy(m_Mask, cMask);
		m_Mask[strlen(cMask)] = 0;

		m_DirectRef = bDirectRef;
	}

	PBYTE m_Pattern;
	char* m_Mask;
	bool m_DirectRef;
};