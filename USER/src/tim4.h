#include "stm8s.h"



void Time4_Init(void);
void Time1msCount (void);
void _delay_us(u16 nCount);
void _delay_ms(u16 nCount);
extern u16 Hour,KHour;
extern u8 Mintue,HfSecond;
extern FlagStatus FlashTick,QuarterTick,QTick,FTick,HSTick,UartSendTick;