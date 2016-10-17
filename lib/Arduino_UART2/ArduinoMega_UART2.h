/******************** (C) COPYRIGHT 2014 陆超 **********************************
* File Name          :  ArduinoMega_UART2.h
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  09/18/2016
* Description        :  UART2 header file
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ARDUINOMEGA_UART2_H
#define __ARDUINOMEGA_UART2_H

/* Includes ------------------------------------------------------------------*/
#include "Global.h"
#include "ArduinoMega_Shell.h"


/* Private define ------------------------------------------------------------*/
#define     UART2_RX_BUFFER_SIZE       	64                         		// 串口接收大小
#define     UART2_TX_BUFFER_SIZE       	64                         		// 串口发送大小

/* Private typedef -----------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
extern  UART_Typedef	UART2;											// 串口变量

/* Private function prototypes -----------------------------------------------*/
extern  void UART2_Init(u32 uiBrud_Rate);                       		// 串口初始化
extern  void UART2_RxData_Handle(void);									// 串口1接收处理
extern  void UART2_Rx_Handle_Task(void);								//

#endif /* __ARDUINOMEGA_UART2_H */

/******************* (C) COPYRIGHT 2016 陆超 ***** END OF FILE *****************/
