/******************** (C) COPYRIGHT 2016 陆超 ***********************************
* File Name          :  ArduinoMega_Timer.c
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  10/10/2016
* Description        :  Timer程序
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "ArduinoMega_Timer.h"
#include "arduino.h"
#include "ArduinoMega_UART2.h"

/* Private variables ---------------------------------------------------------*/
u32	Timer1_1ms_TimeBase;												// 1ms时间基准
u32 Timer1_1s_TimeBase;													// 1s时间基准

/* Private functions ---------------------------------------------------------*/
void Timer1_Init(void);                                              	// Timer1初始化
void Timer1_Timeout_Callback(void);										// 回调

u32 Get_1ms_TimeBase(void);												// 获取1ms时间基准
u32 Get_1s_TimeBase(void);												// 获取1s时间基准

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
*                   陆超@2016-10-10
* Function Name  :  Timer1_Init
* Description    :  Timer1初始化
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void Timer1_Init(void)
{
	// 变量初始化
	Timer1_1ms_TimeBase = 0;
	Timer1_1s_TimeBase  = 0;

	// 1ms超时
	Timer1.initialize(1000);

	// 注册回调
	Timer1.attachInterrupt(Timer1_Timeout_Callback);

}// End of void Timer1_Init(void)

/*******************************************************************************
*                   陆超@2016-10-10
* Function Name  :  Timer1_Timeout_Callback
* Description    :  Timer1超时回调
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void Timer1_Timeout_Callback(void)
{
	Timer1_1ms_TimeBase++;

	if (Timer1_1ms_TimeBase % 1000 == 0)
	{
		Timer1_1s_TimeBase++;

		DEBUG_UART.println("1s Timestamp");
	}

	UART2_Rx_Finish_Judge();

}// End of void Timer1_Timeout_Callback(void)

/*******************************************************************************
*                   陆超@2016-10-10
* Function Name  :  Get_1ms_TimeBase
* Description    :  获取1ms时间基准
* Input          :  None
* Output         :  None
* Return         :  1ms时间基准
*******************************************************************************/
u32 Get_1ms_TimeBase(void)
{
	return (Timer1_1ms_TimeBase);

}// End of u32 Get_1ms_TimeBase(void)

/*******************************************************************************
*                   陆超@2016-10-10
* Function Name  :  Get_1s_TimeBase
* Description    :  获取1s时间基准
* Input          :  None
* Output         :  None
* Return         :  1ms时间基准
*******************************************************************************/
u32 Get_1s_TimeBase(void)
{
	return (Timer1_1s_TimeBase);

}// End of u32 Get_1s_TimeBase(void)

/******************* (C) COPYRIGHT 2016 陆超 ************* END OF FILE *********/
