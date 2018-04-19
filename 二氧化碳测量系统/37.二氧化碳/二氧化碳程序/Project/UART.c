#include <STC12C5A.H>
#include<stdio.h>
#include<UART.H>

#define SYS_Fosc        11059200  //晶振频率			   
#define COMM_BAUD_RATE  9600      //串口波特率

//********************串口1初始化
void UART1_Iint()
{
 SCON=0x50; //[bit6:5]SM1 SM2 = 1 0;[bit4]REN=1
 AUXR=0x11; //[bit4]BRTR=1,允许独立波特率发生器运行;[bit0]SIBRS=1,独立波特率作为串口1的波特率发生器，此时定时器1释放
 BRT=0XFD;   //独特波特率发生器定时器（产生波特率9600）
 ES=0;
 TI=1;
}
//void UART2_Iint()
//{
// S2CON=0x50;  //S2SM0 S2SM1=0 1   S2REN=1 //串口2的工作方式1，接收位允许
// AUXR=0x11;  //BRTR=1,允许独立波特率发生器运行
// BRT=0XFD;  //独特波特率发生器定时器
// IE2=IE2&0xFE;
// S2CON=S2CON|0x02;
//}

//*******************串口1发送函数
//void Send1_Data(unsigned char a)
//{
//  u8 i=0;
//
//  TI=0;
//  SBUF=a;
//  while(!TI);
//}
//void Send2_Data(unsigned char a)
//{
//  u8 i=0;
//
//  S2CON&=0xFD;   //S2TI清0
//  S2BUF=a;
//  while(!(S2CON&0x02)); //while(!S2TI) 等待S2TI变为1
//}

//void Serial()
//{
// u8 a;
// if(RI)    
//  {   
//   a=SBUF;
//   switch(a)
//   {  
//	 case 1:
//			break;
//
//	 case 2:
//			break;
//
//   	 case 3:
//			break;
//
//     case 4:
//			break;
//
//	 case 5:
//	       break;
//    }
//	RI=0;//清接收中断标志 
//  }
//}

