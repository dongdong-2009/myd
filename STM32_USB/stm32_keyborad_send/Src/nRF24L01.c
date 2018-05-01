//
// nRF24L01.c

#include "nRF24L01.h"
#include "stm32f10x_spi.h"
#include "stm32f10x_exti.h"
#include "stdio.h"
#include "usr.h"
#define NSS_L GPIO_ResetBits(GPIOA, GPIO_Pin_4)
#define NSS_H GPIO_SetBits(GPIOA, GPIO_Pin_4)
#define NUMBER1
#ifdef NUMBER1
const BYTE  TX_ADDRESS[TX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x01}; // Define a static TX address
const BYTE  RX_ADDRESS[RX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x01}; // Define a static RX address
#endif
#ifdef NUMBER2
const BYTE  TX_ADDRESS[TX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x02}; // Define a static TX address
const BYTE  RX_ADDRESS[RX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x02}; // Define a static RX address
#endif
#ifdef NUMBER3
const BYTE  TX_ADDRESS[TX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x03}; // Define a static TX address
const BYTE  RX_ADDRESS[RX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x03}; // Define a static RX address
#endif
#ifdef NUMBER4
const BYTE  TX_ADDRESS[TX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x04}; // Define a static TX address
const BYTE  RX_ADDRESS[RX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x04}; // Define a static RX address
#endif







/* when the nCount is 0xffff, the time is delayed by 16ms  ,and 0x1 is about 244ns */
void usdelay(uint32_t nCount)
{
	uint8_t i=5;
	for(;i != 0;i--)
		{
	for(; nCount != 0; nCount--);
		}
}





void SPI1_Config(void)
{

	SPI_InitTypeDef SPI1_InitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	//SPI_I2S_DeInit(SPI1);

	/** SPI1 GPIO Configuration  
	PA4   ------> SPI1_NSS
	PA5   ------> SPI1_SCK
	PA6   ------> SPI1_MISO
	PA7   ------> SPI1_MOSI
	*/
	
	/*Enable or disable APB2 peripheral clock */
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	/*Configure GPIO pin : PA  */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	/*Configure GPIO pin : PA */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	/*Configure GPIO pin : PA */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	/*end of GPIO configuariton     */
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	SPI_Cmd(SPI1, DISABLE);

	SPI_StructInit(&SPI1_InitStruct);
	SPI1_InitStruct.SPI_Mode = SPI_Mode_Master;
	SPI1_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
	SPI1_InitStruct.SPI_NSS = SPI_NSS_Soft;
	SPI_Init(SPI1, &SPI1_InitStruct);
	
	SPI_CalculateCRC(SPI1, DISABLE);
	SPI_I2S_ITConfig(SPI1,SPI_I2S_IT_TXE|SPI_I2S_IT_ERR|SPI_I2S_IT_RXNE, DISABLE);
	SPI_SSOutputCmd(SPI1, DISABLE);
	SPI_DataSizeConfig(SPI1,SPI_DataSize_8b);
	SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Set);
	SPI_Cmd(SPI1, ENABLE);

	

}

void EXINTPC4_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;

	/*Enable or disable APB2 peripheral clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	/*Configure GPIO pin : PC */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource4);
	EXTI_StructInit(&EXTI_InitStruct);
	EXTI_InitStruct.EXTI_Line = EXTI_Line4;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
	EXTI_ClearITPendingBit(EXTI_Line4);
}

void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    #ifdef VECT_TAB_RAM
        NVIC_SetVectorTable(NVIC_VectTab_RAM,0X0);//向量表位于RAM区
    #else
        NVIC_SetVectorTable(NVIC_VectTab_FLASH,0X0);//向量表位于FLASH区
    #endif
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//选择第一组
    //使能EXTI4中断，PC4
    NVIC_InitStructure.NVIC_IRQChannel=EXTI4_IRQn ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;// 指定抢占式优先级别0
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=4;// 指定响应优先级别0
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//
    NVIC_Init(&NVIC_InitStructure);

}


void NRF24L01B_Config(void)
{
	
	GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_SET);
	SPI_RW_Reg(NRF24L01_WRITEREG + CONFIG, 0x0b); // Set PWR_UP bit, enable CRC(2 bytes) &Prim:RX. RX_DR enabled. no interrupt.
	SPI_RW_Reg(NRF24L01_WRITEREG + EN_AA, 0x01);
	SPI_RW_Reg(NRF24L01_WRITEREG + EN_RXADDR, 0x01); // Enable Pipe0
	SPI_RW_Reg(NRF24L01_WRITEREG + SETUP_AW, 0x03); // Setup address width=5 bytes
	SPI_RW_Reg(NRF24L01_WRITEREG + SETUP_RETR, 0x1a); // 500us + 86us, 10 retrans...
	SPI_RW_Reg(NRF24L01_WRITEREG + RF_CH, 0);
	SPI_RW_Reg(NRF24L01_WRITEREG + RF_SETUP, 0x07); // TX_PWR:0dBm, Datarate:1Mbps,	LNA:HCURR
	SPI_RW_Reg(NRF24L01_WRITEREG + RX_PW_P0, RX_PLOAD_WIDTH);
	SPI_Write_Buf(NRF24L01_WRITEREG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);

	SPI_Write_Buf(NRF24L01_WRITEREG + RX_ADDR_P0, RX_ADDRESS, RX_ADR_WIDTH);
	


	
	GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_RESET);

	
}


/**************************************************
Function: SPI_RW();

  Description:
  Writes one byte to nRF24L01, and return the byte read
  from nRF24L01 during write, according to SPI protocol
****************************************************/
uchar SPI_RW(uchar byte)
{

	BYTE count=0, rev_data=0;
	/*uchar bit_ctr;
   	for(bit_ctr=0;bit_ctr<8;bit_ctr++) // output 8-bit
   	{
		MOSI = (byte & 0x80);         // output 'byte', MSB to MOSI
		byte = (byte << 1);           // shift next bit into MSB..
		SCK = 1;                      // Set SCK high..
		byte |= MISO;       		  // capture current MISO bit
		SCK = 0;            		  // ..then set SCK low again
   	}
   	*/
   	SPI_I2S_SendData(SPI1,byte);
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_BSY)==SET);
		while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE)==RESET)
		{
		count++;
		if(count>0x20)

			{
				return ERROR;
			}
		}
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE)==SET)
		{
	rev_data = (BYTE)SPI_I2S_ReceiveData(SPI1);

		}
	
    return(rev_data);           		  // return read byte
}
/**************************************************/

/**************************************************
Function: SPI_RW_Reg();

  Description:
  Writes value 'value' to register 'reg'
**/
uchar SPI_RW_Reg(BYTE reg, BYTE value)
{
	uchar status;
	
	NSS_L;                   // CSN low, init SPI transaction
	status = SPI_RW(reg);      // select register
	SPI_RW(value);             // ..and write value to it..
	NSS_H;                   // CSN high again
	/*
	SPI_I2S_SendData(SPI1,reg);
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_BSY)==SET);
	SPI_I2S_SendData(SPI1,value);
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_BSY)==SET);
	*/
	return(status);            // return nRF24L01 status byte
}
/**************************************************/

/**************************************************
Function: SPI_Read();

  Description:
  Read one byte from nRF24L01 register, 'reg'
**************************************************/
BYTE SPI_Read(BYTE reg)
{
	BYTE reg_val=0;
	NSS_L;
	//CSN = 0;                // CSN low, initialize SPI communication...
	SPI_RW(reg);            // Select register to read from..
	/*
	SPI_I2S_SendData(SPI1,NRF24L01_READREG+reg);
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_BSY)==SET);
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE)==RESET)
		{
		count++;
		if(count>0x20)

			{
				printf("\n error\n");

			return ERROR;
			}
		}
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE)==SET)
		{
	reg_val = (BYTE)SPI_I2S_ReceiveData(SPI1);

	printf("\n I am in the SPI_READ function, and the reg_val is %x\n", reg_val);

		}
	*/
	reg_val = SPI_RW(0);    // ..then read registervalue
	//CSN = 1;                // CSN high, terminate SPI communication
	NSS_H;
	return(reg_val);        // return register value
}
/**************************************************/

/**************************************************
Function: SPI_Read_Buf();

  Description:
  
**************************************************/
uchar SPI_Read_Buf(BYTE reg,BYTE *pBuf, BYTE bytes)
{
                        
	uchar status,byte_ctr;
	NSS_L;                    		// Set CSN low, init SPI tranaction
	status = SPI_RW(reg);       		// Select register to write to and read status byte
	for(byte_ctr=0;byte_ctr<bytes;byte_ctr++)
		pBuf[byte_ctr] = SPI_RW(0);    // 
    NSS_H;
	return(status);                    // return nRF24L01 status byte

}
/**************************************************/

/**************************************************
Function: SPI_Write_Buf();

  Description:
  Writes contents of buffer '*pBuf' to nRF24L01
  Typically used to write TX payload, Rx/Tx address
**************************************************/
uchar SPI_Write_Buf(BYTE reg,const BYTE *pBuf, BYTE bytes)
{
	uchar status,byte_ctr;
	
	NSS_L;                   
	status = SPI_RW(reg);   
	for(byte_ctr=0; byte_ctr<bytes; byte_ctr++) //
		SPI_RW(*pBuf++);
	NSS_H;                 // Set CSN high again
	return(status);          // 
	
}
/**************************************************/

/**************************************************
Function: RX_Mode();

  Description:
  
**************************************************/
void SetRX_Mode(void)
{
	GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_SET);
	SPI_Write_Buf(NRF24L01_WRITEREG + RX_ADDR_P0, RX_ADDRESS, RX_ADR_WIDTH); // Use the same address on the RX device as the TX device
	
	SPI_RW_Reg(NRF24L01_WRITEREG + EN_AA, 0x01);      // 
	SPI_RW_Reg(NRF24L01_WRITEREG + EN_RXADDR, 0x01);  // 
	SPI_RW_Reg(NRF24L01_WRITEREG + RF_CH, 0);        // 
	SPI_RW_Reg(NRF24L01_WRITEREG + RX_PW_P0, RX_PLOAD_WIDTH); 
	SPI_RW_Reg(NRF24L01_WRITEREG + RF_SETUP, 0x07);   
	SPI_RW_Reg(NRF24L01_WRITEREG + CONFIG, 0x0b);     
	
	GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_RESET);
	usdelay(130);

}
/**************************************************/
unsigned char nRF24L01_RxPacket(unsigned char* rx_buf)
{
  unsigned char revale=0;
	unsigned char sta,flag;
	//SetRX_Mode();
	GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_SET);
	sta=SPI_Read(STATUS);	// read register STATUS's value
	flag=sta&RX_DR;
	if (flag)				// if receive data ready (RX_DR) interrupt
	{
	    //CE = 0; 
	    //GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_RESET);
		SPI_Read_Buf(RD_RX_PLOAD,rx_buf,TX_PLOAD_WIDTH);// read receive payload from RX_FIFO buffer
		revale =1;//we have receive data
	}
	SPI_RW_Reg(NRF24L01_WRITEREG+STATUS,sta);// clear RX_DR or TX_DS or MAX_RT interrupt flag

	GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_RESET);
	return revale;
}

/**************************************************
Function: nRF24L01_TxPacket();

  Description:
  This function initializes one nRF24L01 device to
  TX mode, set TX address, set RX address for auto.ack,
  fill TX payload, select RF channel, datarate & TX pwr.
  PWR_UP is set, CRC(2 bytes) is enabled, & PRIM:TX.
  
	ToDo: One high pulse(>10us) on CE will now send this
	packet and expext an acknowledgment from the RX device.
**************************************************/
void nRF24L01_TxPacket(unsigned char const * tx_buf)
{
	//CE=0;
	uchar sta, count = 100;
	sta=SPI_Read(STATUS);
	printf("\n status is :%x\r\n", sta);
	sta &= TX_FULL;
	//#ifdef DEBUG
	printf("\n the sta is :%x\r\n", sta);
	//#endif
	if(sta ==0x1)
		{
	while (count--);
	SPI_RW_Reg(FLUSH_TX,0xff);
		}
	
	GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_SET);
	
	SPI_Write_Buf(NRF24L01_WRITEREG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // 
	SPI_Write_Buf(NRF24L01_WRITEREG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); 
	SPI_Write_Buf(WR_TX_PLOAD, tx_buf, TX_PLOAD_WIDTH); 
	
	SPI_RW_Reg(NRF24L01_WRITEREG + EN_AA, 0x01);      // 
	SPI_RW_Reg(NRF24L01_WRITEREG + EN_RXADDR, 0x01);  // 
	SPI_RW_Reg(NRF24L01_WRITEREG + SETUP_RETR, 0x1a); //
	SPI_RW_Reg(NRF24L01_WRITEREG + RF_CH, 0);        // 
	SPI_RW_Reg(NRF24L01_WRITEREG + RF_SETUP, 0x07);   // 
	SPI_RW_Reg(NRF24L01_WRITEREG + CONFIG, 0x0a);     // 
	//CE=1;
	GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_RESET);
	
	sta=SPI_Read(STATUS);
	//#ifdef DEBUG
	printf("\n the status is :");
	//#endif
	
	while(sta == 0x00);
	
	//#ifdef DEBUG
	printf(" %d\r\n", sta);
	//#endif
	/*
	sta &= (TX_DS | MAX_RT);
	while (sta);
	P?
	*/
//	inerDelay_us(10);
	//sta=SPI_Read(STATUS);	// read register STATUS's value
	//SPI_RW_Reg(NRF24L01_WRITEREG+STATUS,SPI_Read(NRF24L01_READREG+STATUS));	// clear interrupt flag(TX_DS)
	
}


/**************************************************/
