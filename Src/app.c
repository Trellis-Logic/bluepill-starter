#include "main.h" // gpio definitions from CubeMX
#include "stm32f1xx_hal_gpio.h"

void app_main(void)
{
    unsigned int i=0;
    const unsigned int delay_time = 10000;
    while (1) {
        HAL_GPIO_TogglePin(UserLED_GPIO_Port,UserLED_Pin);
        for( i=0; i< delay_time; i++ ) { }
    }


}