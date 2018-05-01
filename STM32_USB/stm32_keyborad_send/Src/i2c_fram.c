/*******************************************************************************
* File Name          : i2c_fram.c
* Author             : Appcat
* Version            : V0.0.1
* Date               : 07/11/2009
* Description        : This file provides a set of functions needed to manage the
*                      communication between I2C peripheral and I2C FM24CL16 FRAM.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/

#include "stm32f10x_gpio.h"
#include "stm32f10x_i2c.h"
#include "i2c_fram.h"
#include "stm32f10x.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define I2C_Speed              100000
#define I2C1_SLAVE_ADDRESS7    0xA0
#define I2C_PageSize           256

#define SCL_H         GPIO_SetBits(GPIOB, GPIO_Pin_6)
#define SCL_L         GPIO_ResetBits(GPIOB, GPIO_Pin_6) 
   
#define SDA_H         GPIO_SetBits(GPIOB, GPIO_Pin_7)
#define SDA_L         GPIO_ResetBits(GPIOB, GPIO_Pin_7)

#define SCL_read      GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)
#define SDA_read      GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
vu8 FRAM_ADDRESS;

/* Private function prototypes -----------------------------------------------*/

/**/
void I2C_delay(void)
{        
   u8 i=15; //这里可以优化速度        ，经测试最低到5还能写入
   while(i) 
   { 
     i--; 
   } 
}

bool I2C_Start(void)
{
        SDA_H;
        SCL_H;
        I2C_delay();
        if(!SDA_read)return FALSE;        //SDA线为低电平则总线忙,退出
        SDA_L;
        I2C_delay();
        if(SDA_read) return FALSE;        //SDA线为高电平则总线出错,退出
        SDA_L;
        I2C_delay();
        return TRUE;
}

void I2C_Stop(void)
{
        SCL_L;
        I2C_delay();
        SDA_L;
        I2C_delay();
        SCL_H;
        I2C_delay();
        SDA_H;
        I2C_delay();
}

void I2C_Ack(void)
{        
        SCL_L;
        I2C_delay();
        SDA_L;
        I2C_delay();
        SCL_H;
        I2C_delay();
        SCL_L;
        I2C_delay();
}

void I2C_NoAck(void)
{        
        SCL_L;
        I2C_delay();
        SDA_H;
        I2C_delay();
        SCL_H;
        I2C_delay();
        SCL_L;
        I2C_delay();
}

bool I2C_WaitAck(void)          //返回为:=1有ACK,=0无ACK
{
        SCL_L;
        I2C_delay();
        SDA_H;                        
        I2C_delay();
        SCL_H;
        I2C_delay();
        if(SDA_read)
        {
      SCL_L;
      return FALSE;
        }
        SCL_L;
        return TRUE;
}

void I2C_SendByte(u8 SendByte) //数据从高位到低位//
{
    u8 i=8;
    while(i--)
    {
        SCL_L;
        I2C_delay();
      if(SendByte&0x80)
        SDA_H;  
      else 
        SDA_L;   
        SendByte<<=1;
        I2C_delay();
        SCL_H;
        I2C_delay();
    }
    SCL_L;
}

u8 I2C_ReceiveByte(void)  //数据从高位到低位//
{ 
    u8 i=8;
    u8 ReceiveByte=0;

    SDA_H;                                
    while(i--)
    {
      ReceiveByte<<=1;      
      SCL_L;
      I2C_delay();
          SCL_H;
      I2C_delay();        
      if(SDA_read)
      {
        ReceiveByte|=0x01;
      }
    }
    SCL_L;
    return ReceiveByte;
}
/*
bool I2C_FRAM_BufferWrite(u8* pBuffer, u16 WriteAddr, u16 NumByteToWrite)
{
        u8 Addr = 0, count = 0;

        Addr = WriteAddr / I2C_PageSize;

        count = WriteAddr % I2C_PageSize;

        Addr = Addr << 1;

        Addr = Addr & 0x0F;  

        FRAM_ADDRESS = I2C1_SLAVE_ADDRESS7 | Addr;

    if (!I2C_Start()) return FALSE;
    I2C_SendByte(FRAM_ADDRESS);//设置器件地址+段地址 
    if (!I2C_WaitAck())
        {
                I2C_Stop(); 
                return FALSE;
        }
    I2C_SendByte(count);   //设置段内地址      
        I2C_WaitAck();        
          
        while(NumByteToWrite--)
        {
          I2C_SendByte(* pBuffer);
          I2C_WaitAck();
      pBuffer++;
        }
        I2C_Stop();
          //注意：因为这里要等待EEPROM写完，可以采用查询或延时方式(10ms)
          //Systick_Delay_1ms(10);
        return TRUE;
}


//读出1串数据         
bool I2C_FRAM_BufferRead(u8* pBuffer, u16 WriteAddr, u16 NumByteToRead)
{                
        u8 Addr = 0, count = 0;

    Addr = WriteAddr / I2C_PageSize;

        count = WriteAddr % I2C_PageSize;

        Addr = Addr << 1;

        Addr = Addr & 0x0F;  

        FRAM_ADDRESS = I2C1_SLAVE_ADDRESS7 | Addr;
        
        if (!I2C_Start()) return FALSE;

    I2C_SendByte(FRAM_ADDRESS);//设置器件地址+段地址 

    if (!I2C_WaitAck()) 
        {
                I2C_Stop(); 
                return FALSE;
        }

    I2C_SendByte(count);   //设置低起始地址      
    I2C_WaitAck();
    I2C_Start();
    I2C_SendByte(FRAM_ADDRESS | 0x01);
    I2C_WaitAck();
    while(NumByteToRead)
    {
      *pBuffer = I2C_ReceiveByte();
      if(NumByteToRead == 1)I2C_NoAck();
      else I2C_Ack(); 
      pBuffer++;
      NumByteToRead--;
    }
    I2C_Stop();
    return TRUE;
}
*/
