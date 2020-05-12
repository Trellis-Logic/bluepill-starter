/*
 * log.c
 *
 *  Created on: Dec 18, 2018
 *      Author: Dan Walkes
 */

#include "log.h"
#include <stdbool.h>
#include <stdint.h>
#include "usart.h"
#include "retarget.h"


#if INCLUDE_LOGGING

/**
 * @return a timestamp value for the logger, typically based on a free running timer.
 * This will be printed at the beginning of each log message.
 */
uint32_t loggerGetTimestamp(void)
{
	return HAL_GetTick();
}

/**
 * Initialize logging for STM32 parts
 * See https://shawnhymel.com/1873/how-to-use-printf-on-stm32/
 */
void logInit(void)
{
    RetargetInit(&huart2);
	LOG_INFO("Initialized Logging");
}

/**
 * Block for chars to be flushed out of the serial port.
 */
void logFlush(void)
{
}


#endif