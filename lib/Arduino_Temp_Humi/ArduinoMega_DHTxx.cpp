/******************** (C) COPYRIGHT 2016 陆超 ***********************************
* File Name          :  ArduinoMega_DHTxx.c
* Author             :  陆超
* CPU Type           :  ArduinoMega2560
* IDE                :  Arduino
* Version            :  V1.0
* Date               :  10/13/2016
* Description        :  DHTxx程序
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "ArduinoMega_DHTxx.h"
#include "arduino.h"


/* Private variables ---------------------------------------------------------*/
DHT dht(DHTPIN, DHTTYPE);

/* Private function prototypes -----------------------------------------------*/
void DHTxx_Init(void);                                                 	// DHTxx初始化
int DHTxx_Read(float *fTemp, float *fHumi);								// 读取温湿度

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
*                   陆超@2016-10-13
* Function Name  :  DHTxxCard_Init
* Description    :  DHTxx初始化
* Input          :  None
* Output         :  None
* Return         :  None
*******************************************************************************/
void DHTxx_Init(void)
{
	dht.begin();

}// End of void DHTxx_Init(void)

/*******************************************************************************
*                   陆超@2016-10-13
* Function Name  :  DHTxx_Read
* Description    :  DHTxx读取温湿度
* Input          :  float *fTemp  温度
*					float *fHumi  湿度
* Output         :  None
* Return         :  0 成功 -1 失败
*******************************************************************************/
int DHTxx_Read(float *fTemp, float *fHumi)
{
	// char Send_Data[48];

	// 读取湿度 温度
	*fHumi = dht.readHumidity();
    *fTemp = dht.readTemperature();


    // 是否读取失败
    if (isnan(*fHumi) || isnan(*fTemp))
	{
		DEBUG_UART.println("Failed to read from DHT sensor!");
		return -1;
    }

	// sprintf(Send_Data, "Temp = %f℃, Humi = %f%% \r\n", (double)*fTemp, (double)*fHumi);
	// DEBUG_UART.print(Send_Data);
    DEBUG_UART.print("Humidity: ");
    DEBUG_UART.print(*fHumi);
    DEBUG_UART.print(" %\t");
    DEBUG_UART.print("Temperature: ");
    DEBUG_UART.print(*fTemp);
    DEBUG_UART.println(" *C");
    // DEBUG_UART.print(f);
    // DEBUG_UART.print(" *F\t");
    // DEBUG_UART.print("Heat index: ");
    // DEBUG_UART.print(hic);
    // DEBUG_UART.print(" *C ");
    // DEBUG_UART.print(hif);
    // DEBUG_UART.println(" *F");

	return 0;


}// End of int DHTxx_Init(float *fTemp, float *fHumi)


/******************* (C) COPYRIGHT 2016 陆超 ************* END OF FILE *********/
