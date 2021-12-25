/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "sys.h"
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
#define KEY0_Value        HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_5)  //KEY0
#define KEY1_Value        HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15) //KEY1
#define WK_UP_Value       HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)  //WKUP

#define KEY0_PRES	1		//KEY0
#define KEY1_PRES	2		//KEY1
#define WKUP_PRES	3		//WK_UP
#define LED0_Value PAout(8)	// PA8
#define LED1_Value PDout(2)	// PD2
/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
u8 KEY_Scan(u8 mode);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
