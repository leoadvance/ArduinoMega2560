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
DHT Dht11;																// 声明结构体

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
	Dht11.setup(DHTxx_DATA_PIN);

}// End of void DHTxx_Init(void)

/*******************************************************************************
*                   陆超@2016-10-13
* Function Name  :  DHTxx_Read
* Description    :  DHTxx读取温湿度
* Input          :  float *fTemp  温度
*					float *fHumi  湿度
* Output         :  None
* Return         :  0 成功 -1 超时 -2 crc错误
*******************************************************************************/
int DHTxx_Read(float *fTemp, float *fHumi)
{
	char *p_Get_Status;
	char Send_Data[48];

	// 读取温湿度
	*fHumi = Dht11.getHumidity();
	*fTemp = Dht11.getTemperature();

	p_Get_Status = (char *)Dht11.getStatusString();
	sprintf(Send_Data, "Temp = %f℃, Humi = %f%%  %s \r\n", (double)*fTemp, (double)*fHumi, p_Get_Status);
	DEBUG_UART.print(Send_Data);

	if (strstr(p_Get_Status, "OK"))
	{
		return 0;
	}
	else if (strstr(p_Get_Status, "TIMEOUT"))
	{
		return -1;
	}
	else
	{
		return -2;
	}



}// End of int DHTxx_Init(float *fTemp, float *fHumi)


/******************* (C) COPYRIGHT 2016 陆超 **************END OF FILE**********/
