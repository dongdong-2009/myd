/*******************************************************************************
* File Name          : i2c_fram.h
* Author             : MCD Application Team
* Version            : V2.0.1
* Date               : 06/13/2008
* Description        : Header for i2c_ee.c module
*******************************************************************************/
/* Define to prevent recursive inclusion ------------------------------------ */
#ifndef __I2C_FRAM_H
#define __I2C_FRAM_H

/* Includes ------------------------------------------------------------------*/
//#include "stm32f10x_lib.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/*
bool I2C_FRAM_BufferWrite(u8* pBuffer, u16 WriteAddr, u16 NumByteToWrite);
bool I2C_FRAM_BufferRead(u8* pBuffer, u16 ReadAddr, u16 NumByteToRead);
*/
typedef enum {FALSE = 0, TRUE = !FALSE} bool;

void I2C_SendByte(u8 SendByte) ;
u8 I2C_ReceiveByte(void) ;


#endif /* __I2C_FRAM_H */

