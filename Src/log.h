/*
 * log.h
 *
 *  Created on: Dec 18, 2018
 *      Author: Dan Walkes
 */

#ifndef LOG_H_
#define LOG_H_
#include "stdio.h"
#include <inttypes.h>

/**
 * Instructions for using this module:
 * 1) #include "log.h" in the C file where you'd like to add logging
 * 2) Reference macros LOG_XXX to log at specific thresholds.  Use printf style argument
 *    lists with each macro to support printing variables.
 *    * ERROR for unexpected conditions which should never occur.
 *    * WARN for potential issues which may occur
 *    * INFO for infrequent status updates
 *    * DEBUG for detailed updates, useful when troubleshooting a specific
 *        code path
 *  3) Call logInit() once in the main init routine, before any logging is attempted and after any timing capability for
 *  loggerGetTimestamp() is complete.
 *  All logging is off by default (compiled out of the build) if you #define INCLUDE_LOGGING 0
 *   * In any build which should not include logging, you can define INCLUDE_LOGGING 0 or change the default below
 *  Even after turning logging on with INCLUDE_LOGGING, debug logging is off by default.
 *   * To turn debug logging on for a specific .c file, #define INCLUDE_LOG_DEBUG 1 at the top of the file
 *       before the #include "log.h" reference.
 *   * To turn on for all files #define INCLUDE_LOG_DEBUG 1 in the project configuration.
 */

#ifndef INCLUDE_LOGGING
#define INCLUDE_LOGGING 1
#endif

#ifndef LOG_ERROR
#define LOG_ERROR(message,...) \
	LOG_DO(message,"Error", ##__VA_ARGS__)
#endif

#ifndef LOG_WARN
#define LOG_WARN(message,...) \
	LOG_DO(message,"Warn ", ##__VA_ARGS__)
#endif

#ifndef LOG_INFO
#define LOG_INFO(message,...) \
	LOG_DO(message,"Info ", ##__VA_ARGS__)
#endif

#if INCLUDE_LOG_DEBUG
#ifndef LOG_DEBUG
#define LOG_DEBUG(message,...) \
	LOG_DO(message,"Debug",##__VA_ARGS__)
#define LOG_DEBUG_CODE(code) code
#endif
#else
#define LOG_DEBUG(message,...)
#define LOG_DEBUG_CODE(code)
#endif


#if INCLUDE_LOGGING
#define LOG_DO(message,level, ...) \
	printf( "%5"PRIu32":%s:%s: " message "\n", loggerGetTimestamp(), level, __func__, ##__VA_ARGS__ )
void logInit();
uint32_t loggerGetTimestamp();
void logFlush();
#else
/**
 * Remove all logging related code on builds where logging is not enabled
 */
#define LOG_DO(message,level, ...)
static inline void logInit() {}
static inline void logFlush() {}
#endif


#endif /* LOG_H_ */