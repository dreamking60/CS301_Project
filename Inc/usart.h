/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "sys.h"
/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

/* USER CODE BEGIN Private defines */
#define RXBUFFERSIZE   1
#define USART_REC_LEN 1024
extern u8 aRxBuffer[RXBUFFERSIZE];
extern u16 USART_RX_STA;
extern u8 Usart_Success;
extern u8 USART_RX_BUF[USART_REC_LEN];

#define USART2_MAX_RECV_LEN		400
#define USART2_MAX_SEND_LEN		400
#define USART2_RX_EN 			1

extern u8  USART2_RX_BUF[USART2_MAX_RECV_LEN];
extern u8  USART2_TX_BUF[USART2_MAX_SEND_LEN];
extern vu16 USART2_RX_STA;
/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);

/* USER CODE BEGIN Prototypes */
void u2_printf(char* fmt,...);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
