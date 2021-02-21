


/* 包含系统头文件 */

/* 包含自定义头文件 */
#include "keyled.h"
#include "stm8s_gpio.h"
#include "tim4.h"

/* 自定义新类型 */

/* 自定义宏 */

/* 全局变量定义 */

/* 简单的延时函数 */

static void Delay(u32 nCount)
{
	unsigned int i;
	
  	for (i = 0; i < 2000; i++) {
		for (; nCount > 0; nCount--)
			;
  	}
}

/*******************************************************************************
 * 名称: Key_Init
 * 功能: 按键外设GPIO引脚初始化操作
 * 形参: 无
 * 返回: 无
 * 说明: 无 
 ******************************************************************************/
void Key_Init(void)
{
    GPIO_Init(KEY_PORT, KEY_M, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(KEY_PORT, KEY_D, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(KEY_PORT, KEY_U, GPIO_MODE_IN_PU_NO_IT);	/* 与按键相连的引脚设置为输入模式 */
  //  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_FALL_ONLY);
}


/*******************************************************************************
 * 名称: Key_Scan
 * 功能: 读取一个按键的状态
 * 形参: key -> 要读取的按键
 * 返回: 按键的状态 0--按下 1--未按下 2---按住
 * 说明: 无 
 ******************************************************************************/
u8 Key_State_Check(GPIO_Pin_TypeDef key)
{
	u32 i=200000;
        u8 KeyStatus;
	KeyStatus = KEY_UP;
	
	if (1) {
		if(!GPIO_ReadInputPin(KEY_PORT, key))
		{
			_delay_ms(10);	/* 消抖 */
			if(!GPIO_ReadInputPin(KEY_PORT, key))
			{
				while(!GPIO_ReadInputPin(KEY_PORT, key))
                                {
                                        i--;
                                        if (i==0) 
                                        {
                                          i=200000;
                                          KeyStatus=KEY_HOLD;
                                          return KeyStatus;
                                        
                                        }
                                        
                                        /*松手释放*/
                                
                                }
					
				KeyStatus = KEY_DOWN;
			}
		}		
	} 

	return KeyStatus;
}
void KeyReleaseWait (GPIO_Pin_TypeDef key)
{
    u8 i=255;
    while(!GPIO_ReadInputPin(KEY_PORT, key));
    i--;
    while(!GPIO_ReadInputPin(KEY_PORT, key));
    
}


/*******************************************************************************
 * 名称: LED_Init
 * 功能: LED外设GPIO引脚初始化操作
 * 形参: 无
 * 返回: 无
 * 说明: 无 
 ******************************************************************************/
void LED_Init(void)
{
	GPIO_Init(LED_PORT, LED, GPIO_MODE_OUT_PP_HIGH_FAST );	
        LEDOFF;
}

/*
u8 Key_Check(void)

{
    u8 keystatus,checkkey;
    checkkey = Key_State_Check(KEY_M);
    if(checkkey==KEY_DOWN)   keystatus=KEY1_DOWN;
    if(checkkey==KEY_HOLD)   keystatus=KEY1_HOLD;
    checkkey = Key_State_Check(KEY_D);
    if(checkkey==KEY_DOWN)   keystatus=KEY2_DOWN;
    if(checkkey==KEY_HOLD)   keystatus=KEY2_HOLD;
    checkkey = Key_State_Check(KEY_U);
    if(checkkey==KEY_DOWN)   keystatus=KEY3_DOWN;
    if(checkkey==KEY_HOLD)   keystatus=KEY3_HOLD;
    return keystatus;
   
}

*/
/*
static void Delay(s32 nCount)
{
	u32 i = 0;
	
	for (; nCount > 0; nCount--) {
		for (i = 0; i < 1000; i++) {
			;
		} 
	}
}

*/
