/******************** (C) COPYRIGHT 2016 陆超 **********************************
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
#include "ArduinoMega_Shell.h"


/* Private define ------------------------------------------------------------*/
#define     UART1_RX_BUFFER_SIZE       	64                         		// 串口接收大小
#define     UART1_TX_BUFFER_SIZE       	64                         		// 串口发送大小

/* Private typedef -----------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
extern  UART_Typedef	UART1;											// 串口变量

/* Private function prototypes -----------------------------------------------*/
extern  void UART1_Init(u32 uiBrud_Rate);                       		// 串口初始化
extern  void UART1_RxData_Handle(void);									// 串口1接收处理
extern  void UART1_Rx_Handle_Task(void);								//

#endif /* __ARDUINOMEGA_UART1_H */

/******************* (C) COPYRIGHT 2016 陆超 ***** END OF FILE *****************/
