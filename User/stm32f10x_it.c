/**
 ******************************************************************************
 * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c
 * @author  MCD Application Team
 * @version V3.6.0
 * @date    20-September-2021
 * @brief   Main Interrupt Service Routines.
 *          This file provides template for all exceptions handler and
 *          peripherals interrupt service routine.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2011 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "stm32f10x_usart.h"
#include "./uart/bsp_uart.h"
#include <string.h>

/** @addtogroup STM32F10x_StdPeriph_Template
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
 * @brief  This function handles NMI exception.
 * @param  None
 * @retval None
 */
void NMI_Handler(void)
{
}

/**
 * @brief  This function handles Hard Fault exception.
 * @param  None
 * @retval None
 */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
 * @brief  This function handles Memory Manage exception.
 * @param  None
 * @retval None
 */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
 * @brief  This function handles Bus Fault exception.
 * @param  None
 * @retval None
 */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
 * @brief  This function handles Usage Fault exception.
 * @param  None
 * @retval None
 */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
 * @brief  This function handles SVCall exception.
 * @param  None
 * @retval None
 */
void SVC_Handler(void)
{
}

/**
 * @brief  This function handles Debug Monitor exception.
 * @param  None
 * @retval None
 */
void DebugMon_Handler(void)
{
}

/**
 * @brief  This function handles PendSVC exception.
 * @param  None
 * @retval None
 */
void PendSV_Handler(void)
{
}

/**
 * @brief  This function handles SysTick Handler.
 * @param  None
 * @retval None
 */
void SysTick_Handler(void)
{
}

struct receive_stack rx_stack;
void rx_stack_init()
{
  rx_stack.head = 0xAA;                                            //协议栈头，起始位
  rx_stack.addr = 0x01;                                            //从机地址
  memset(rx_stack.recevie_data, 0, sizeof(rx_stack.recevie_data)); //把rx_stack.data[]全部初始化为零
  rx_stack.tail = 0xBB;                                            //协议栈尾，结束位
  rx_stack.head_flag = 0;
  rx_stack.tail_flag = 0;
  rx_stack.finish_flag = 0;
  rx_stack.data_pt = 0;
}

void CommClr(void)
{
  rx_stack.head_flag = 0;
  rx_stack.tail_flag = 0;
  rx_stack.finish_flag = 0;
  rx_stack.data_pt = 0;

  memset(rx_stack.recevie_data, 0, sizeof(rx_stack.recevie_data)); //把rx_stack.data[]全部初始化为零
  rx_stack.commPack_OK_flag = 0;
}

// 中断服务函数
void DEBUG_USART_IRQHandler(void)
{
  uint8_t ucTemp;
  if (USART_GetITStatus(DEBUG_USARTx, USART_IT_RXNE) != RESET) //接收中断
  {
    ucTemp = USART_ReceiveData(DEBUG_USARTx); //读取接收到的数据
    Usart_SendByte(DEBUG_USARTx,ucTemp);
    if (rx_stack.head_flag == 1)              //帧头
    {
      if (ucTemp == 0xBB) //判断当前数据是否为帧尾
      {
        rx_stack.finish_flag = 1;
        rx_stack.tail_flag = 1;
        rx_stack.head_flag = 0;
      }
      else
      {
        rx_stack.recevie_data[rx_stack.data_pt] = ucTemp;
        rx_stack.data_pt++;
        if (rx_stack.data_pt > 9)
        {
          rx_stack.data_pt = 0;
        }
      }
    }
    else //没有接收到帧头
    {
      if (ucTemp == rx_stack.head)
        rx_stack.head_flag = 1;
      else
      {
        CommClr();
        return;
      }
    }
  }
  USART_ClearITPendingBit(DEBUG_USARTx, USART_IT_RXNE); //清除接收中断标志
}


/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
 * @brief  This function handles PPP interrupt request.
 * @param  None
 * @retval None
 */
/*void PPP_IRQHandler(void)
{
}*/

/**
 * @}
 */
