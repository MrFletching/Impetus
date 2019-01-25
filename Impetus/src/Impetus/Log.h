#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Impetus {

	class IMPETUS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define IMPETUS_CORE_TRACE(...) ::Impetus::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define IMPETUS_CORE_INFO(...)  ::Impetus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define IMPETUS_CORE_WARN(...)  ::Impetus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define IMPETUS_CORE_ERROR(...) ::Impetus::Log::GetCoreLogger()->error(__VA_ARGS__)
#define IMPETUS_CORE_FATAL(...) ::Impetus::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define IMPETUS_TRACE(...) ::Impetus::Log::GetClientLogger()->trace(__VA_ARGS__)
#define IMPETUS_INFO(...)  ::Impetus::Log::GetClientLogger()->info(__VA_ARGS__)
#define IMPETUS_WARN(...)  ::Impetus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define IMPETUS_ERROR(...) ::Impetus::Log::GetClientLogger()->error(__VA_ARGS__)
#define IMPETUS_FATAL(...) ::Impetus::Log::GetClientLogger()->fatal(__VA_ARGS__)
