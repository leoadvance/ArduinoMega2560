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
void GPU_LCD_Task(void *pvParameters);									// GPU Task

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

	// 创建任务
	xTaskCreate(GPU_LCD_Task,
			   (const portCHAR *) "GPU_LCD_Task",
		        128,				// 堆栈
				NULL,
				1,  				// Priority 3最高
     			NULL );




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

	GPU_LCD.println("串口2回调成功！");

}// End of void GPU_Rx_Callback(char *p_Data, int Len)

/*******************************************************************************
*                   陆超@2016-10-17
* Function Name  :  GPU_LCD_Task
* Description    :  GPU任务
* Input          :  void *pvParameters 启动传参
* Output         :  None
* Return         :  None
*******************************************************************************/
void GPU_LCD_Task(void *pvParameters)
{
	float Temp, Humi;
	char Temp_Array[8];
	char Humi_Array[8];

	// 清屏 显示第一幅图片
	GPU_LCD.print("CLS(0);");
	GPU_LCD.print("PIC(40,0,1);");
	GPU_LCD.print("\r\n");

	// 延时
	vTaskDelay( 2000 / portTICK_PERIOD_MS );

	// 清屏
	GPU_LCD.print("CLS(0);");
	GPU_LCD.print("\r\n");

	// 显示温湿度界面
	GPU_LCD.print("DS16(32,48,'温度:',11,0);");
	GPU_LCD.print("DS16(128,50,'℃',11,0);");
	GPU_LCD.print("DS16(32,80,'湿度:',11,0);");
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

}// End of void GPU_LCD_Task( void *pvParameters ）

/******************* (C) COPYRIGHT 2016 陆超 **************END OF FILE**********/
