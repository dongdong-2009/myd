
STM32��4x4������̣������ⲿ�жϣ����Լ��������ͬʱ����
#ifndef __COMMON_H 
#define __COMMON_H 
#include "stm32f10x.h" 

/* 4*4������� */ 
void keyboard_init(void); 
void update_key(void); 
extern unsigned char key[4][4];

#endif  
/**************�������.c�ļ�*****************************/
#include "common.h"

struct io_port 
{                                            
GPIO_TypeDef *GPIO_x;                 
unsigned short GPIO_pin;
}; 
static struct io_port key_output[4] = {
{GPIOD, GPIO_Pin_0}, {GPIOD, GPIO_Pin_1},
{GPIOD, GPIO_Pin_2}, {GPIOD, GPIO_Pin_3}
};
static struct io_port key_input[4] = {
{GPIOD, GPIO_Pin_4}, {GPIOD, GPIO_Pin_5},
{GPIOD, GPIO_Pin_6}, {GPIOD, GPIO_Pin_7}
};
unsigned char key[4][4];
void keyboard_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
unsigned char i;

/* ������ɨ������� ����ߵ�ƽ */
/* PA0 PA1 PA2 PA3 ���*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
/* ������ɨ�������� ������ʱ����ߵ�ƽ �ſ�����͵�ƽ */
/* PA4 PA5 PA6 PA7 ����*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IPU; 
    GPIO_Init(GPIOD, &GPIO_InitStructure);

for(i = 0; i < 4; i++)
{
  GPIO_SetBits(key_output[i].GPIO_x, key_output[i].GPIO_pin);
}
}
void update_key(void)
{
unsigned char i, j;
for(i = 0; i < 4; i++)             //i������ڣ������õ͵�ƽ
{
  GPIO_ResetBits(key_output[i].GPIO_x, key_output[i].GPIO_pin);   
  for(j = 0; j < 4; j++)            //j������ڣ���������ʱ��ͨ����Ϊ�͵�ƽ  
  {
   if(GPIO_ReadInputDataBit(key_input[j].GPIO_x, key_input[j].GPIO_pin) == 0)
   {
    key[i][j] = 1; 
   }else{
    key[i][j] = 0;
   }
  }
  GPIO_SetBits(key_output[i].GPIO_x, key_output[i].GPIO_pin);
}
}


