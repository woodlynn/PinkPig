

#ifndef __KEY_SCAN_H
#define __KEY_SCAN_H

/* ����ϵͳͷ�ļ� */

/* �����Զ���ͷ�ļ� */
#include "stm8s.h"

/* �Զ����������� */

/* �Զ��峣����ͱ��ʽ�� */
/* LED �����ӵ�GPIO�˿ڶ��� */

#define LED_PORT        GPIOC
#define LED             GPIO_PIN_7//LED GPIO ONLE ONE LED  

#define LEDON            GPIO_WriteHigh(LED_PORT,LED);
#define LEDOFF           GPIO_WriteLow(LED_PORT,LED);
#define LEDREVERSE       GPIO_WriteReverse(LED_PORT,LED);

void LED_Init(void);


#endif