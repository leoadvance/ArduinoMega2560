/******************** (C) COPYRIGHT 2014 陆超 **********************************
* File Name          :  ArduinoMega_UART1.h
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  09/18/2016
* Description        :  UART1 header file
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ARDUINOMEGA_UART1_H
#define __ARDUINOMEGA_UART1_H

/* Includes ------------------------------------------------------------------*/
#include "Global.h"



/* Private define ------------------------------------------------------------*/


/* Private typedef -----------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
extern  UART_Typedef	UART1;											// 串口变量

/* Private function prototypes -----------------------------------------------*/
extern  void UART1_Init(u32 uiBrud_Rate);                       		// 串口初始化
extern  void UART1_RxData_Handle(void);									// 串口1接收处理

#endif /* __ARDUINOMEGA_UART1_H */

/******************* (C) COPYRIGHT 2016 陆超 *****END OF FILE******************/
