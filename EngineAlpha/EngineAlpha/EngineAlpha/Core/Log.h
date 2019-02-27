#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace alpha {
	class Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_coreLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
	};
}

template<typename... Args>
void LOG(const std::string& format, const Args&... args) {
	alpha::Log::GetCoreLogger()->info(format.c_str(), args...);
}

template<typename... Args>
void LOG_ERROR(const std::string& format, const Args&... args) {
	alpha::Log::GetCoreLogger()->error(format.c_str(), args...);
}

template<typename... Args>
void DEBUG(const std::string& format, const Args&... args) {
	alpha::Log::GetCoreLogger()->debug(format.c_str(), args...);
}