

#ifndef __KEY_SCAN_H
#define __KEY_SCAN_H

/* 包含系统头文件 */

/* 包含自定义头文件 */
#include "stm8s.h"

/* 自定义数据类型 */

/* 自定义常量宏和表达式宏 */
/* LED 灯所接的GPIO端口定义 */

#define LED_PORT        GPIOC
#define LED             GPIO_PIN_7//LED GPIO ONLE ONE LED  

#define LEDON            GPIO_WriteHigh(LED_PORT,LED);
#define LEDOFF           GPIO_WriteLow(LED_PORT,LED);
#define LEDREVERSE       GPIO_WriteReverse(LED_PORT,LED);

void LED_Init(void);


#endif