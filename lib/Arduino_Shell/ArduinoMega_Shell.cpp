/******************** (C) COPYRIGHT 2016 陆超 ***********************************
* File Name          :  ArduinoMega_Shell.c
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  10/13/2016
* Description        :  Shell程序
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "ArduinoMega_Shell.h"
#include "arduino.h"
#include "ArduinoMega_RTC.h"


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
void Shell_Set_RTC(char *p_Data);											// 设置RTC

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
*                   陆超@2016-10-13
* Function Name  :  Shell_Set_RTC
* Description    :  设置RTC
* Input          :  char *p_Data 待解析字符串
* Output         :  None
* Return         :  None
*******************************************************************************/
void Shell_Set_RTC(char *p_Data)
{
	char *p_Temp;
	int usYear, ucMonth, ucDay, ucHour, ucminute, ucSecond, ucWeekday;
	p_Temp  = strstr(p_Data, SHELL_RTC_HEAD);
	p_Temp += sizeof(SHELL_RTC_HEAD) - 1;
	sscanf(p_Temp, "%d, %d, %d, %d, %d, %d, %d", &usYear, &ucMonth, &ucDay, &ucHour, &ucminute, &ucSecond, &ucWeekday);

	RTC_Set_Time(usYear, ucMonth, ucDay, ucHour, ucminute, ucSecond, ucWeekday);


}// End of void shell_Set_RTC(char *p_Data)




/******************* (C) COPYRIGHT 2016 陆超 **************END OF FILE**********/
