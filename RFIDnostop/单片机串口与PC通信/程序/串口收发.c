

/*预处理命令*/
#include <reg52.h> 		  //包含单片机寄存器的头文件
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
uchar num,a;
#define uchar unsigned char 
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;

sbit TXD1 = P3^3; //??????? 
sbit RXD1 = P3^2;   //???????   
bdata unsigned char SBUF1;   //????????? 
sbit SBUF1_bit0 = SBUF1^0; 
sbit SBUF1_bit1 = SBUF1^1; 
sbit SBUF1_bit2 = SBUF1^2; 
sbit SBUF1_bit3 = SBUF1^3; 
sbit SBUF1_bit4 = SBUF1^4; 
sbit SBUF1_bit5 = SBUF1^5; 
sbit SBUF1_bit6 = SBUF1^6; 
sbit SBUF1_bit7 = SBUF1^7;  
bdata unsigned char SBUF1_send;   //????????? 
sbit SBUF1_send_bit0 = SBUF1_send^0; 
sbit SBUF1_send_bit1 = SBUF1_send^1; 
sbit SBUF1_send_bit2 = SBUF1_send^2; 
sbit SBUF1_send_bit3 = SBUF1_send^3; 
sbit SBUF1_send_bit4 = SBUF1_send^4; 
sbit SBUF1_send_bit5 = SBUF1_send^5; 
sbit SBUF1_send_bit6 = SBUF1_send^6; 
sbit SBUF1_send_bit7 = SBUF1_send^7; 
unsigned int tcount;
unsigned char m;
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,
                        0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e,0x89,0xc7,0xc8,0xc1};
uchar code cardtable[]={0x00,0x03,0x4a,0x18};
uchar card_msg[36];
uchar card_msg_cp[36];
uchar msg_start=0;

void delay_bps() 
{
	
unsigned char i; 
	EA=0;
for (i = 0; i < 29; i++);
_nop_();
_nop_();

	EA=1;
} //???9600 ????9600???  
void delay(uchar i)
{
  uchar j,k; 
  for(j=i;j>0;j--)
  for(k=125;k>0;k--);
}


void putchar2(unsigned char input)    //??????????
 {      
	SBUF1_send = input;      
	TXD1 = 0;  //???     
	delay_bps();          
	TXD1 = SBUF1_send_bit0;  //0     
	delay_bps();          
	TXD1 = SBUF1_send_bit1;  //1     
	delay_bps();          
	TXD1 = SBUF1_send_bit2;  //2     
	delay_bps();          
	TXD1 = SBUF1_send_bit3;  //3     
	delay_bps();         
	TXD1 = SBUF1_send_bit4;  //4     
	delay_bps();          
	TXD1 = SBUF1_send_bit5;  //5     
	delay_bps();          
	TXD1 = SBUF1_send_bit6;  //6     
	delay_bps();         
	TXD1 = SBUF1_send_bit7;  //7     
	delay_bps();          
	TXD1 = 1;       //???     
	delay_bps();     
}  
 
void display(uint x)
{
  uchar x1,x2,x3,x4;
		uchar i=10;
	x1 = x>>12;
	x2 = x/256%16;
	x3 = x/16%16;
	x4 = x%16;


   
	
		P0=table[x1];
	//P0 = 0xa4;
   P2_0 = 0;
	while(i--);
 //  delay(5);
   P2_0 = 1;
i=10;
   P0=(table[x2]& 0x7f);
	// P0=0xb0;
   P2_1 = 0;
 //  delay(5);
	while(i--);
   P2_1 = 1;
i=10;
  P0=table[x3];
//	P0=0x99;
   P2_2 = 0;
  // delay(5);
	while(i--);
   P2_2 = 1;
i = 10;
  P0=table[x4];
//		P0=0x92;
   P2_3 = 0;
 //  delay(5);
 while(i--);
   P2_3 = 1;
   
}
/*
********************************************************************************
** 函数名称 ： main(void)
** 函数功能 ： 主函数
********************************************************************************
*/
uchar intr_flag = 0;

uchar cardaddr;
uchar cardnum[4];
uchar cardstate;
uchar cardcheck;
uchar state = 0;
uchar intrstate = 0xff;
void main()
{
	
	int i=0;
		EX0=1;         //外部中断0开
	IT0=0;         //酱シ?
	
	TMOD=0x20;		   //用定时器设置串口波特率	   9600 
	TH1=0xfd;
	TL1=0xfd;
	TR1=1;
	REN=1;          //串口初始化
	SM0=0;
	SM1=1;
	EA=1;           //开启总中断
	ES=1;
	
	while(1)
	{
 
		if(num==1)    //判断是否有串口数据的传送
		{
			ES=0;
			num=0;
					


			TI=0;
			ES=1;
	
		}
		

		intrstate--;
		
		if(intrstate > 10)
		{
			for(i = 0; i<36;i++)
					putchar2(card_msg_cp[i]);

			for(i = 0; i<25;i++)
			{
					
				if(card_msg_cp[i+0] == 0xff && card_msg_cp[i+1] == 0xff && card_msg_cp[i+2] == 0xff && card_msg_cp[i+3] == 0xff && card_msg_cp[i+4] == 0xff)
				{
								//putchar2(0x01);
					cardcheck = card_msg_cp[i+5]^card_msg_cp[i+6]^card_msg_cp[i+7]^card_msg_cp[i+8]^card_msg_cp[i+9]^card_msg_cp[i+10];
					if(cardcheck == card_msg_cp[i+11])
					{
						//putchar2(0x02);
						cardaddr = card_msg_cp[i+5];
						cardstate = card_msg_cp[i+6];
						if(cardtable[0] == card_msg_cp[i+7] && cardtable[1] == card_msg_cp[i+8] && cardtable[2] == card_msg_cp[i+9] && cardtable[3] == card_msg_cp[i+10])
						{
							//putchar2(0x03);
							state = 0x01;
							//display(0xd0d0); 
								break;
						}
						else 
						{
							state = 0x02;
							//display(0xeeee);
							
						}
					}
				}

				
			}
		
		}
		else
		{
			intrstate++;
			state = 0x00;
			putchar2(0x01);

		}


		switch(state)
		{
			case 0x00: 
				display(0x0000);
				break;
			case 0x01:
				display(0xd0d0);
				break;
			case 0x02:
				display(0xeeee);
				break;
			default:
				display(0x0000);
				break;
		}
		
		
	}	
}
void ser() interrupt 4
{
	int i;
	RI=0;
	//P2=SBUF;			//接收数据SBUF，即将计算机的数据接收。
	card_msg[msg_start++]=SBUF;

	if(msg_start >= 36)
	{			
		for(i = 0; i<36;i++)
		{
			card_msg_cp[i] = card_msg[i];
			
		}
		msg_start = 0;
	}
	num=1;
	intrstate=0xff;
}

void getchar2(void) interrupt 0 using 1
{

	//while (RXD1);
intr_flag = 1;	
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();    
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();  	
	delay_bps();      
	SBUF1_bit0 = RXD1; //0            
	delay_bps();      
	SBUF1_bit1 = RXD1; //1           
	delay_bps();      
	SBUF1_bit2 = RXD1; //2        
	delay_bps();      
	SBUF1_bit3 = RXD1; //3            
	delay_bps();      
	SBUF1_bit4 = RXD1; //4            
	delay_bps();      
	SBUF1_bit5 = RXD1; //5            
	delay_bps();      
	SBUF1_bit6 = RXD1; //6            
	delay_bps();      
	SBUF1_bit7 = RXD1; //7         
	delay_bps();   
  
          
}