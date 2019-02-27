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

// TODO: why does it not format the string? It just logs the format string without
// any args formatted into the format string :(
template<typename... Args>
void LOG(const std::string& format, Args... args) {
	alpha::Log::GetCoreLogger()->info(format.c_str(), args...);
}

template<typename... Args>
void LOG_ERROR(const std::string& format, Args... args) {
	alpha::Log::GetCoreLogger()->error(format.c_str(), args...);
}

template<typename... Args>
void DEBUG(const std::string& format, Args... args) {
	alpha::Log::GetCoreLogger()->debug(format.c_str(), args...);
}