/******************** (C) COPYRIGHT 2016 ½�� ***********************************
* File Name          :  ArduinoMega_GPU_LCD.c
* Author             :  ½��
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  10/17/2016
* Description        :  GPU_LCD程序
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "ArduinoMega_UART2.h"
#include "ArduinoMega_GPU_LCD.h"
#include "arduino.h"



/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void GPU_LCD_Init(void);                                              	// GPU_LCD初始�?
void GPU_Rx_Callback(char *p_Data, int Len);							// 接收回调

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
*                   ½��@2016-10-17
* Function Name  :  GPU_LCD_Init
* Description    :  LCD��ʼ��
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void GPU_LCD_Init(void)
{

	UART2_Init(115200, GPU_Rx_Callback);

}// End of void GPU_LCD_Init(void�?

/*******************************************************************************
*                   ½��@2016-10-17
* Function Name  :  GPU_Rx_Callback
* Description    :  ����2�ص�����
* Input          :  uchar *p_Data �յ�����
*					int Len		  ����
* Output         :  None
* Return         :  None
*******************************************************************************/
void GPU_Rx_Callback(char *p_Data, int Len)
{

	GPU_LCD.println("����2�ص��ɹ���");

}// End of void GPU_Rx_Callback(char *p_Data, int Len)


/******************* (C) COPYRIGHT 2016 ½�� **************END OF FILE**********/
