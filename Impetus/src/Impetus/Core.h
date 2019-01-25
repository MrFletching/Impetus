#pragma once

#ifdef IMPETUS_PLATFORM_WINDOWS
	#ifdef IMPETUS_BUILD_DLL
		#define IMPETUS_API __declspec(dllexport)
	#else
		#define IMPETUS_API __declspec(dllimport)
	#endif
#else
	#error Impetus only supports Windows!
#endif
