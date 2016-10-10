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
#include "ArduinoMega_RTC.h"
#include "ArduinoMega_Timer.h"
#include "Global.h"


/* Private variables ---------------------------------------------------------*/
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
u32 ui1sTimestamp;

/* Private functions ---------------------------------------------------------*/
void Loop_1s(void);

/* Private functions ---------------------------------------------------------*/
void setup()
{

    // put your setup code here, to run once:
    Serial.begin(115200);

    UART1_Init(115200);

    SDCard_Init();

    // 实时时钟初始化
    RTC_Init();

	// 初始化Timer1
	Timer1_Init();

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

    if (stringComplete)
    {
        Serial.print("收到数据:");
        Serial.println(inputString);

        // clear the string:
        inputString = "";
        stringComplete = false;
    }

	// 串口1接收完毕
	if (UART1.Rx_Complete == true)
	{
		// 串口1数据处理
		UART1_RxData_Handle();


	}

}
/*******************************************************************************
*                   陆超@2016-10-10
* Function Name  :  Timer1_Init
* Description    :  Timer1初始化
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void Loop_1s(void)
{
	Serial.println("Hello Mega2560");
	RTC_Print_Time();

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
