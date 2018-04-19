#ifndef __UART_H
#define __UART_H

#define u8 unsigned char
#define u16 unsigned int

extern u8 star_flag;

void UART1_Iint();
void UART2_Iint();
void Send1_Data(unsigned char a);
void Send2_Data(unsigned char a);
void Serial(); 

#endif 
 