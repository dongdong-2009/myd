#include <REG51.H>
#include <SBQ.H>
#include<intrins.h>

#define u16 unsigned int
#define u8 unsigned char

u16 ms=0;
/*****初始化IO*****/
void AD_Init(u8 S_channel)
{
 P1M1=P1M1|S_channel;//P1^7为高阻输入，其余脚为准双向弱上拉 //AD采集口
 P1M0=P1M0|0X00;
 
 ADC_RES=0X00;//清空结果
 AUXR1=0X00;//选择高8位低2位模式储存
 _nop_();
 _nop_();
 _nop_();
 _nop_();	
}
/*****初始化AD*****/
void Channel(u8 channel)
{
  P1ASF=0x01<<channel;//使能AD通道
  ADC_CONTR=0XE8|channel;//SPEED为540T/次 
  _nop_();
  _nop_();
  _nop_();
  _nop_();	
}

/*****获取AD数据*****/
u8 Get_ADC(u8 channel,u8 time)
{
  u8 Count=0;
  unsigned long Sum=0; 

  for(Count=0;Count<time;Count++)
  {
     Channel(channel);
	 while(!(ADC_CONTR&ADC_FLAG));
	 ADC_CONTR&=!ADC_FLAG;
	 Sum=ADC_RES+Sum;//数据存储
	 ADC_RES=0;//清空结果 
  }
  return Sum/time;
}
