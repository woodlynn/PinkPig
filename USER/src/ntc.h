
#ifndef __NTC_H_
#define __NTC_H_

/* ����ϵͳͷ�ļ� */


/* �����Զ���ͷ�ļ� */
#include "stm8s.h"
#include "tim4.h"

#include "tds.h"
/* �Զ��������� */

/* �Զ���� */

/* ȫ�ֱ������� */

/**************************************************************************
 * ��������Send_ADC_Value
 * ����  ��ADCת�������ʾ����
 * ����  ��AD_Value--ADCת�����ֵ
 *
 * ���  ����
 * ����  ���� 
 * ����  ���ڲ����� 
 *************************************************************************/
void ADC_Init(void);
void Send_ADC_Value(u16 AD_Value);
void MultipleChannelGetADValue(void);
 uint16_t OneChannelGetADValue(ADC1_Channel_TypeDef ADC1_Channel,\
                                     ADC1_SchmittTrigg_TypeDef ADC1_SchmittTriggerChannel);
 s8 GetNtcTemp(u8 ch);
#endif