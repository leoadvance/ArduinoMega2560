/******************** (C) COPYRIGHT 2016 陆超 ***********************************
* File Name          :  ArduinoMega_GPU_LCD.c
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  10/17/2016
* Description        :  GPU_LCD程序
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "ArduinoMega_RTC.h"
#include "ArduinoMega_UART2.h"
#include "ArduinoMega_GPU_LCD.h"
#include "arduino.h"
#include "ArduinoMega_DHTxx.h"

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void GPU_LCD_Init(void);                                              	// LCD初始化
void GPU_Rx_Callback(char *p_Data, int Len);							// 接收回调函数
void GPU_LCD_Task(void);												// GPU Task

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

	// // 创建任务
	// xTaskCreate(GPU_LCD_Task,
	// 		   (const portCHAR *) "GPU_LCD_Task",
	// 	        128,				// 堆栈
	// 			NULL,
	// 			1,  				// Priority 3最高
    //  			NULL );



	// 清屏 显示第一幅图片
	GPU_LCD.print("CLS(0);");
	GPU_LCD.print("PIC(40,0,1);");
	GPU_LCD.print("\r\n");

	delay(2000);

	// 清屏
	GPU_LCD.print("CLS(0);");

	// 绘制背景界面
	GPU_LCD.print("CLS(0);");
	GPU_LCD.print("BOXF(0,0,159,159,58);");
	GPU_LCD.print("BOXF(160,0,319,159,46);");
	GPU_LCD.print("BOXF(0,160,319,239,20);");
	GPU_LCD.print("SBC(58);");
	GPU_LCD.print("DS32(48,16,'温度',43,0);");
	GPU_LCD.print("SBC(46);");
	GPU_LCD.print("DS32(208,16,'湿度',47,0);");
	GPU_LCD.print("SBC(58);");
	GPU_LCD.print("DS24(128,106,'℃',1,0);");
	GPU_LCD.print("SBC(46);");
	GPU_LCD.print("DS24(288,100,'%',1,0);");
	GPU_LCD.print("\r\n");

}// End of void GPU_LCD_Init(void锛?

/*******************************************************************************
*                   陆超@2016-10-17
* Function Name  :  GPU_Rx_Callback
* Description    :  接收回调函数
* Input          :  uchar *p_Data 收到数据
*					int Len		  长度
* Output         :  None
* Return         :  None
*******************************************************************************/
void GPU_Rx_Callback(char *p_Data, int Len)
{

	DEBUG_UART.println("串口2回调成功！");

}// End of void GPU_Rx_Callback(char *p_Data, int Len)

/*******************************************************************************
*                   陆超@2016-10-17
* Function Name  :  GPU_LCD_Task
* Description    :  GPU任务
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


	// 读取温湿度
	DHTxx_Read(&Temp, &Humi);
	dtostrf(Temp, 3, 2, Temp_Array);
	dtostrf(Humi, 3, 2, Humi_Array);




	// 显示温湿度
	sprintf(Buffer, "SBC(58);LABL(24,32,100,128,'%s',20,1);", Temp_Array);
	GPU_LCD.print(Buffer);

	sprintf(Buffer, "SBC(46);LABL(24,192,100,288,'%s',20,1);", Humi_Array);
	GPU_LCD.print(Buffer);


	// 显示万年历
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




}// End of void GPU_LCD_Task(void）

/******************* (C) COPYRIGHT 2016 陆超 **************END OF FILE**********/
