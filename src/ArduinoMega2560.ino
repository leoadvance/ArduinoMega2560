#include <Arduino.h>

/******************** (C) COPYRIGHT 2016 陆超 ***********************************
* File Name          :  ArduinoMega2560.ino
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  09/18/2016
* Description        :  Arduino 主程序
*******************************************************************************/
#include "ArduinoMega_UART1.h"
#include "Global.h"
#include <SPI.h>
#include <SD.h>

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
const int chipSelect = 4;  //设定CS接口

void setup()
{

    // put your setup code here, to run once:
    Serial.begin(115200);

    UART1_Init(115200);

    if (!SD.begin(chipSelect))
    {
        //如果从CS口与SD卡通信失败，串口输出信息Card failed, or not present
        Serial1.println("Card failed, or not present");
        return;
    }
    Serial1.println("card initialized.");  //与SD卡通信成功，串口输出信息card initialized.
    File dataFile = SD.open("datalog.txt", FILE_WRITE);  //打开datalog.txt文件
    if (dataFile)
    {


        Serial1.print("Writing to test.txt...");
        dataFile.println("testing 1, 2, 3.");


        Serial1.println("done.");

        Serial1.print("Read SDCard Data = ");
        dataFile.seek(0);
        while (dataFile.available())
        {  //检查是否dataFile是否有数据
            Serial1.write(dataFile.read());  //如果有数据则把数据发送到串口
        }
        dataFile.close();
    }
    else
    {
        Serial1.println("error opening datalog.txt");  //如果文件无法打开串口发送信息error opening datalog.txt
    }
}

void loop()
{

    delay(1000);
    Serial.println("Hello Mega2560");

    if (stringComplete)
    {
        Serial.print("收到数据:");
        Serial.println(inputString);

        // clear the string:
        inputString = "";
        stringComplete = false;
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
