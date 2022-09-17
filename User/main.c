#include "stm32f10x.h"
#include "./led/bsp_led.h"
#include "./uart/bsp_uart.h"
#include <string.h>

void delay(uint32_t count)
{
	for (; count != 0; count--);
}

int main()
{

	LED_GPIO_Config();
	DEBUG_UART_Config();
	while (1)
	{

		if (rx_stack.finish_flag == 1) //数据接收完成
		{
			switch (rx_stack.recevie_data[1])
			{
			case 0x00:
				LED1_ON;
				break;
			case 0x01:
			    LED2_ON;
			    break;
			default:
			    LED1_OFF;
				LED2_OFF;
				break;
			}
			rx_stack_init();
		}
	}
}
