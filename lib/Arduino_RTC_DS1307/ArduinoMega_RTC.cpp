/******************** (C) COPYRIGHT 2016 陆超 ***********************************
* File Name          :  ArduinoMega_RTC.c
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  10/08/2016
* Description        :  RTC程序
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "ArduinoMega_RTC.h"
#include "arduino.h"


/* Private variables ---------------------------------------------------------*/
DS1307 RTC_Clock;                                                       // 声明一个时钟类

/* Private function prototypes -----------------------------------------------*/
void RTC_Init(void);                                                    // RTC初始化
void RTC_Print_Time(void);                                              // 打印当前时间

/* Private functions ---------------------------------------------------------*/


/*******************************************************************************
*                   陆超@2016-10-08
* Function Name  :  RTC_Init
* Description    :  RTC初始化
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void RTC_Init(void)
{

    RTC_Clock.begin();
    RTC_Clock.fillByYMD(2016,10,1);//Jan 19,2013
    RTC_Clock.fillByHMS(1,25,30);//15:28 30"
    RTC_Clock.fillDayOfWeek(SAT);//Saturday
    RTC_Clock.setTime();//write time to the RTC chip

}// End of void RTC_Init(void)

/*******************************************************************************
*                   陆超@2016-10-08
* Function Name  :  RTC_Print_Time
* Description    :  RTC打印时间
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void RTC_Print_Time(void)
{
    RTC_Clock.getTime();
	DEBUG_UART.print(RTC_Clock.hour, DEC);
	DEBUG_UART.print(":");
	DEBUG_UART.print(RTC_Clock.minute, DEC);
	DEBUG_UART.print(":");
	DEBUG_UART.print(RTC_Clock.second, DEC);
	DEBUG_UART.print("	");
	DEBUG_UART.print(RTC_Clock.month, DEC);
	DEBUG_UART.print("/");
	DEBUG_UART.print(RTC_Clock.dayOfMonth, DEC);
	DEBUG_UART.print("/");
	DEBUG_UART.print(RTC_Clock.year+2000, DEC);
	DEBUG_UART.print(" ");
	switch (RTC_Clock.dayOfWeek)// Friendly printout the weekday
	{
        case MON:
		  	DEBUG_UART.print("MON");
		  	break;
		case TUE:
		  	DEBUG_UART.print("TUE");
		  	break;
		case WED:
		  	DEBUG_UART.print("WED");
		  	break;
		case THU:
		  	DEBUG_UART.print("THU");
		  	break;
		case FRI:
		    DEBUG_UART.print("FRI");
		    break;
		case SAT:
		    DEBUG_UART.print("SAT");
		    break;
		case SUN:
	        DEBUG_UART.print("SUN");
	        break;
        default:
            break;
    }
    DEBUG_UART.println(" ");

}// End of void RTC_Print_Time()


/******************* (C) COPYRIGHT 2016 陆超 **************END OF FILE**********/
