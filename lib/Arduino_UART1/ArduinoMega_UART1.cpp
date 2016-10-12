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
UART_Typedef	UART1;													// 串口变量
SemaphoreHandle_t UART1_Rx_End_Semaphore;

/* Private function prototypes -----------------------------------------------*/
void UART1_Init(void);                                                  // UART1初始化
void UART1_Rx_Handle_Task(void *pvParameters);							// 串口接收处理任务

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

	UART1.Rx_Data     = (char*)malloc(UART1_RX_BUFFER_SIZE);
	UART1.Rx_En       = true;
	UART1.Rx_Len      = 0;
	UART1_Rx_End_Semaphore = xSemaphoreCreateBinary();

  	Serial1.begin(uiBrud_Rate);

  	Serial1.print("UART1 init With 8 N 1 Brud Rate = ");
  	Serial1.println(uiBrud_Rate);

	// 创建UART接收处理任务
	xTaskCreate(UART1_Rx_Handle_Task,
				(const portCHAR *)"UART1_Rx_Handle_Task" ,  	// 名称
  				128,  						   	// 堆栈
    			NULL,
  				0,     						 	// 优先级 3最高 0最低
				NULL );

}// End of void UART1_Init(u32 uiBrud_Rate)

/*******************************************************************************
*                   陆超@2016-10-10
* Function Name  :  Loop_1s
* Description    :  1s任务
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void UART1_Rx_Handle_Task(void *pvParameters)
{
	for(;;)
	{
		xSemaphoreTake( UART1_Rx_End_Semaphore, ( TickType_t ) portMAX_DELAY );
		UART1.Rx_Data[UART1.Rx_Len] = '\0';
		Serial1.print("串口1收到数据:");
		Serial1.println(UART1.Rx_Data);

		// 串口数据处理
		UART1_RxData_Handle();

		UART1.Rx_Len      = 0;
		UART1.Rx_En       = true;

	}

}// End of void UART1_Rx_Handle_Task(void *pvParameters)

/*******************************************************************************
*                   陆超@2016-10-08
* Function Name  :  UART1_RxData_Handle
* Description    :  串口1接收数据处理
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void UART1_RxData_Handle(void)
{
	if (strstr(UART1.Rx_Data , "RTC:"))
	{
		Serial1.println("接收到配置RTC命令");
		Shell_Set_RTC(UART1.Rx_Data);
	}

}// End of void UART1_RxData_Handle(void)

/*******************************************************************************
*                   陆超@2016-10-09
* Function Name  :  serialEvent1
* Description    :  串口中断处理
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void serialEvent1(void)
{
	char inChar;

    while (Serial1.available())
    {
        // get the new byte:
        inChar = (char)Serial1.read();

		if (UART1.Rx_En == true)
		{
	        // add it to the inputString:
	        UART1.Rx_Data[UART1.Rx_Len++] = inChar;
	        // if the incoming character is a newline, set a flag
	        // so the main loop can do something about it:
	        if ((inChar == '\n') || UART1.Rx_Len >= UART1_RX_BUFFER_SIZE)
	        {
				UART1.Rx_En       = false;

				// 发送信号量
				xSemaphoreGive(UART1_Rx_End_Semaphore);

	        }
		}
    }

}// End of void serialEvent1(void)


/******************* (C) COPYRIGHT 2016 陆超 **************END OF FILE**********/
