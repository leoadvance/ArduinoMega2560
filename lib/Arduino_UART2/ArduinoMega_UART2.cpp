/******************** (C) COPYRIGHT 2016 陆超 ***********************************
* File Name          :  ArduinoMega_UART2.c
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  09/18/2016
* Description        :  串口程序
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "ArduinoMega_UART2.h"
#include "arduino.h"


/* Private variables ---------------------------------------------------------*/
UART_Typedef	UART2;													// 串口变量
UART2_RxData_Callback RxData_Callback;
/* Private function prototypes -----------------------------------------------*/
void UART2_Init(u32 uiBrud_Rate, UART2_RxData_Callback Fun_Callback); 	// 串口初始化                                                 // UART2初始化
void UART2_Rx_Handle_Task(void *pvParameters);							// 串口接收处理任务
void UART2_Rx_Finish_Judge(void);										// 串口接收完成判断

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
*                   陆超@2016-10-17
* Function Name  :  UART2_Init
* Description    :  串口初始化
* Input          :  u32 uiBrud_Rate 波特率
*					UART2_RxData_Callback Fun_Callback 回调函数
* Output         :  None
* Return         :  None
*******************************************************************************/
void UART2_Init(u32 uiBrud_Rate, UART2_RxData_Callback Fun_Callback)
{

	UART2.Rx_Data      = (char*)malloc(UART2_RX_BUFFER_SIZE);
	UART2.Tx_Data      = (char*)malloc(UART2_TX_BUFFER_SIZE);
	UART2.Rx_En        = true;
	UART2.Rx_Len       = 0;
	UART2.Tx_Len       = 0;
	UART2.Rx_Complete  = false;
	UART2.Rx_Timestamp = 0;

	RxData_Callback = Fun_Callback;

  	Serial2.begin(uiBrud_Rate);
  	Serial2.print("UART2 init With 8 N 1 Brud Rate = ");
  	Serial2.println(uiBrud_Rate);

}// End of void UART2_Init(u32 uiBrud_Rate, UART2_RxData_Callback Fun_Callback)

/*******************************************************************************
*                   陆超@2016-10-10
* Function Name  :  Loop_1s
* Description    :  1s任务
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void UART2_Rx_Handle_Task(void)
{




}// End of void UART2_Rx_Handle_Task(void)

/*******************************************************************************
*                   陆超@2016-10-08
* Function Name  :  UART2_RxData_Handle
* Description    :  串口1接收数据处理
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void UART2_RxData_Handle(void)
{
	// Serial2.print("UART2 RX Len = ");
	// Serial2.println(UART2.Rx_Len);
	UART2.Rx_Data[UART2.Rx_Len] = '\0';
	memcpy(UART2.Tx_Data, UART2.Rx_Data, UART2.Rx_Len + 1);

	// Serial2.println(UART2.Tx_Data);
	DEBUG_UART.println(UART2.Tx_Data);

	RxData_Callback(UART2.Rx_Data, UART2.Rx_Len);

	UART2.Rx_Len      = 0;
	UART2.Rx_En       = true;


}// End of void UART2_RxData_Handle(void)

/*******************************************************************************
*                   陆超@2016-10-17
* Function Name  :  serialEvent2
* Description    :  串口中断处理
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void serialEvent2(void)
{
	char inChar;
    while (Serial2.available())
    {

        // get the new byte:
        inChar = (char)Serial2.read();

		if (UART2.Rx_En == true)
		{
			// 未溢出
	        if (UART2.Rx_Len < UART2_RX_BUFFER_SIZE)
			{
	        	UART2.Rx_Data[UART2.Rx_Len++] = inChar;
			}
		}
    }

	// 刷新超时时间
	UART2.Rx_Timestamp = 5;

}// End of void serialEvent2(void)

/*******************************************************************************
*                   陆超@2016-10-18
* Function Name  :  UART2_Rx_Finish_Judge
* Description    :  串口接收完成判断
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void UART2_Rx_Finish_Judge(void)
{
	if (UART2.Rx_Timestamp)
	{
		UART2.Rx_Timestamp--;
		if (UART2.Rx_Timestamp == 0)
		{
			UART2.Rx_En       = false;
			UART2.Rx_Complete = true;
		}
	}

}// End of void UART2_Rx_Finish_Judge(void)

/******************* (C) COPYRIGHT 2016 陆超 **************END OF FILE**********/
