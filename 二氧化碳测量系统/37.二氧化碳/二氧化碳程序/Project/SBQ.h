#ifndef __SBQ_H
#define __SBQ_H

#define u8 unsigned char
#define u16 unsigned int

void AD_Init(u8 S_channel);
void Channel(u8 channel);
u8 Get_ADC(u8 channel,u8 time);
void AD_INIT();

#endif  