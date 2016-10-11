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

// From Library: FreeRTOS
#include <Arduino_FreeRTOS.h>
#include <list.h>
#include <queue.h>
#include <semphr.h>
#include <task.h>
#include <timers.h>


/* Private variables ---------------------------------------------------------*/
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
u32 ui1sTimestamp;

/* Private functions ---------------------------------------------------------*/
void Loop_1s(void *pvParameters);

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


	xTaskCreate(Loop_1s,
				(const portCHAR *)"Loop_1s" ,  	// 名称
  				128,  						   	// 堆栈
    			NULL,
  				2,     						 	// 优先级 3最高 0最低
				NULL );

	ui1sTimestamp = millis();



}

void loop()
{

	// // s循环
	// if (millis() - ui1sTimestamp >= 1000)
	// {
	// 	ui1sTimestamp = millis();
	//
	// 	Loop_1s();
	// }

    if (stringComplete)
    {
        Serial.print("收到数据:");
        Serial.println(inputString);

        // clear the string:
        inputString = "";
        stringComplete = false;
    }


}
/*******************************************************************************
*                   陆超@2016-10-10
* Function Name  :  Loop_1s
* Description    :  1s任务
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void Loop_1s(void *pvParameters)
{
	for(;;)
	{
		Serial.println("Hello Mega2560");
		RTC_Print_Time();
		vTaskDelay( 1000 / portTICK_PERIOD_MS );
	}

}// End of void Loop_1s(void *pvParameters)

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
