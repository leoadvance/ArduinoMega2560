/******************** (C) COPYRIGHT 2014 陆超 **********************************
* File Name          :  ArduinoMega_SD.h
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  09/18/2016
* Description        :  SD header file
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ARDUINOMEGA_SD_H
#define __ARDUINOMEGA_SD_H

/* Includes ------------------------------------------------------------------*/
#include <SPI.h>
#include <SD.h>

#include "Global.h"



/* Private define ------------------------------------------------------------*/


/* Private typedef -----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
extern  void SDCard_Init(void);                                         // SD卡初始化


#endif /* __ARDUINOMEGA_SD_H */

/******************* (C) COPYRIGHT 2014 陆超 *****END OF FILE******************/
