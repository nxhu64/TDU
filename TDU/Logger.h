#ifndef Logger
#define Logger

#include <stdlib.h>
#include <vadefs.h>
#include <stdarg.h>
#include <iostream>

#include "Config.h"

#define WriteLog(logType, ...) Logger::LogInternal(__func__, __FILE__, logType, __VA_ARGS__)

enum class ELogType
{
	Generic = 1,
	Address = 2,
	Error = 3,
	Special = 4 // Don't get removed by ERRORS_ONLY (Only used by the loader message)
};

namespace Logger
{
	template<char const*... Args_t>
	inline void LogInternal(const char* sFuncName, const char* sFileName, ELogType eType, const char* fmt, ...)
	{
		if (!c_ConEnabled)
			return;

		char sSplitPath[255];
		char ext[20];
		_splitpath(sFileName, NULL, NULL, sSplitPath, ext);

		char buff[4096];
		va_list args;
		va_start(args, fmt);

		vsnprintf(buff, sizeof(buff), fmt, args);
		va_end(args);

		switch (eType)
		{
			if (!c_ConErrorsOnly)
			{
				case ELogType::Generic:
					std::cout << "\033[97;44;1m[" << sFuncName << " @ " << sSplitPath << ext << "]\033[0m " << buff << std::endl;
					break;
				case ELogType::Address:
					if (c_ConShowAddresses)
						std::cout << "\033[30;103;1m[" << "ADDRESS" << " @ " << sSplitPath << ext << "]\033[0m " << buff << std::endl;
					break;
			}
		case ELogType::Error:
			std::cout << "\033[30;41;1m[" << sFuncName << " @ " << sSplitPath << ext << "]\033[0m " << buff << std::endl;
			break;
		case ELogType::Special:
			std::cout << "\033[97;44;1m[" << sFuncName << " @ " << sSplitPath << ext << "]\033[0m " << buff << std::endl;
			break;
		}
	}
}

#endif