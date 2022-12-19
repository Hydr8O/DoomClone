#pragma once

#ifdef DC_PLATFORM_WINDOWS
	#ifdef DC_BUILD_DLL
		#define DoomClone_API __declspec(dllexport)
	#else
		#define DoomClone_API __declspec(dllimport)
	#endif
#endif