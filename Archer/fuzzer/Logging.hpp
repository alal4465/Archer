#pragma once
#include <iostream>
#include <string_view>
#include <ctime>
#include <string>

namespace Log {
	enum class LogLevel : unsigned int {
		DEBUG,
		INFO,
		WARN,
		ERR,
		LOG_LEVELS_SIZE
	};

	constexpr LogLevel MIN_LOG_LEVEL = LogLevel::DEBUG;
	constexpr std::string_view log_levels_printable[static_cast<unsigned int>(LogLevel::LOG_LEVELS_SIZE)] = {
		"Debug",
		"Info",
		"Warn",
		"Error",
	};

	#define LOG_DEBUG(msg) ::Log::impl::print_log(msg, ::Log::LogLevel::DEBUG, __LINE__, __FILE__, true)
	#define LOG_INFO(msg)  ::Log::impl::print_log(msg, ::Log::LogLevel::INFO, __LINE__, __FILE__)
	#define LOG_WARN(msg)  ::Log::impl::print_log(msg, ::Log::LogLevel:::WARN, __LINE__, __FILE__)
	#define LOG_ERROR(msg) ::Log::impl::print_log(msg, ::Log::LogLevel::ERR, __LINE__, __FILE__, true)

	namespace impl{
		inline std::string timestamp() {
			auto result = std::time(nullptr);
			auto readable_timestamp = std::string(std::asctime(std::localtime(&result)));
			readable_timestamp.pop_back();
			
			return readable_timestamp;
		}

		inline void print_log(const std::string& msg, LogLevel verbosity, int line, const char* filename, bool print_metadata = false) {
			if (verbosity < MIN_LOG_LEVEL) {
				return;
			}
			
			std::string printable_log(
				"[" + 
				(print_metadata ? timestamp() + ", " + filename + "@" + std::to_string(line) + ", " : "") +
				log_levels_printable[static_cast<unsigned int>(verbosity)].data() +
				"] : " +
				msg
			);
			if (verbosity >= LogLevel::WARN) {
				std::cerr << printable_log << "\n";
			}
			else {
				std::cout << printable_log << "\n";
			}
		}
	}
}