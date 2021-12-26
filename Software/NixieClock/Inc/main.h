/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2019 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LedRed_Pin GPIO_PIN_13
#define LedRed_GPIO_Port GPIOC
#define LedBlue_Pin GPIO_PIN_14
#define LedBlue_GPIO_Port GPIOC
#define LedGreen_Pin GPIO_PIN_15
#define LedGreen_GPIO_Port GPIOC
#define Buzzer_Pin GPIO_PIN_0
#define Buzzer_GPIO_Port GPIOA
#define Alarm_Pin GPIO_PIN_1
#define Alarm_GPIO_Port GPIOA
#define Alarm_EXTI_IRQn EXTI1_IRQn
#define BL_Pin GPIO_PIN_2
#define BL_GPIO_Port GPIOA
#define B1_Pin GPIO_PIN_3
#define B1_GPIO_Port GPIOA
#define B2_Pin GPIO_PIN_4
#define B2_GPIO_Port GPIOA
#define B3_Pin GPIO_PIN_5
#define B3_GPIO_Port GPIOA
#define Nixie_1_Pin GPIO_PIN_6
#define Nixie_1_GPIO_Port GPIOA
#define NixieCrl_P_Pin GPIO_PIN_7
#define NixieCrl_P_GPIO_Port GPIOA
#define Nixie_DP_Pin GPIO_PIN_0
#define Nixie_DP_GPIO_Port GPIOB
#define Nixie_LP_Pin GPIO_PIN_1
#define Nixie_LP_GPIO_Port GPIOB
#define BOOT1_Pin GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB
#define Nixie_2_Pin GPIO_PIN_12
#define Nixie_2_GPIO_Port GPIOB
#define Nixie_3_Pin GPIO_PIN_13
#define Nixie_3_GPIO_Port GPIOB
#define Nixie_4_Pin GPIO_PIN_14
#define Nixie_4_GPIO_Port GPIOB
#define Nixie_5_Pin GPIO_PIN_15
#define Nixie_5_GPIO_Port GPIOB
#define Nixie_6_Pin GPIO_PIN_8
#define Nixie_6_GPIO_Port GPIOA
#define Nixie_7_Pin GPIO_PIN_9
#define Nixie_7_GPIO_Port GPIOA
#define Nixie_0_Pin GPIO_PIN_10
#define Nixie_0_GPIO_Port GPIOA
#define Nixie_9_Pin GPIO_PIN_11
#define Nixie_9_GPIO_Port GPIOA
#define Nixie_8_Pin GPIO_PIN_12
#define Nixie_8_GPIO_Port GPIOA
#define NixieCrl_0_Pin GPIO_PIN_15
#define NixieCrl_0_GPIO_Port GPIOA
#define NixieCrl_1_Pin GPIO_PIN_3
#define NixieCrl_1_GPIO_Port GPIOB
#define NixieCrl_2_Pin GPIO_PIN_4
#define NixieCrl_2_GPIO_Port GPIOB
#define NixieCrl_3_Pin GPIO_PIN_5
#define NixieCrl_3_GPIO_Port GPIOB
#define NixieCrl_4_Pin GPIO_PIN_6
#define NixieCrl_4_GPIO_Port GPIOB
#define NixieCrl_5_Pin GPIO_PIN_7
#define NixieCrl_5_GPIO_Port GPIOB
#define SENSOR_Pin GPIO_PIN_8
#define SENSOR_GPIO_Port GPIOB
#define BOARD_SEL_Pin GPIO_PIN_9
#define BOARD_SEL_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
