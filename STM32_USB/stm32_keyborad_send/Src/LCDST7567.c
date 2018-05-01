
//#include <reg51.h>
//#include <intrins.h>
//#define  unsigned char unsigned char
//#define  uint unsigned int
/*
sbit	R_S=	P3^5;//Ö¸Áî/Êý¾ÝÑ¡ÔñÐÅºÅ
sbit	RES=	P3^4;//¸´Î»ÐÅºÅ
sbit	W_R= 	P3^1;//Ð´ÐÅºÅ
sbit	R_D=	P3^0;//¶ÁÐÅºÅ
sbit    C_S=    P3^7;//Æ¬Ñ¡


*/
#include "stm32f10x_gpio.h"
#include "stm32f10x_i2c.h"
#include "i2c_fram.h"
#include "LCDST7567.h"


/****************Serial*************************/


 

#define RS_L GPIO_ResetBits(GPIOB, GPIO_Pin_8)
#define RS_H GPIO_SetBits(GPIOB, GPIO_Pin_8)
#define RES_L GPIO_ResetBits(GPIOB, GPIO_Pin_9)
#define RES_H GPIO_SetBits(GPIOB, GPIO_Pin_9)
#define CS_L GPIO_ResetBits(GPIOC, GPIO_Pin_5)
#define CS_H GPIO_SetBits(GPIOC, GPIO_Pin_5)

#define BL_L GPIO_ResetBits(GPIOB, GPIO_Pin_5)
#define BL_H GPIO_SetBits(GPIOB, GPIO_Pin_5)


/**********************************************/


unsigned char Page = 0xb0	;
                           			                    


void delayms(uint16_t ms)
{	
	uint16_t j;
	while(ms--)
	  for(j=0;j<=0x1002;j++); //®É20us=0.02ms//  
}		
	


/************Serial*************/

void WrateC(unsigned char com)

{
    
	    CS_L;
	    RS_L;  
   	/*     SCK=0;
	
	for(i=0;i<8;i++)
	    { 
		 j=com;
		 SCK=0;
		 SDA=com&0x80;
         SCK=1;	     
		 com=j<<1;
		}
		*/
		I2C_SendByte(com);
	    CS_H;
		RS_H;
}


void WrateD(unsigned char dat)
{
    
	    CS_L;
	    RS_H;  
       /* SCK=0;
	for(i=0;i<8;i++)
	    { 
		 j=dat;
		 SCK=0;
		 SDA=dat&0x80;
         SCK=1;	     
		 dat=j<<1;
		}*/
		I2C_SendByte(dat);
	    CS_H;
		RS_L;
}



void ClearDisplay(unsigned char const *P)
{

//   page=0x80;
   unsigned char  i,j;
   for(i=0xb0;i<0xB8;i++)   
    {
         WrateC(i);               // (Page = 0xB0)//ÉèÖÃÎ»ÖÃ
 	 WrateC(0x00);
	 WrateC(0x10);	  
       for(j=0;j<128;j++) 			//·¢ËÍÊý¾Ý
          { 
            WrateD(*P++);
          }
          
    }
delayms(1);
}  

void LCDGPIOinit(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	/*--------------------------------------------------------------*/
	/*NRST------------------->B9*/
	/*LCD_CLK---------------->B6*/
	/*LCD_A0----------------->B8*/
	/*LCD_CS----------------->C5*/
	/*LCD_IO----------------->B7*/
	/*LCD_LED+--------------->B5*/
	/*--------------------------------------------------------------*/

	/*Enable or disable APB2 peripheral clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	
	/*Configure GPIO pin : PB */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	/*Configure GPIO pin : PB */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

		/*Enable or disable APB2 peripheral clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

	
	/*Configure GPIO pin : PB */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

}




void LcdInit(void)
{		

	LCDGPIOinit();
	BL_L;
	RES_L;
	RS_L;
	delayms(50);//×090îÉÙ2um
	RES_H;
	RS_H;
	BL_H;
	delayms(20);
	RES_L;
	RS_L;
	BL_L;
	delayms(50);
	RES_H;
	RS_H;
	BL_H;
	WrateC(0xe2);//Èí¼þ¸´Î»		
	WrateC(0xA3);//Bais set		ÏÔÊ¾Æ«Ñ¹
	WrateC(0xA0);//ADC seg¾µÏñÑ¡Ôñ 0xa0Õý³££¬0xA1×óÓÒ¾µÏñ
	WrateC(0xc8);//com output scan direction£¬com¾µÏñÑ¡Ôñ 0xc0Õý³££¬0xC8ÉÏÏÂ¾µÏñ
/****Select internal resistor ratio****/
	WrateC(0x2c);//ÄÚ²¿µçÔ´¹ÜÀí£¬
	WrateC(0x2e);//ÈýÌõÖ¸Áî¼ä¸ôÊ±¼ä2um
	WrateC(0x2F);//
/**************************************/

	WrateC(0x81);//µçÑ¹Ä£Ê½Ñ¡Ôñ
	WrateC(0x1d);//µçÑ¹µ÷Õû¼Ä´æÆ÷µÍÎ» ·¶Î§£º0x00-0x3f
	WrateC(0x24);//µçÑ¹µ÷Õû¼Ä´æÆ÷¸ßÎ» ·¶Î§£º0x21-0x27 £¬ÖµÔ½´ó£¬ÏÔÊ¾Ð§¹ûÔ½Å¨£¨µ×Ó°Ô½Å¨£©

	WrateC(0xAF);//ÏÔÊ¾¿ª         
	WrateC(0x40);//´ÓÊ×ÐÐ¿ªÊ¼ÏÔÊ¾
	BL_H;
	
}
	







void Setadd(unsigned char xl,unsigned char yl)
{    unsigned char i;
     i=xl&0x0f;
     xl=(xl>>4)+0x10;

     WrateC(0xb0+yl); 	  
	 WrateC(xl);
 	 WrateC(i);	
}

/*

void ShowOneDig(unsigned char col,unsigned char pag,unsigned char d)
{
	
{
	unsigned char i = 0 ;
	unsigned char j;
	if(col==0x80)        
	{ 
	   col=0;
	   pag+=1;
	 }
	Setadd(col,pag);   	   	  
	for(j=0;j<8;j++)
	{ 
	 
		WrateD(Number[d][i++]); 
	}          
	pag++;  
	
	Setadd(col,pag);   	   	  
	for(j=0;j<8;j++)
	{ 
		WrateD(Number[d][i++]); 
	}          
	pag++;   
   
}

delayms(1);
}


*/

//--------------------------------------------
/*
void main()
{	
  LcdInit();
      while(1)
	{
	//unsigned char a = 0 ;
	
	
	ClearDisplay(pJH);
	
	ClearDisplay(pJH1);
	
	
	
	ShowOneDig(3,0,0);    //¿ªÊ¼Êý×ÖÊÇSEGÆðÊ¼Ïß,ÖÐ¼äÊý×Ö±íÊ¾pageµÚ*Ò³£¬ºóÃæÊý×Ö±íÊ¾"²é±í"µÚ*ÐÐ
	LcdInit();
	ShowOneDig(10,0,1);
	LcdInit();
	ShowOneDig(17,0,2);
	LcdInit();
	ShowOneDig(24,0,3);
	LcdInit();
	ShowOneDig(31,0,4);
	LcdInit();
	ShowOneDig(38,0,5);
	LcdInit();
	ShowOneDig(45,0,6);
	LcdInit();
	ShowOneDig(52,0,7);
	ShowOneDig(59,0,0);    //¿ªÊ¼Êý×ÖÊÇSEGÆðÊ¼Ïß,ÖÐ¼äÊý×Ö±íÊ¾pageµÚ*Ò³£¬ºóÃæÊý×Ö±íÊ¾"²é±í"µÚ*ÐÐ
	ShowOneDig(63,0,1);
	ShowOneDig(70,0,2);
	ShowOneDig(77,0,3);
	ShowOneDig(84,0,4);
	ShowOneDig(91,0,5);
	ShowOneDig(98,0,6);
	ShowOneDig(105,0,7);
	ShowOneDig(112,0,2);
	ShowOneDig(119,0,3);
	ShowOneDig(127,0,4);
	
	//ShowOneDig(88,3,9);
	
	
	
	}
}
*/




