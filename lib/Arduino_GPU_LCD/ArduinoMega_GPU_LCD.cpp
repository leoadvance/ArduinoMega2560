/******************** (C) COPYRIGHT 2016 陆超 ***********************************
* File Name          :  ArduinoMega_GPU_LCD.c
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  10/17/2016
* Description        :  GPU_LCD绋嬪簭
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "ArduinoMega_UART2.h"
#include "ArduinoMega_GPU_LCD.h"
#include "arduino.h"



/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void GPU_LCD_Init(void);                                              	// GPU_LCD鍒濆鍖?
void GPU_Rx_Callback(char *p_Data, int Len);							// 鎺ユ敹鍥炶皟

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
*                   陆超@2016-10-17
* Function Name  :  GPU_LCD_Init
* Description    :  LCD初始化
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void GPU_LCD_Init(void)
{

	UART2_Init(115200, GPU_Rx_Callback);

}// End of void GPU_LCD_Init(void锛?

/*******************************************************************************
*                   陆超@2016-10-17
* Function Name  :  GPU_Rx_Callback
* Description    :  串口2回调函数
* Input          :  uchar *p_Data 收到数据
*					int Len		  长度
* Output         :  None
* Return         :  None
*******************************************************************************/
void GPU_Rx_Callback(char *p_Data, int Len)
{

	GPU_LCD.println("串口2回调成功！");

}// End of void GPU_Rx_Callback(char *p_Data, int Len)


/******************* (C) COPYRIGHT 2016 陆超 **************END OF FILE**********/
