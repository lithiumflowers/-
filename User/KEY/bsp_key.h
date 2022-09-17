#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "stm32f10x.h"

#define KEY_ON                 1
#define KEY_OFF                0

#define KEY0_GPIO_LCK          RCC_APB2Periph_GPIOC
#define KEY0_GPIO_PORT         GPIOC
#define KEY0_GPIO_PIN          GPIO_Pin_5

#define KEY1_GPIO_LCK          RCC_APB2Periph_GPIOA
#define KEY1_GPIO_PORT         GPIOA
#define KEY1_GPIO_PIN          GPIO_Pin_15

void GPIO_KEY_Config();
uint8_t KEY_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif /* _BSP_KEY_H */