/******************** (C) COPYRIGHT 2016 ½�� ***********************************
* File Name          :  ArduinoMega_GPU_LCD.c
* Author             :  ½��
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  10/17/2016
* Description        :  GPU_LCD����
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "ArduinoMega_RTC.h"
#include "ArduinoMega_UART2.h"
#include "ArduinoMega_GPU_LCD.h"
#include "arduino.h"
#include "ArduinoMega_DHTxx.h"

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void GPU_LCD_Init(void);                                              	// LCD��ʼ��
void GPU_Rx_Callback(char *p_Data, int Len);							// ���ջص�����
void GPU_LCD_Task(void);												// GPU Task

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

	// // ��������
	// xTaskCreate(GPU_LCD_Task,
	// 		   (const portCHAR *) "GPU_LCD_Task",
	// 	        128,				// ��ջ
	// 			NULL,
	// 			1,  				// Priority 3���
    //  			NULL );



	// ���� ��ʾ��һ��ͼƬ
	GPU_LCD.print("CLS(0);");
	GPU_LCD.print("PIC(40,0,1);");
	GPU_LCD.print("\r\n");

	delay(2000);

	// ����
	GPU_LCD.print("CLS(0);");

	// ���Ʊ�������
	GPU_LCD.print("CLS(0);");
	GPU_LCD.print("BOXF(0,0,159,159,58);");
	GPU_LCD.print("BOXF(160,0,319,159,46);");
	GPU_LCD.print("BOXF(0,160,319,239,20);");
	GPU_LCD.print("SBC(58);");
	GPU_LCD.print("DS32(48,16,'�¶�',43,0);");
	GPU_LCD.print("SBC(46);");
	GPU_LCD.print("DS32(208,16,'ʪ��',47,0);");
	GPU_LCD.print("SBC(58);");
	GPU_LCD.print("DS24(128,106,'��',1,0);");
	GPU_LCD.print("SBC(46);");
	GPU_LCD.print("DS24(288,100,'%',1,0);");
	GPU_LCD.print("\r\n");

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

	DEBUG_UART.println("����2�ص��ɹ���");

}// End of void GPU_Rx_Callback(char *p_Data, int Len)

/*******************************************************************************
*                   ½��@2016-10-17
* Function Name  :  GPU_LCD_Task
* Description    :  GPU����
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void GPU_LCD_Task(void)
{
	static char i = 0;
	float Temp, Humi;
	char Temp_Array[8];
	char Humi_Array[8];
	char Buffer[96];


	// ��ȡ��ʪ��
	DHTxx_Read(&Temp, &Humi);
	dtostrf(Temp, 3, 2, Temp_Array);
	dtostrf(Humi, 3, 2, Humi_Array);




	// ��ʾ��ʪ��
	sprintf(Buffer, "SBC(58);LABL(24,32,100,128,'%s',20,1);", Temp_Array);
	GPU_LCD.print(Buffer);

	sprintf(Buffer, "SBC(46);LABL(24,192,100,288,'%s',20,1);", Humi_Array);
	GPU_LCD.print(Buffer);


	// ��ʾ������
	RTC_Clock.getTime();
	GPU_LCD.print("SBC(20);");
	sprintf(Buffer, "LABL(24,0,168,319,'%04d/%02d/%02d',22,1);",
										RTC_Clock.year + 2000,
							   			RTC_Clock.month,
						       			RTC_Clock.dayOfMonth);
	GPU_LCD.print(Buffer);
	if (i)
	{
		i = 0;
		sprintf(Buffer, "LABL(24,0,204,319,'%02d:%02d:%02d',22,1);",
											RTC_Clock.hour,
											RTC_Clock.minute,
											RTC_Clock.second);
	}
	else
	{
		i = 1;
		sprintf(Buffer, "LABL(24,0,204,319,'%02d %02d %02d',22,1);",
											RTC_Clock.hour,
											RTC_Clock.minute,
											RTC_Clock.second);
	}

	GPU_LCD.print(Buffer);
	GPU_LCD.print("\r\n");




}// End of void GPU_LCD_Task(void��

/******************* (C) COPYRIGHT 2016 ½�� **************END OF FILE**********/
