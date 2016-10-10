/******************** (C) COPYRIGHT 2014 陆超 **********************************
* File Name          :  ArduinoMega_Timer.h
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  10/08/2016
* Description        :  Timer header file
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ARDUINOMEGA_TIMER_H
#define __ARDUINOMEGA_TIMER_H

/* Includes ------------------------------------------------------------------*/
#include "Global.h"



/* Private define ------------------------------------------------------------*/


/* Private typedef -----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
extern  void Timer1_Init(void);                                         // Timer1卡初始化

extern  u32 Get_1ms_TimeBase(void);									    // 获取1ms时间戳
extern  u32 Get_1s_TimeBase(void);									  	// 获取1s时间戳


#endif /* #ifndef __ARDUINOMEGA_TIMER_H */

/******************* (C) COPYRIGHT 2016 陆超 ***** END OF FILE *****************/
