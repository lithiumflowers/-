#ifndef _BSP_UART_H
#define _BSP_UART_H

#include "stm32f10x.h"
#include <stdio.h>

// 串口宏定义，不同的串口挂载的总线不一样，移植时需要修改这几个宏
#define DEBUG_USARTx USART1
#define DEBUG_USART_CLK RCC_APB2Periph_USART1
#define DEBUG_USART_APBxClkCmd RCC_APB2PeriphClockCmd
#define DEBUG_USART_BAUDRATE 115200

// USART GPIO 引脚宏定义
#define DEBUG_USART_GPIO_CLK (RCC_APB2Periph_GPIOA)
#define DEBUG_USART_GPIO_APBxClkCmd RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PORT GPIOA
#define DEBUG_USART_TX_GPIO_PIN GPIO_Pin_9
#define DEBUG_USART_RX_GPIO_PORT GPIOA
#define DEBUG_USART_RX_GPIO_PIN GPIO_Pin_10

#define DEBUG_USART_IRQ USART1_IRQn
#define DEBUG_USART_IRQHandler USART1_IRQHandler

struct receive_stack
{
  u8 head;             //帧头
  u8 addr;             //从机地址
  u8 recevie_data[10]; //数据
  u8 check;            //校验
  u8 tail;             //帧尾
  u8 head_flag;        //接收到帧头标志位
  u8 tail_flag;        //接收到帧尾标志位
  u8 finish_flag;      //接收完成标志位
  u8 data_pt;          //已接收的字节数
  u8 commPack_OK_flag; //数据解包完成标志
};
extern struct receive_stack rx_stack;

void DEBUG_UART_Config(void);
void Usart_SendByte(USART_TypeDef *pUSARTx, uint8_t ch);
void Usart_SendString(USART_TypeDef *pUSARTx, char *str);
void rx_stack_init(void);
void CommClr(void);

#endif /* _BSP_UART_H */
