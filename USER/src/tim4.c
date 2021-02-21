#include "tim4.h"
#include "iwdg.h"
#include "filter.h"
u16 TimeTick=0;
u8  TimeSecondTick=0;
u8 TimeMintueTick=0,TimeHourTick=0;
u16 Hour,KHour;
u8 Mintue,HfSecond;
FlagStatus FlashTick,QuarterTick,QTick,FTick,HSTick,UartSendTick;

void _delay_us(u16 z)     //微秒延时
{
  while(z--)
  {
    nop();nop();nop();nop();
  }
}
/*void _delay_us(u16 nCount)
{
//   nCount*=2;
  {
    while (nCount != 0) 
    {
      nCount--; 
    } 
  }
}*/
void _delay_ms(u16 nCount)
{
    u16 i;
    for (i=0;i<nCount;i++)
    {
        _delay_us(1500);
    }
   
}

/*******************************************************************************
 * 名称: Time4_Init
 * 功能: 定时器4初始化
 * 形参: 无
 * 返回: 无
 * 说明: 定时器4用来一个1MS的时间基准
 ******************************************************************************/
void Time4_Init(void)
{
    TIM4_TimeBaseInit(TIM4_PRESCALER_128, 124);//理论定时中断时间8us*125=1MS
    TIM4_PrescalerConfig(TIM4_PRESCALER_128, TIM4_PSCRELOADMODE_IMMEDIATE);
    TIM4_ARRPreloadConfig(ENABLE);
    TIM4_ClearFlag(TIM4_FLAG_UPDATE);
    TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
    TIM4_Cmd(ENABLE);
}

void Time1msCount (void)
{   
   u8 qt=0,ft=0;
   u8 i;
    TimeTick++;
    if (TimeTick==250)
    {   
        IWDG_ReloadCounter();         //喂狗
        QuarterTick=~QuarterTick;
        TimeTick=0;
        qt=1;
        QTick=1;
    }
    if (qt)
    {
        qt=0;
        
        FlashTick=~FlashTick;
        FTick=1;
        if (FlashTick) 
        {
//            FTick=1;
//        TimeSecondTick=1;
            HSTick=1;
            HfSecond++;
            if (HfSecond%2==0)  UartSendTick=1;
        }
        if (HfSecond==120)
        {
            HfSecond=0;
            TimeMintueTick=1;
          
        }
        if (TimeMintueTick==1)
        {
            TimeMintueTick=0;
            Mintue++;
            if (FlagFilterCount)             //////////////如果泵标志开滤芯计时
            {
                for (i=0;i<6;i++)
                {
                    filterusedminute[i]++;
                    if (filterusedminute[i]==60)
                    {
                        filterusedhour[i]++;
                        filterusedminute[i]=0;
                    }
                }
            
            }
            if (Mintue==60)
            {
                Mintue=0;
                TimeHourTick=1;
                
            }
        }
        if (TimeHourTick==1)
        {
            TimeHourTick=0;
            Hour++;
            
            if (Hour==1000)
            {
                Hour=0;
                KHour++;
                
            }
        }
        
    }
    

}

 
        
      
