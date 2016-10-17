/******************** (C) COPYRIGHT 2016 陆超 ***********************************
* File Name          :  ArduinoMega2560.ino
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  09/18/2016
* Description        :  Arduino 主程序
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>
#include "ArduinoMega_SD.h"
#include "ArduinoMega_UART1.h"
#include "ArduinoMega_UART2.h"
#include "ArduinoMega_GPU_LCD.h"
#include "ArduinoMega_RTC.h"
#include "ArduinoMega_Timer.h"
#include "ArduinoMega_DHTxx.h"
#include "Global.h"



/* Private variables ---------------------------------------------------------*/
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
u32 ui1sTimestamp;														// s时间戳
u32 ui100msTimestamp;													// 100ms时间戳



/* Private functions ---------------------------------------------------------*/
void Loop_1s(void);														// s循环
void Loop_100ms(void);													// 100ms循环

/* Private functions ---------------------------------------------------------*/
void setup()
{

    // put your setup code here, to run once:
    Serial.begin(115200);

    UART1_Init(115200);

	GPU_LCD_Init();

    SDCard_Init();

    // 实时时钟初始化
    RTC_Init();

	// 初始化Timer1
	Timer1_Init();

	// 初始化温湿度
	DHTxx_Init();

	ui1sTimestamp = millis();


}

void loop()
{

	// s循环
	if (millis() - ui1sTimestamp >= 1000)
	{
		ui1sTimestamp = millis();

		Loop_1s();
	}

	// s循环
	if (millis() - ui100msTimestamp >= 100)
	{
		ui100msTimestamp = millis();

		Loop_100ms();
	}


    if (stringComplete)
    {
        Serial.print("收到数据:");
        Serial.println(inputString);

        // clear the string:
        inputString = "";
        stringComplete = false;
    }
	if (UART1.Rx_Complete == true)
	{
		UART1_RxData_Handle();
		UART1.Rx_Complete = false;
	}

	if (UART2.Rx_Complete == true)
	{
		UART2_RxData_Handle();
		UART2.Rx_Complete = false;
	}


}

/*******************************************************************************
*                   陆超@2016-10-13
* Function Name  :  Loop_100ms
* Description    :  1ms任务
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void Loop_100ms(void)
{



}// End of void Loop_100ms(void)

/*******************************************************************************
*                   陆超@2016-10-10
* Function Name  :  Loop_1s
* Description    :  1s任务
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void Loop_1s(void)
{
	// float Temp, Humi;
	Serial.println("Hello Mega2560");
	RTC_Print_Time();
	// DHTxx_Read(&Temp, &Humi);

	GPU_LCD_Task();


}// End of void Loop_1s(void)

void serialEvent()
{
    while (Serial.available())
    {
        // get the new byte:
        char inChar = (char)Serial.read();
        // add it to the inputString:
        inputString += inChar;
        // if the incoming character is a newline, set a flag
        // so the main loop can do something about it:
        if (inChar == '\n')
        {
            stringComplete = true;
        }
    }
}
