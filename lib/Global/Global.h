/******************** (C) COPYRIGHT 2016 陆超 **********************************
* File Name          :  Global.h
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  MDK 4.72
* Version            :  V1.0
* Date               :  08/08/2014
* Description        :  Global header file
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GLOBAL_H
#define __GLOBAL_H
/* Includes ------------------------------------------------------------------*/
#include "Global_Cfg.h"
#include "Struct.h"

/* Private define ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/



/* Private variables ---------------------------------------------------------*/
//----------------------- System ----------------------------------------------/
extern  u8                      Sys_Memory_Usage;                       // 内存使用率
extern  u32						Sys_1ms_TimeBase;						// 1ms时间基准
extern  u32						Sys_1s_TimeBase;						// 1s时间基准

#endif /* __GLOBAL_H */

/******************* (C) COPYRIGHT 2016 陆超 ********END OF FILE***************/
