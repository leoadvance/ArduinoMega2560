/******************** (C) COPYRIGHT 2016 陆超 ***********************************
* File Name          :  ArduinoMega_UART1.c
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  09/18/2016
* Description        :  串口程序
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "ArduinoMega_UART1.h"
#include "arduino.h"

/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
void UART1_Init(void);                                                  // UART1初始化

    
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
*                   陆超@2016-09-18
* Function Name  :  UART1_Init
* Description    :  串口初始化
* Input          :  u32 uiBrud_Rate 波特率
* Output         :  None
* Return         :  None
*******************************************************************************/
void UART1_Init(u32 uiBrud_Rate)
{

  Serial1.begin(uiBrud_Rate);

  Serial1.print("UART1 init With 8 N 1 Brud Rate = ");
  Serial1.println(uiBrud_Rate);

}// End of void UART1_Init(u32 uiBrud_Rate)




/******************* (C) COPYRIGHT 2016 陆超 **************END OF FILE**********/
