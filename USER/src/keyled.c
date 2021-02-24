


/* 包含系统头文件 */

/* 包含自定义头文件 */
#include "keyled.h"
#include "stm8s_gpio.h"
#include "tim4.h"




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


