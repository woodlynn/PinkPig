

#ifndef __KEY_SCAN_H
#define __KEY_SCAN_H

/* ����ϵͳͷ�ļ� */

/* �����Զ���ͷ�ļ� */
#include "stm8s.h"

/* �Զ����������� */

/* �Զ��峣����ͱ��ʽ�� */
/* LED �����ӵ�GPIO�˿ڶ��� */
#define KEY_PORT        GPIOA	/* ���尴����������GPIO�˿� */


/* LED�����ӵ�GPIO���Ŷ��� */
#define KEY_M     	GPIO_PIN_5
#define KEY_D           GPIO_PIN_4
#define KEY_U           GPIO_PIN_3


#define KEY_DOWN   	0	/* �������µ͵�ƽ */
#define KEY_UP 	 	1	/* �����ɿ��ߵ�ƽ */
#define KEY_HOLD        2       //����
#define KEY1_DOWN   	3	
#define KEY2_DOWN   	4
#define KEY3_DOWN   	5
#define KEY1_HOLD   	6       //����
#define KEY2_HOLD  	7
#define KEY3_HOLD       8
#define CHECKKEYON      0
#define CHECKKEYOFF     1
#define LED_PORT        GPIOG
#define LED             GPIO_PIN_0

#define LEDON            GPIO_WriteHigh(LED_PORT,LED);
#define LEDOFF           GPIO_WriteLow(LED_PORT,LED);
#define LEDREVERSE       GPIO_WriteReverse(LED_PORT,LED);
/* �������ⲿʹ�õı��� */

/* �������ⲿʹ�õĺ��� */

/*******************************************************************************
 * ����: Key_Init
 * ����: ��������GPIO���ų�ʼ������
 * �β�: ��
 * ����: ��
 * ˵��: �� 
 ******************************************************************************/
void Key_Init(void);

/*******************************************************************************
 * ����: Key_Scan
 * ����: ��ȡһ��������״̬
 * �β�: key -> Ҫ��ȡ�İ���
 * ����: ������״̬ 0--���� 1--δ����
 * ˵��: �� 
 ******************************************************************************/
u8 Key_State_Check(GPIO_Pin_TypeDef key);
//u8 Key_Check(void);
void KeyReleaseWait (GPIO_Pin_TypeDef key);
void LED_Init(void);


#endif