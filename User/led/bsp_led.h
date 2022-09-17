#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f10x.h"

#define LED1_GPIO_LCK          RCC_APB2Periph_GPIOA
#define LED1_GPIO_PORT         GPIOA
#define LED1_GPIO_PIN          GPIO_Pin_8

#define LED2_GPIO_LCK          RCC_APB2Periph_GPIOD
#define LED2_GPIO_PORT         GPIOD
#define LED2_GPIO_PIN          GPIO_Pin_2

#define digitalTOGGLE(p,i)     {p->ODR ^= i;}
#define LED1_TOGGLE            digitalTOGGLE(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED2_TOGGLE            digitalTOGGLE(LED2_GPIO_PORT,LED2_GPIO_PIN)

/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //输出为高电平		
#define digitalLo(p,i)		 {p->BRR=i;}	 //输出低电平
#define digitalToggle(p,i) {p->ODR ^=i;} //输出反转状态


/* 定义控制IO的宏 */
#define LED1_OFF		   digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON			   digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2_OFF		   digitalHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_ON			   digitalLo(LED2_GPIO_PORT,LED2_GPIO_PIN)

void LED_GPIO_Config(void);

#endif /*_BSP_LED_H*/