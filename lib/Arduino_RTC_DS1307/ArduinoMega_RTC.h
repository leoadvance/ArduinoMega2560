/******************** (C) COPYRIGHT 2016 陆超 **********************************
* File Name          :  ArduinoMega_RTC.h
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  10/08/2016
* Description        :  RTC header file
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ARDUINOMEGA_RTC_H
#define __ARDUINOMEGA_RTC_H

/* Includes ------------------------------------------------------------------*/
#include "Global.h"
#include "Wire.h"
#include "DS1307.h"


/* Private define ------------------------------------------------------------*/


/* Private typedef -----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
extern	DS1307 RTC_Clock;                                             	// 声明一个时钟类

/* Private function prototypes -----------------------------------------------*/
extern  void RTC_Init(void);                                            // RTC卡初始化
extern  void RTC_Print_Time(void);                                      // 打印当前时间
extern  void RTC_Set_Time(u16 usYear, u8 ucMonth, u8 ucDay, u8 ucHour, u8 ucminute, u8 ucSecond, u8 ucWeekday);

#endif /* __ARDUINOMEGA_RTC_H */

/******************* (C) COPYRIGHT 2016 陆超 *****END OF FILE******************/
