#include <STC12C5A.H>
#include<stdio.h>
#include<UART.H>

#define SYS_Fosc        11059200  //����Ƶ��			   
#define COMM_BAUD_RATE  9600      //���ڲ�����

//********************����1��ʼ��
void UART1_Iint()
{
 SCON=0x50; //[bit6:5]SM1 SM2 = 1 0;[bit4]REN=1
 AUXR=0x11; //[bit4]BRTR=1,������������ʷ���������;[bit0]SIBRS=1,������������Ϊ����1�Ĳ����ʷ���������ʱ��ʱ��1�ͷ�
 BRT=0XFD;   //���ز����ʷ�������ʱ��������������9600��
 ES=0;
 TI=1;
}
//void UART2_Iint()
//{
// S2CON=0x50;  //S2SM0 S2SM1=0 1   S2REN=1 //����2�Ĺ�����ʽ1������λ����
// AUXR=0x11;  //BRTR=1,������������ʷ���������
// BRT=0XFD;  //���ز����ʷ�������ʱ��
// IE2=IE2&0xFE;
// S2CON=S2CON|0x02;
//}

//*******************����1���ͺ���
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
//  S2CON&=0xFD;   //S2TI��0
//  S2BUF=a;
//  while(!(S2CON&0x02)); //while(!S2TI) �ȴ�S2TI��Ϊ1
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
//	RI=0;//������жϱ�־ 
//  }
//}

