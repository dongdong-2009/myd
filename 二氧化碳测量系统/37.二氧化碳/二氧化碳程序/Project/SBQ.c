#include <REG51.H>
#include <SBQ.H>
#include<intrins.h>

#define u16 unsigned int
#define u8 unsigned char

u16 ms=0;
/*****��ʼ��IO*****/
void AD_Init(u8 S_channel)
{
 P1M1=P1M1|S_channel;//P1^7Ϊ�������룬�����Ϊ׼˫�������� //AD�ɼ���
 P1M0=P1M0|0X00;
 
 ADC_RES=0X00;//��ս��
 AUXR1=0X00;//ѡ���8λ��2λģʽ����
 _nop_();
 _nop_();
 _nop_();
 _nop_();	
}
/*****��ʼ��AD*****/
void Channel(u8 channel)
{
  P1ASF=0x01<<channel;//ʹ��ADͨ��
  ADC_CONTR=0XE8|channel;//SPEEDΪ540T/�� 
  _nop_();
  _nop_();
  _nop_();
  _nop_();	
}

/*****��ȡAD����*****/
u8 Get_ADC(u8 channel,u8 time)
{
  u8 Count=0;
  unsigned long Sum=0; 

  for(Count=0;Count<time;Count++)
  {
     Channel(channel);
	 while(!(ADC_CONTR&ADC_FLAG));
	 ADC_CONTR&=!ADC_FLAG;
	 Sum=ADC_RES+Sum;//���ݴ洢
	 ADC_RES=0;//��ս�� 
  }
  return Sum/time;
}
