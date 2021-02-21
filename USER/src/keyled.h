

#ifndef __KEY_SCAN_H
#define __KEY_SCAN_H

/* 包含系统头文件 */

/* 包含自定义头文件 */
#include "stm8s.h"

/* 自定义数据类型 */

/* 自定义常量宏和表达式宏 */
/* LED 灯所接的GPIO端口定义 */
#define KEY_PORT        GPIOA	/* 定义按键外设所接GPIO端口 */


/* LED灯所接的GPIO引脚定义 */
#define KEY_M     	GPIO_PIN_5
#define KEY_D           GPIO_PIN_4
#define KEY_U           GPIO_PIN_3


#define KEY_DOWN   	0	/* 按键按下低电平 */
#define KEY_UP 	 	1	/* 按键松开高电平 */
#define KEY_HOLD        2       //长按
#define KEY1_DOWN   	3	
#define KEY2_DOWN   	4
#define KEY3_DOWN   	5
#define KEY1_HOLD   	6       //长按
#define KEY2_HOLD  	7
#define KEY3_HOLD       8
#define CHECKKEYON      0
#define CHECKKEYOFF     1
#define LED_PORT        GPIOG
#define LED             GPIO_PIN_0

#define LEDON            GPIO_WriteHigh(LED_PORT,LED);
#define LEDOFF           GPIO_WriteLow(LED_PORT,LED);
#define LEDREVERSE       GPIO_WriteReverse(LED_PORT,LED);
/* 声明给外部使用的变量 */

/* 声明给外部使用的函数 */

/*******************************************************************************
 * 名称: Key_Init
 * 功能: 按键外设GPIO引脚初始化操作
 * 形参: 无
 * 返回: 无
 * 说明: 无 
 ******************************************************************************/
void Key_Init(void);

/*******************************************************************************
 * 名称: Key_Scan
 * 功能: 读取一个按键的状态
 * 形参: key -> 要读取的按键
 * 返回: 按键的状态 0--按下 1--未按下
 * 说明: 无 
 ******************************************************************************/
u8 Key_State_Check(GPIO_Pin_TypeDef key);
//u8 Key_Check(void);
void KeyReleaseWait (GPIO_Pin_TypeDef key);
void LED_Init(void);


#endif