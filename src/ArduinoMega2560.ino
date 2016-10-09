/******************** (C) COPYRIGHT 2016 陆超 ***********************************
* File Name          :  ArduinoMega2560.ino
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  09/18/2016
* Description        :  Arduino 主程序
*******************************************************************************/
#include <Arduino.h>
#include "ArduinoMega_SD.h"
#include "ArduinoMega_UART1.h"
#include "ArduinoMega_RTC.h"
#include "Global.h"





String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


void setup()
{

    // put your setup code here, to run once:
    Serial.begin(115200);

    UART1_Init(115200);

    SDCard_Init();

    // 实时时钟初始化
    RTC_Init();



}

void loop()
{

    delay(1000);
    Serial.println("Hello Mega2560");
RTC_Print_Time();
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
