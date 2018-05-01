/*******************************************************************************
* File Name          : LCDST7567.h
* Author             : 
* Version            : V2.0.1
* Date               : 12/28/2014
* Description        : Header for lcdst7567.c module
*******************************************************************************/
/* Define to prevent recursive inclusion ------------------------------------ */
#ifndef __LCDST7567_H
#define __LCDST7567_H


void delayms(uint16_t ms);
void WrateC(unsigned char com);
void WrateD(unsigned char dat);
void ClearDisplay(unsigned char const *P);
void LcdInit(void);
void Setadd(unsigned char xl,unsigned char yl);
void ShowOneDig(unsigned char col,unsigned char pag,unsigned char d);

#endif 
/* end ------------------------------------ */
