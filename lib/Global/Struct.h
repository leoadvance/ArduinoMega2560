/******************** (C) COPYRIGHT 2016 陆超 ***********************************
* File Name          :  Struct.h
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  08/08/2014
* Description        :  结构体定义
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STRUCT_H
#define __STRUCT_H

/* Includes ------------------------------------------------------------------*/
#include "Global_Cfg.h"
#include "arduino.h"



/* Private define ------------------------------------------------------------*/



/* Private typedef -----------------------------------------------------------*/
typedef struct
{
    char *      		Rx_Data;                                       	// 接收数据
	unsigned short		Rx_Len;											// 接收数据长度
    boolean 			Rx_Complete;									// 接收完毕
	boolean 			Rx_En;											// 接收允许


} UART_Typedef;

/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/

#endif /* __STRUCT_H */

/******************* (C) COPYRIGHT 2016 陆超 **************END OF FILE**********/
