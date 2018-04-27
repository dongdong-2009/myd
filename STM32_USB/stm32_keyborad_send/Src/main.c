/**
  ******************************************************************************
  * File Name          : main.c
  * Date               : 04/11/2014 15:33:33
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2014 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
//#include "stm32f1xx_hal.h"
//#include "usr.h"
#include "gpio.h"
#include "usr.h"
#include "stdio.h"
#include "stm32f10x_usart.h"
#include "NRF24L01.h"
#include "stdlib.h"
#include "LCDST7567.h"

#define BLACKINPUT GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14)
#define BLACKOUTPUT_H GPIO_SetBits(GPIOB, GPIO_Pin_12)
#define BLACKOUTPUT_L GPIO_ResetBits(GPIOB, GPIO_Pin_12)
#define YELLOWINPUT GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15)
#define YELLOWOUTPUT_H GPIO_SetBits(GPIOB, GPIO_Pin_13)
#define YELLOWOUTPUT_L GPIO_ResetBits(GPIOB, GPIO_Pin_13)




/* USER CODE BEGIN Includes */
uint8_t *nrf24L01tx_buf = NULL;
uint8_t *nrf24L01rx_buf = NULL;
uint8_t *rxdata = NULL;

uint8_t comparedata = 0;
uint8_t revdata = 0;
uint8_t prerevdata = 0;
uint8_t forward = 0;
uint8_t preblackline = 0;
uint8_t blackline = 0;
uint8_t yellowline = 0;




unsigned char *lcdbuf;




/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
#define BAUDRATE1 115200;
#define DEBUG
/* USER CODE END PV */

/* USER CODE BEGIN PFP */
unsigned char keyval = 0xff;
struct io_port 
{                                            
GPIO_TypeDef *GPIO_x;                 
unsigned short GPIO_pin;
	
}; 
static struct io_port key_output[4] = {
{GPIOB, GPIO_Pin_12}, {GPIOB, GPIO_Pin_13},
{GPIOB, GPIO_Pin_14}, {GPIOB, GPIO_Pin_15}
};
static struct io_port key_input[4] = {
{GPIOC, GPIO_Pin_6}, {GPIOC, GPIO_Pin_7},
{GPIOC, GPIO_Pin_8}, {GPIOC, GPIO_Pin_9}
};
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
void update_key(void)
{
	unsigned char i, j;
	keyval = 0xff;
	for(i = 0; i < 4; i++)             //i????,??????
	{

		 GPIO_WriteBit(key_output[i].GPIO_x, key_output[i].GPIO_pin, Bit_SET);

		for(j = 0; j < 4; j++)            //j????,?????????????  
		{
		 if(GPIO_ReadInputDataBit(key_input[j].GPIO_x,  key_input[j].GPIO_pin) == Bit_SET)
		 {
			keyval = i*4+j; 
			break;
		 }
		}
		if(keyval != 0xff)
		{
			GPIO_WriteBit(key_output[i].GPIO_x, key_output[i].GPIO_pin, Bit_RESET);
			break;
		}
		 GPIO_WriteBit(key_output[i].GPIO_x, key_output[i].GPIO_pin, Bit_RESET);
	}
	
}
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/* when the nCount is 0xffff, the time is delayed by 16ms  ,and 0x1 is about 244ns */
void delay(uint32_t nCount)
{
	for(; nCount != 0; nCount--);
}
void ClockInit(void);
void USART1_Config(void);
void SPI1_Config(void);
void KEY_config(void);
void getkey(uint8_t *key_buf);
void measureInit(void);



int main(void)
{

	
	uchar count, buf[TX_ADR_WIDTH]={0,0,0,0,0},twoImpulse = 0;
  GPIO_InitTypeDef GPIO_InitStruct;
	uchar i;
		uchar keyval_0; 

	/* USER CODE BEGIN 1 */
	nrf24L01tx_buf =  (uint8_t *)malloc(1*sizeof(uint8_t));
	*nrf24L01tx_buf = 0xff;
	nrf24L01rx_buf =  (uint8_t *)malloc(1*sizeof(uint8_t));
	*nrf24L01rx_buf = 0x0;
	rxdata = (uint8_t *)malloc(1*sizeof(uint8_t));
	*rxdata = 0x0;


	ClockInit();

	/* USER CODE END 1 */

	/* MCU Configuration----------------------------------------------------------*/

	/* Initialize all configured peripherals */


	/* USART1
	for debug, 115200,8bit,no stop; no interrupt */
	MX_GPIO_Init();
	for (i = 0;i<4;i++)
	{
		GPIO_InitStruct.GPIO_Pin = key_output[i].GPIO_pin;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init(key_output[i].GPIO_x, &GPIO_InitStruct);
		
			GPIO_InitStruct.GPIO_Pin = key_input[i].GPIO_pin;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
		GPIO_Init(key_input[i].GPIO_x, &GPIO_InitStruct);
	}
	USART1_Config();
	#ifdef DEBUG
	printf("\nusart1 is initialized\r\n");
	#endif
	SPI1_Config();
	#ifdef DEBUG
	printf("\n SPI1 is initialized \r\n");
	#endif
	/*
	EXINTPC4_Config();
      */
	EXINTPC4_Config();
	
	#ifdef DEBUG
	printf("\n EXINTPC4 is configured\r\n");
	#endif
	
 	NVIC_Configuration();

	#ifdef DEBUG
	printf("\n NVIC is configured \r\n");
	#endif
	
	NRF24L01B_Config();

	#ifdef DEBUG
	printf("\n NRF24L01 is configured and the RX_ADDR_P0 address is :\r\n");


		SPI_Read_Buf(RX_ADDR_P0,buf,RX_ADR_WIDTH);

		for(count=0;count<RX_ADR_WIDTH;count++)
		{
			printf(" \n Bthe buf %d is %x\r\n", count, buf[count]);
		}
	printf(" \n NRF240L1 is CONFIGURED %x\r\n", SPI_Read(CONFIG));
	#endif
/*
	KEY_config();
	#ifdef DEBUG
	printf("\n KEYPAD is configured \n");
	#endif
	
	LcdInit();
	#ifdef DEBUG
	printf("\n LCD is configured \n");
	#endif
	
	ClearDisplay(mainmenu);
	#ifdef DEBUG
	printf("\n LCD is cleared \n");
	#endif

	*/
	//ShowOneDig(10,1,1);
	//ShowOneDig(10,3,2);
	
	/*END OF USART1*/

	/* USER CODE BEGIN 2 */

	/* USER CODE END 2 */

	/* USER CODE BEGIN 3 */
	/* Infinite loop */
	GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_SET);
	SPI_RW_Reg(FLUSH_RX,0xff);
	SPI_RW_Reg(FLUSH_TX,0xff);
		if(EXTI_GetITStatus(EXTI_Line4)!=RESET)//判断标志，中断是否发生

    {
        EXTI_ClearITPendingBit(EXTI_Line4); //清标志位

    }
	//SetRX_Mode();
	GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_SET);
	SPI_RW_Reg(NRF24L01_WRITEREG+STATUS,SPI_Read(STATUS));
	measureInit();

	while (1)
	{
		uchar sta, count = 100;

		#if 1
		keyval_0 = keyval;
		update_key();
		if(keyval_0 == keyval)
		{
			if(keyval != 0xff)
			{
				*nrf24L01tx_buf = keyval + 0x58;
				//*nrf24L01tx_buf = (uint8_t)(HID_Buffer[0] + 0x28);
				nRF24L01_TxPacket(nrf24L01tx_buf);
				//USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, HID_Buffer,65);
				printf("keyval: %x",*nrf24L01tx_buf-0x58);
				//HAL_UART_Transmit(&huart1, HID_Buffer, 11, 10);
				keyval = 0xff;
			}
		}
				// = 0x59; 
		//nRF24L01_TxPacket(nrf24L01tx_buf);

  	delay(0x500B);  //5ms  delay*/
		delay(0x500B);  //5ms  delay*/
  #endif
  }
  /* USER CODE END 3 */

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}


  
*/ 


	void measureInit(void)
	
{

	
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	/*Configure GPIO pin : PB */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pin : PB */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOB, &GPIO_InitStruct);


}

	void ClockInit(void)
{
	  /* begin of HSE configuration*/

  	RCC_DeInit();

  	RCC_HSEConfig(RCC_HSE_ON);
	while(RCC_WaitForHSEStartUp() == ERROR);  


	/*the begin of PLL configure       48MHz        */
	RCC_PLLCmd(DISABLE);
	RCC_PLLConfig(RCC_PLLSource_HSE_Div2,RCC_PLLMul_6);
	RCC_PLLCmd(ENABLE);  
	/*the end of PLL configure     48MHz            */  

	/*the begin of SYSCLK configure       48MHz        */
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

	while(RCC_GetSYSCLKSource() != 0x08);

	/*the end of SYSCLK configure       48MHz        */
		
	/*the begin of HCLK configure		48MHz		 */
	RCC_HCLKConfig(RCC_SYSCLK_Div1);
	/*the END of HCLK configure 	 48MHz		  */

	/*the begin of APB2 configure		12MHz		 */  
	RCC_PCLK2Config(RCC_HCLK_Div4);
	/*the END of APB2 configure		12MHz		 */  

	/*the begin of APB1 configure		12MHz		 */  
	RCC_PCLK1Config(RCC_HCLK_Div4);
	/*the END of APB1 configure		12MHz		 */  

	/*the begin of USBCLK configure		48MHz		 */  
	RCC_USBCLKConfig(RCC_USBCLKSource_PLLCLK_Div1);
	/*the END of USBCLK configure		48MHz		 */

	/*the begin of ADCCLK configure		 2MHz		  */  
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	/*the END of ADCCLK configure		 2MHz		  */  

	/*the begin of RTC  configure		 2MHz		  */   
	RCC_LSEConfig(RCC_LSE_ON);
	RCC_LSICmd(DISABLE);
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
	RCC_RTCCLKCmd(ENABLE);
	/*the begin of END  configure		2MHz		 */   

	/*the begin of AHB peripheral clock  configure		 2MHz		  */  
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_SRAM,ENABLE);
	/*the END of AHB peripheral clock	configure		2MHz		 */  
	}

	void USART1_Config(void)
	{
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct1;
	USART_ClockInitTypeDef USART_ClockInitStruct1;
	
	/** USART1 GPIO Configuration  
	PA9   ------> USART1_TX
	PA10   ------> USART1_RX
	*/
	
	/*Enable or disable APB2 peripheral clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	/*Configure GPIO pin : PA */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	/*Configure GPIO pin : PA */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	/* end of GPIO Configuration                        */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);      /*clock enable*/
	USART_ClockInitStruct1.USART_Clock = USART_Clock_Disable; // 时钟低电平活动 ；
	USART_ClockInitStruct1.USART_CPOL = USART_CPOL_Low;	// 时钟低电平 ；
	USART_ClockInitStruct1.USART_CPHA = USART_CPHA_2Edge; // 时钟第二个边沿进行数据捕获 ；
	USART_ClockInitStruct1.USART_LastBit = USART_LastBit_Disable; // 最后一位数据的时钟脉冲不从SCLK输出 ；
	USART_ClockInit(USART1, &USART_ClockInitStruct1);
	USART_StructInit(&USART_InitStruct1);
	USART_ITConfig(USART1,USART_IT_TC|USART_IT_CTS|USART_IT_ERR|USART_IT_TXE|USART_IT_RXNE,DISABLE);
	USART_InitStruct1.USART_BaudRate = BAUDRATE1;
	USART_Cmd(USART1,ENABLE);
	USART_Init(USART1,&USART_InitStruct1);
	}
	void KEY_config(void)
		{
			GPIO_InitTypeDef GPIO_InitStruct;

			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

			/*Configure GPIO pin : PC */
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
			GPIO_InitStruct.GPIO_Mode =   GPIO_Mode_IPU;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
			GPIO_Init(GPIOC, &GPIO_InitStruct);
		}
	void getkey(uint8_t *key_buf)
		{
		uint16_t flag;

		flag = GPIO_ReadInputData(GPIOC) & 0x03c0;
		switch(flag)
			{
			case 0x01c0:
				{

					*key_buf = 0x01;
					break;
				}
			case 0x02c0: 
								{

					*key_buf = 0x02;
					break;
				}
			case 0x0340: 
											{

					*key_buf = 0x03;
					break;
				}
			case 0x0380: 
															{

					*key_buf = 0x04;
					break;
				}
			default: 
																			{

					*key_buf = 0x0;
					break;
				}

		}

		}
		
void EXTI4_IRQHandler(void)
{
	unsigned char sta,flag=0x01;

	if(EXTI_GetITStatus(EXTI_Line4)!=RESET)//判断标志，中断是否发生

    {
        EXTI_ClearITPendingBit(EXTI_Line4); //清标志位

    }
	printf("\r\n intr \r\n");

	//SetRX_Mode();
	GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_SET);
	sta = SPI_Read(STATUS);	// read register STATUS's value
	sta &= (RX_DR | TX_DS | MAX_RT);
	
		while(flag)
		{
		SPI_RW_Reg(NRF24L01_WRITEREG+STATUS,SPI_Read(STATUS));
		flag = SPI_Read(STATUS);	// read register STATUS's value
		flag &= (RX_DR | TX_DS | MAX_RT);
			}			
			
	switch(sta)
		{
		case RX_DR:
				{
					
					SPI_Read_Buf(RD_RX_PLOAD,nrf24L01rx_buf,TX_PLOAD_WIDTH);
					SPI_RW_Reg(FLUSH_RX,0xff);
					printf("\n receive data success \r\n");
					break;  // read receive payload from RX_FIFO buffer
			}
		
			default: 
				{
						SPI_RW_Reg(FLUSH_RX,0xff);
						SPI_RW_Reg(FLUSH_TX,0xff);
						break;
					}

			}
		
		//GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_RESET);

}


	/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
