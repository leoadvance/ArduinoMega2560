/******************** (C) COPYRIGHT 2014 陆超 **********************************
* File Name          :  ArduinoMega_DHTxx.h
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  09/18/2016
* Description        :  DHTxx header file
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ARDUINOMEGA_DHTxx_H
#define __ARDUINOMEGA_DHTxx_H

/* Includes ------------------------------------------------------------------*/
#include "Global.h"
#include "DHT.h"


/* Private define ------------------------------------------------------------*/
#define     DHTxx_DATA_PIN              14                             	// DHTxx卡片选管脚


/* Private typedef -----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
extern  void DHTxx_Init(void);                                    		// DHTxx卡初始化
extern  int DHTxx_Read(float *fTemp, float *fHumi);						// 读取温湿度


#endif /* __ARDUINOMEGA_DHTxx_H */

/******************* (C) COPYRIGHT 2016 陆超 *****END OF FILE******************/
