#include <REG51.H>
#include<intrins.h>
#include <LCD1602.h>
#include <SBQ.H>
#include <DS18B20.h>

u8 dis[4]={0,0,0,0};
u16 Time=0;
u16 V1=0;V2=0;
float Proportion;

sbit Ctrl=P3^7;

/*****定时器T0初始化*****/
void Time0_Init()
{
  TMOD=0X01;
  EA=1;
  TR0=1;
  ET0=1;
  TH0=0X3C;//50ms
  TL0=0XB0;
}


void delay(u16 t)
{
  u16 j;
   for(;t>0;t--)
   	 for(j=113;j>0;j--);
}

void main()	  
{
  AD_Init(0xC0);
  LCD_Initial();
  Time0_Init();

  LCD_Print(2,0,"Temperature");//1602显示
  LCD_Print(4,1,"Control");
  delay(5000);
  LCD_Write(0x00, 0x01);//清屏

  Ctrl=0;
  while(1)
  {
	  V1=Get_ADC(3,50);
	  V2=Get_ADC(4,50);
	  Proportion=(float)V1/V2*10; 
	  V1=50*V1/255;
	  V2=50*V2/255;

 	  dis[0]=(u16)Proportion/100+'0';//计算两个通道比例
      dis[1]=(u16)Proportion%100/10+'0';
	  dis[2]=(u16)Proportion%100%10+'0';
	  LCD_Print(10,0,"P:  . ");
      LCD_PutChar(12,0,&dis[0]);//1602显示比值
      LCD_PutChar(13,0,&dis[1]);	
	  LCD_PutChar(15,0,&dis[2]);
	  	   
 	  dis[0]=V1/10+'0';//计算通道一电压
      dis[1]=V1%10+'0';
	  LCD_Print(0,0,"V1: . V");
      LCD_PutChar(3,0,&dis[0]);//1602显示
      LCD_PutChar(5,0,&dis[1]);

      dis[0]=V2/10+'0';//计算通道二电压
      dis[1]=V2%10+'0';
	  LCD_Print(0,1,"V2: . V");
      LCD_PutChar(3,1,&dis[0]);//1602显示
      LCD_PutChar(5,1,&dis[1]);

	  delay(5000);
  }
}


/*********定时器中断**********/
void Timer0() interrupt 1
{
  TH0=0X3C;//50ms
  TL0=0XB0;

  Time++;
  if(Time<=90)
  {
    Ctrl=0;
  }
  else if(Time>=90&&Time<=100)
  {
    Ctrl=1;
  }
  else
  {
    Time=0;
  }
}
  