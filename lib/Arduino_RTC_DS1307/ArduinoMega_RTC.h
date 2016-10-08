/******************** (C) COPYRIGHT 2014 陆超 **********************************
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
#include "Wire.h"
#include "DS1307.h"

#include "Global.h"



/* Private define ------------------------------------------------------------*/


/* Private typedef -----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
extern  void RTC_Init(void);                                            // RTC卡初始化
extern  void RTC_Print_Time(void);                                      // 打印当前时间


#endif /* __ARDUINOMEGA_RTC_H */

/******************* (C) COPYRIGHT 2014 陆超 *****END OF FILE******************/
