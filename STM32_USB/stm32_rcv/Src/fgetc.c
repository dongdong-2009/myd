

#include "stdio.h"
#include "stm32f10x_usart.h"


void fgetc(FILE * /*stream*/);

void fgetc(FILE *f /*stream*/)
{

/* Loop until received a char */
while(!(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET))
{
}
  /* Read a character from the USART and RETURN */
USART_ReceiveData(USART1);

}

/*----------------------------------------------------------------------------*/
