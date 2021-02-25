
#ifndef __UART_H
#define __UART_H
#include "stm8s_uart1.h"

/* Private macro -------------------------------------------------------------*/

#define USE_485 //if use 485 then deifne this 
/************************************************/
#ifdef USE_485//485 TXRX mod control
#define RS485_PORT 			GPIOD
#define RS485_PIN			GPIO_PIN_4
#define RS485_RECEIVE_MOD	GPIO_WriteLow(RS485_PORT,RS485_PIN)
#define RS485_TRANSMIT_MOD	GPIO_WriteHigh(RS485_PORT,RS485_PIN)
/*************************************************/
#endif

#define countof(a)   (sizeof(a) / sizeof(*(a)))//计算a的成员个数
#define RxBufferSize 32
void Uart_Init(void);
void UART1_SendByte(u8 data);
void UART1_SendString(u8* Data,u16 len);
u8 UART2_ReceiveByte(void);
extern u8 RxBuffer[RxBufferSize];
extern u8 UART_RX_NUM;
extern u8 Uart1_Rx_Flag;
extern u8 Uart1_Tx_Flag;
void UART1_ReciveIRQ(void);

#endif