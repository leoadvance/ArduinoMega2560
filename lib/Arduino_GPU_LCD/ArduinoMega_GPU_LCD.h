/******************** (C) COPYRIGHT 2016 ½�� **********************************
* File Name          :  ArduinoMega_GPU_LCD.h
* Author             :  ½��
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  10/17/2016
* Description        :  GPU_LCD header file
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ARDUINOMEGA_GPU_LCD_H
#define __ARDUINOMEGA_GPU_LCD_H

/* Includes ------------------------------------------------------------------*/
#include "Global.h"


/* Private define ------------------------------------------------------------*/
#define     GPU_LCD                  	Serial2                         // ��������ӿ�


/* Private typedef -----------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
extern  void GPU_LCD_Init(void);                       					// GPU LCD��ʼ��
extern  void GPU_LCD_Task(void);										// GPU Task

#endif /* __ARDUINOMEGA_GPU_LCD_H */

/******************* (C) COPYRIGHT 2016 ½�� ***** END OF FILE *****************/
