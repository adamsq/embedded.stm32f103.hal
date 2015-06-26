/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F103_BOARD_H
#define __STM32F103_BOARD_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
   
/** LED Constants
  * @{
  */

#define LED_GPIO_PORT                   GPIOA
#define LED_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOA_CLK_ENABLE()  
#define LED_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOA_CLK_DISABLE()  

#ifdef __cplusplus
}
#endif

#endif

