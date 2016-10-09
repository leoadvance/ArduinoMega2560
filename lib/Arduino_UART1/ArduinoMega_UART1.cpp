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

	UART1.Rx_Data     = "";
	UART1.Rx_Complete = false;
	UART1.Rx_En       = true;


  	Serial1.begin(uiBrud_Rate);

  	Serial1.print("UART1 init With 8 N 1 Brud Rate = ");
  	Serial1.println(uiBrud_Rate);

}// End of void UART1_Init(u32 uiBrud_Rate)

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

	Serial1.print("串口1收到数据:");
	Serial1.println(UART1.Rx_Data);

	UART1.Rx_Data     = "";
	UART1.Rx_Complete = false;
	UART1.Rx_En       = true;

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
	        UART1.Rx_Data += inChar;
	        // if the incoming character is a newline, set a flag
	        // so the main loop can do something about it:
	        if (inChar == '\n')
	        {
	            UART1.Rx_Complete = true;
				UART1.Rx_En       = false;
	        }
		}
    }

}// End of void serialEvent1(void)


/******************* (C) COPYRIGHT 2016 陆超 **************END OF FILE**********/
