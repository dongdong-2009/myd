#ifndef __LCD1602_H
#define __LCD1602_H

#define u8 unsigned char
#define u16 unsigned int

void LCD_Write(bit style, unsigned char input);
void LCD_SetDisplay(unsigned char DisplayMode);
void LCD_SetInput(unsigned char InputMode);
void LCD_Initial();
void GotoXY(unsigned char x, unsigned char y);
void Print(unsigned char *str);
void LCD_Print(unsigned char x, unsigned char y, unsigned char *str);
void LCD_PutChar(unsigned char x, unsigned char y, unsigned char *str);
unsigned int Strings(unsigned char *s);
void LCD_Put5x8(unsigned char x, unsigned char  y, unsigned char g[2]);
void TFT_PutString(unsigned char x, unsigned char y, unsigned char *s); 
void delayms(u16 ms);
#endif 
 



