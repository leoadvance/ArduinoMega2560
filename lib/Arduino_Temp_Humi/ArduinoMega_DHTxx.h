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
#define 	DHTPIN            			49        						// HTxx卡片选管脚

#define 	DHTTYPE           			DHT11     						// DHT 11
// #define 	DHTTYPE           			DHT22     						// DHT 22 (AM2302)
// #define 	DHTTYPE           			DHT21     						// DHT 21 (AM2301)

/* Private typedef -----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
extern  void DHTxx_Init(void);                                    		// DHTxx卡初始化
extern  int DHTxx_Read(float *fTemp, float *fHumi);						// 读取温湿度


#endif /* __ARDUINOMEGA_DHTxx_H */

/******************* (C) COPYRIGHT 2016 陆超 *****END OF FILE******************/
