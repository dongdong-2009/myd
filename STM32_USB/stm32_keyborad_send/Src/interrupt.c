


 ex_int()
 {
	 if (GPIO_ReadInputDataBit(GPIOA,1)==0)
	 {
		 frontCounter++;
	 }
	 else 
	 {
		 if frontCounter ==(--(int)0);
		 frontCounter--;
	 }
 }
 
 while (1)
 {
	 pa0Temp = GPIO_ReadInputDataBit(GPIOA,0);
	 pa1Temp = GPIO_ReadInputDataBit(GPIOA,1);
	 GPIO_WriteBit(GPIOA, 0, pa0Temp);
	 GPIO_WriteBit(GPIOA, 1, pa1Temp);
	 if(