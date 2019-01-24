#pragma once

#ifdef IM_PLATFORM_WINDOWS
	#ifdef IM_BUILD_DLL
		#define IM_API __declspec(dllexport)
	#else
		#define IM_API __declspec(dllimport)
	#endif
#else
	#error Impetus only supports Windows!
#endif
