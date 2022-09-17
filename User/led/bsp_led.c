#include "./led/bsp_led.h"

void LED_GPIO_Config(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//打开外设时钟
	RCC_APB2PeriphClockCmd(LED1_GPIO_LCK | LED2_GPIO_LCK,ENABLE);
	
	//配置外设初始化
	GPIO_InitStruct.GPIO_Pin = LED2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	
	//调用外设初始化函数
	GPIO_Init(LED2_GPIO_PORT,&GPIO_InitStruct);
	
  //LED1
	
	GPIO_InitStruct.GPIO_Pin = LED1_GPIO_PIN;
	
	GPIO_Init(LED1_GPIO_PORT,&GPIO_InitStruct);
	
		/* 关闭所有led灯	*/
	GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
		
		/* 关闭所有led灯	*/
	GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
}