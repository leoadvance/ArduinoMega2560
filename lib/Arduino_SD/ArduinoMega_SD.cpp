/******************** (C) COPYRIGHT 2016 陆超 ***********************************
* File Name          :  ArduinoMega_SD.c
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  09/18/2016
* Description        :  串口程序
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "ArduinoMega_SD.h"
#include "arduino.h"


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
void SDCard_Init(void);                                                 // SD初始化
void SD_CS_Low(void);                                                   // 拉低CS
void SD_CS_High(void);                                                  // 释放CS管脚

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
*                   陆超@2016-09-22
* Function Name  :  SD_CS_Low
* Description    :  拉低CS管脚
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void SD_CS_Low(void)
{
    digitalWrite(SD_CS_PIN, LOW);

}// ENd of void SD_CS_Low(void)

/*******************************************************************************
*                   陆超@2016-09-22
* Function Name  :  SD_CS_High
* Description    :  拉高CS管脚
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void SD_CS_High(void)
{
    digitalWrite(SD_CS_PIN, LOW);

}// ENd of void SD_CS_High(void)

/*******************************************************************************
*                   陆超@2016-09-18
* Function Name  :  SDCard_Init
* Description    :  SD初始化
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void SDCard_Init(void)
{

    DEBUG_UART.println("Initializing SD card...");

    // 片选CS
    pinMode(SD_CS_PIN, OUTPUT);

    // 拉低片选
    SD_CS_Low();

    // 使能SD without CS
    if (!SD.begin())
    {
        // 如果从CS口与SD卡通信失败，串口输出信息Card failed, or not present
        DEBUG_UART.println("Card failed, or not present");

    }
    else
    {
        // 初始化成功
        DEBUG_UART.println("initialization done.");
    }

    File dataFile = SD.open("datalog.txt", FILE_WRITE);  //打开datalog.txt文件
    if (dataFile)
    {


        DEBUG_UART.print("Writing to test.txt...");
        dataFile.println("testing 1, 2, 3.");


        DEBUG_UART.println("done.");

        DEBUG_UART.print("Read SDCard Data = ");
        dataFile.seek(0);
        while (dataFile.available())
        {
            //检查是否dataFile是否有数据
            DEBUG_UART.write(dataFile.read());  //如果有数据则把数据发送到串口
        }
        dataFile.close();
    }
    else
    {
        DEBUG_UART.println("error opening datalog.txt");  //如果文件无法打开串口发送信息error opening datalog.txt
    }


}// End of void SDCard_Init(void)




/******************* (C) COPYRIGHT 2016 陆超 **************END OF FILE**********/
