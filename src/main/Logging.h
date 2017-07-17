#ifndef SRC_MAIN_LOGGING_H_
#define SRC_MAIN_LOGGING_H_

#include <Arduino.h>
#include "Config.h"

class Log {
public:
	template<typename T>
	static void debug(T message);

	template<typename T>
	static void info(T message);

	template<typename T>
	static void warn(T message);

	template<typename T>
	static void error(T message);
};

template <typename T>
void Log::debug(T message) {
#if IYN_LOG_LEVEL <= IYN_LOG_LEVEL_DBUG
	Serial.print("[IYN_DEBUG]: ");
	Serial.println(message);
#endif
}

template <typename T>
void Log::info(T message) {
#if IYN_LOG_LEVEL <= IYN_LOG_LEVEL_INFO
	Serial.print("[IYN_INFO]: ");
	Serial.println(message);
#endif
}

template <typename T>
void Log::warn(T message) {
#if IYN_LOG_LEVEL <= IYN_LOG_LEVEL_WARN
	Serial.print("[IYN_WARN]: ");
	Serial.println(message);
#endif
}

template <typename T>
void Log::error(T message) {
#if IYN_LOG_LEVEL <= IYN_LOG_LEVEL_ERROR
	Serial.print("[IYN_ERROR]: ");
	Serial.println(message);
#endif
}

#endif /* SRC_MAIN_LOGGING_H_ */
