


/* ����ϵͳͷ�ļ� */

/* �����Զ���ͷ�ļ� */
#include "keyled.h"
#include "stm8s_gpio.h"
#include "tim4.h"

/* �Զ��������� */

/* �Զ���� */

/* ȫ�ֱ������� */

/* �򵥵���ʱ���� */

static void Delay(u32 nCount)
{
	unsigned int i;
	
  	for (i = 0; i < 2000; i++) {
		for (; nCount > 0; nCount--)
			;
  	}
}


/*******************************************************************************
 * ����: LED_Init
 * ����: LED����GPIO���ų�ʼ������
 * �β�: ��
 * ����: ��
 * ˵��: �� 
 ******************************************************************************/
void LED_Init(void)
{
	GPIO_Init(LED_PORT, LED, GPIO_MODE_OUT_PP_HIGH_FAST );	
        LEDOFF;
}


