#include "./KEY/bsp_key.h"

void GPIO_KEY_Config(){
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//打开外设时钟
  RCC_APB2PeriphClockCmd(KEY0_GPIO_LCK | KEY1_GPIO_LCK,ENABLE);

	//配置外设结构体
	GPIO_InitStruct.GPIO_Pin = KEY0_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(KEY0_GPIO_PORT,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN;
	GPIO_Init(KEY1_GPIO_PORT,&GPIO_InitStruct);

}

uint8_t KEY_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	if( GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON ){
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON)
			return KEY_ON;
	}
	else return KEY_OFF;
}
