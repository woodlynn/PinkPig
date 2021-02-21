
#ifndef __UART_H
#define __UART_H
#include "stm8s_uart1.h"

/* Private macro -------------------------------------------------------------*/
#define countof(a)   (sizeof(a) / sizeof(*(a)))
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