

/******************** (C) COPYRIGHT  ��۵���Ƕ��ʽ���������� ***************************
  ��۵���STM8������Ӳ������
    |--------------------|
    |  USART2_RX-PA4     |
    |  USART2_TX-PA5     |
    |--------------------|

****************************************************************************************/

#include "uart.h"
#include "stm8s.h"


/* ********************************************
UART1  configured as follow:
  - BaudRate = 115200 baud  
  - Word Length = 8 Bits
  - One Stop Bit
  - No parity
  - Receive and transmit enabled
 -  Receive interrupt
  - UART1 Clock disabled
*********************************************/

u8 RxBuffer[RxBufferSize];
u8 TxBuffer[TxBufferSize];
u8 UART_RX_NUM=0;
u8 Uart1_Rx_Flag=0;
u8 Uart1_Tx_Flag=0;


void Uart_Init(void)
{
  #ifdef USE_485
    GPIO_Init(RS485_PORT, RS485_PIN, GPIO_MODE_OUT_PP_LOW_FAST );
    RS485_RECEIVE_MOD;
  #endif

    UART1_DeInit();
    UART1_Init((u32)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, \
    UART1_PARITY_NO , UART1_SYNCMODE_CLOCK_DISABLE , UART1_MODE_TXRX_ENABLE);
    UART1_ITConfig(UART1_IT_RXNE_OR,ENABLE  );
    UART1_Cmd(ENABLE );
  
}

void UART1_SendByte(u8 data)
{
  #ifdef USE_485
    RS485_TRANSMIT_MOD;   //485 control 
  #endif  
    UART1_SendData8((unsigned char)data);
  /* Loop until the end of transmission */
  while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
  #ifdef USE_485
    RS485_RECEIVE_MOD;   
  #endif  

}

void UART1_SendString(u8* Data,u16 len)
{
  u16 i=0;
  for(;i<len;i++)
    UART1_SendByte(Data[i]);
  
}

u8 UART1_ReceiveByte(void)
{
     u8 USART2_RX_BUF; 
     while (UART1_GetFlagStatus(UART1_FLAG_RXNE) == RESET);
     USART2_RX_BUF=UART1_ReceiveData8();
     return  USART2_RX_BUF;
    
}

char* itoa(int num,char* str,int radix)
{
    char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";//������
    unsigned unum;//���Ҫת���������ľ���ֵ,ת�������������Ǹ���
    int i=0,j,k;//i����ָʾ�����ַ�����Ӧλ��ת��֮��i��ʵ�����ַ����ĳ��ȣ�ת����˳��������ģ��������������k����ָʾ����˳��Ŀ�ʼλ��;j����ָʾ����˳��ʱ�Ľ�����
 
    //��ȡҪת���������ľ���ֵ
    if(radix==10&&num<0)//Ҫת����ʮ�����������Ǹ���
    {
        unum=(unsigned)-num;//��num�ľ���ֵ����unum
        str[i++]='-';//���ַ�����ǰ������Ϊ'-'�ţ�����������1
    }
    else unum=(unsigned)num;//����numΪ����ֱ�Ӹ�ֵ��unum
 
    //ת�����֣�ע��ת�����������
    do
    {
        str[i++]=index[unum%(unsigned)radix];//ȡunum�����һλ��������Ϊstr��Ӧλ��ָʾ������1
        unum/=radix;//unumȥ�����һλ
 
    }while(unum);//ֱ��unumΪ0�˳�ѭ��
 
    str[i]='\0';//���ַ���������'\0'�ַ���c�����ַ�����'\0'������
 
    //��˳���������
    if(str[0]=='-') k=1;//����Ǹ��������Ų��õ������ӷ��ź��濪ʼ����
    else k=0;//���Ǹ�����ȫ����Ҫ����
 
    char temp;//��ʱ��������������ֵʱ�õ�
    for(j=k;j<=(i-1)/2;j++)//ͷβһһ�Գƽ�����i��ʵ�����ַ����ĳ��ȣ��������ֵ�ȳ�����1
    {
        temp=str[j];//ͷ����ֵ����ʱ����
        str[j]=str[i-1+k-j];//β����ֵ��ͷ��
        str[i-1+k-j]=temp;//����ʱ������ֵ(��ʵ����֮ǰ��ͷ��ֵ)����β��
    }
 
    return str;//����ת������ַ���
 
}


void UART1_ReciveIRQ(void)
{
    u8 Res;
    
    if(UART1_GetITStatus(UART1_IT_RXNE )!= RESET)  
    {
      
	Res =UART1_ReceiveData8();
        
              
        /*(USART1->DR);��ȡ���յ�������,���������ݺ��Զ�ȡ��RXNE���жϱ�־λ*/
        if (UART_RX_NUM==0)
        {
            if (!(Res==0xEE))  UART_RX_NUM=0;             
        }
        else if (UART_RX_NUM==1)
        {
            if (!((Res==0x03)||(Res==0x02)))  UART_RX_NUM=0;
        }
        RxBuffer[ UART_RX_NUM]=Res ;
        UART_RX_NUM++;
        if( UART_RX_NUM>20)
        {
                UART_RX_NUM=0;
        }
        if ((UART_RX_NUM==RxBuffer[2])&&(RxBuffer[0]==0xEE)&&((RxBuffer[1]==0x03)||(RxBuffer[1]==0x02))&&(RxBuffer[UART_RX_NUM-1]==0xFF)&&(RxBuffer[UART_RX_NUM-2]==0x55))
         
        {
                UART_RX_NUM=0; 
                UART1_Rx_Flag=1;
        
        }	
    }
}

