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

template<typename... Args>
void AssertionFailure(const char* expr, const char* file, int line, const char* func) {
	alpha::Log::GetCoreLogger()->critical(
		"***ASSERTION FAILURE***\n"
		"Expression:\n"
		"{0}\n"
		"In ::{1}\n"
		"File: {2}\n"
		"Line: {3}",
		expr, func, file, line);

	std::abort();
}

#define ASSERTION_FAILURE(X) AssertionFailure(X, __FILE__, __LINE__, __FUNCTION__)
#define ASSERT(X) void((!(X))?(ASSERTION_FAILURE(#X),0):0)