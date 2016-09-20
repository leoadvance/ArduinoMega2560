/******************** (C) COPYRIGHT 2014 ½�� **********************************
* File Name          :  Global.h
* Author             :  ½��
* CPU Type           :  STM32F103
* IDE                :  MDK 4.72
* Version            :  V1.0
* Date               :  08/08/2014
* Description        :  ȫ�ֶ���
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GLOBAL_CFG_H
#define __GLOBAL_CFG_H

/* Includes ------------------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/
//----------------------- System ----------------------------------------------/
#define     SYS_DEBUG                                                   // 系统调试
#define     SYS_UPDATE_SIGN             0x1234                          //

#define     DEBUG_UART                  Serial1                         // 调试串口

/* Private typedef -----------------------------------------------------------*/

typedef long           s32;
typedef short          s16;
typedef char           s8;


typedef unsigned long  u32;
typedef unsigned short u16;
typedef unsigned char  u8;

/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/

#endif /* __GLOBAL_CFG_H */

/******************* (C) COPYRIGHT 2014 ½�� ********END OF FILE***************/
