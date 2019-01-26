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

#ifdef IMPETUS_DEBUG
	#define IMPETUS_CORE_ASSERT(x, ...) { if(!(x)) { IMPETUS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define IMPETUS_ASSERT(x, ...) { if(!(x)) { IMPETUS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define IMPETUS_CORE_ASSERT(x, ...)
	#define IMPETUS_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)