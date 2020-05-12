#include "main.h" // gpio definitions from CubeMX
#include "stm32f1xx_hal_gpio.h"
#include "log.h"
#include <stdbool.h>

void app_main(void)
{
    unsigned int i=0;
    const unsigned int delay_time = 1000000;
    logInit();
    bool is_set = false;

    while (1) {
        if( is_set ) {
            HAL_GPIO_WritePin(UserLED_GPIO_Port,UserLED_Pin,GPIO_PIN_RESET);
        } else {
            HAL_GPIO_WritePin(UserLED_GPIO_Port,UserLED_Pin,GPIO_PIN_SET);
        }
        is_set = !is_set;
        LOG_INFO("Toggled GPIO, new state is %s",is_set ? "set" : "reset");
        if( (is_set && (HAL_GPIO_ReadPin(UserLED_GPIO_Port,UserLED_Pin) == GPIO_PIN_RESET)) ||
            (!is_set && (HAL_GPIO_ReadPin(UserLED_GPIO_Port,UserLED_Pin) == GPIO_PIN_SET)) ){
                LOG_WARN("Unexpected mismatch in pin setting, expected %s, found %s",
                                is_set ? "set" : "reset",
                                is_set ? "set" : "reset");
        }

        for( i=0; i< delay_time; i++ ) { }
    }


}