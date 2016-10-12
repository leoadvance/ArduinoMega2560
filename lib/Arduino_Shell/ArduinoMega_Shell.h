/******************** (C) COPYRIGHT 2016 陆超 **********************************
* File Name          :  ArduinoMega_Shell.h
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  10/12/2016
* Description        :  Shell header file
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ARDUINOMEGA_SHELL_H
#define __ARDUINOMEGA_SHELL_H

/* Includes ------------------------------------------------------------------*/
#include "Global.h"



/* Private define ------------------------------------------------------------*/
#define     SHELL_RTC_HEAD       		"RTC: "                        	// RTC识别头


/* Private typedef -----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
extern	void Shell_Set_RTC(char *p_Data);								// 设置RTC

#endif /* __ARDUINOMEGA_SHELL_H */

/******************* (C) COPYRIGHT 2016 陆超 ***** END OF FILE ****************/
