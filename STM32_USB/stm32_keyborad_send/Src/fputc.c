



#include "stdio.h"
#include "stm32f10x_usart.h"
#include "usr.h"

int fputc(int ch, FILE *f);

int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, (uint8_t) ch);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
	return ch;
}

/*----------------------------------------------------------------------------*/
