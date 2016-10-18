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
	GPU_LCD.print("\r\n");

	// 显示温湿度界面
	GPU_LCD.print("DS16(32,48,'温度:',11,0);");
	GPU_LCD.print("DS16(144,50,'℃',11,0);");
	GPU_LCD.print("DS16(32,80,'湿度:',11,0);");
	GPU_LCD.print("DS16(144,82,'%',11,0);");
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
	float Temp, Humi;
	char Temp_Array[8];
	char Humi_Array[8];
	char Buffer[96];


	// 读取温湿度
	DHTxx_Read(&Temp, &Humi);
	dtostrf(Temp, 3, 2, Temp_Array);
	dtostrf(Humi, 3, 2, Humi_Array);

	sprintf(Buffer, "LABL(16,80,50,136,'%s',15,2);", Temp_Array);
	GPU_LCD.print(Buffer);

	sprintf(Buffer, "LABL(16,80,82,136,'%s',15,2);\r\n", Humi_Array);
	GPU_LCD.print(Buffer);



}// End of void GPU_LCD_Task(void）

/******************* (C) COPYRIGHT 2016 陆超 **************END OF FILE**********/
