#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace alpha {
	std::shared_ptr<spdlog::logger> Log::s_coreLogger;
	
	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_coreLogger = spdlog::stdout_color_mt("ENGINE");
		s_coreLogger->set_level(spdlog::level::debug);
	}
}