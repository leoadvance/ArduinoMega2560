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
#include "ArduinoMega_DHTxx.h"

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void GPU_LCD_Init(void);                                              	// LCD��ʼ��
void GPU_Rx_Callback(char *p_Data, int Len);							// ���ջص�����
void GPU_LCD_Task(void *pvParameters);									// GPU Task

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

	// ��������
	xTaskCreate(GPU_LCD_Task,
			   (const portCHAR *) "GPU_LCD_Task",
		        128,				// ��ջ
				NULL,
				1,  				// Priority 3���
     			NULL );




}// End of void GPU_LCD_Init(void�?

/*******************************************************************************
*                   ½��@2016-10-17
* Function Name  :  GPU_Rx_Callback
* Description    :  ���ջص�����
* Input          :  uchar *p_Data �յ�����
*					int Len		  ����
* Output         :  None
* Return         :  None
*******************************************************************************/
void GPU_Rx_Callback(char *p_Data, int Len)
{

	GPU_LCD.println("����2�ص��ɹ���");

}// End of void GPU_Rx_Callback(char *p_Data, int Len)

/*******************************************************************************
*                   ½��@2016-10-17
* Function Name  :  GPU_LCD_Task
* Description    :  GPU����
* Input          :  void *pvParameters ��������
* Output         :  None
* Return         :  None
*******************************************************************************/
void GPU_LCD_Task(void *pvParameters)
{
	float Temp, Humi;
	char Temp_Array[8];
	char Humi_Array[8];

	// ���� ��ʾ��һ��ͼƬ
	GPU_LCD.print("CLS(0);");
	GPU_LCD.print("PIC(40,0,1);");
	GPU_LCD.print("\r\n");

	// ��ʱ
	vTaskDelay( 2000 / portTICK_PERIOD_MS );

	// ����
	GPU_LCD.print("CLS(0);");
	GPU_LCD.print("\r\n");

	// ��ʾ��ʪ�Ƚ���
	GPU_LCD.print("DS16(32,48,'�¶�:',11,0);");
	GPU_LCD.print("DS16(128,50,'��',11,0);");
	GPU_LCD.print("DS16(32,80,'ʪ��:',11,0);");
	GPU_LCD.print("DS16(128,82,'%',11,0);");
	GPU_LCD.print("\r\n");

	for (;;)
	{
		DHTxx_Read(&Temp, &Humi);
		sprintf(Temp_Array, "%02f", (double)Temp);
		GPU_LCD.print("BS16(80,50,128,4,Temp_Array,1);");
		GPU_LCD.print("\r\n");
		vTaskDelay( 1000 / portTICK_PERIOD_MS );

	}

}// End of void GPU_LCD_Task( void *pvParameters ��

/******************* (C) COPYRIGHT 2016 ½�� **************END OF FILE**********/
