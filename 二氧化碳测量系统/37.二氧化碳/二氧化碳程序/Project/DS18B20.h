#ifndef __DS18B20_H
#define __DS18B20_H

#define uchar unsigned char
#define uint unsigned int

void Init_DS18B20(void);
uint get_temp(void);
void chuli(uint temperature,uchar *Data);
#endif 