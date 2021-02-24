#ifndef _ADC_H_
#define _ADC_H_

#include "main.h"

#define NTC_CHANNEL 	ADC1_CHANNEL_2
#define SENSOR_CHANNEL	ADC1_CHANNEL_3


void ADC_Init(void);

 uint16_t OneChannelGetADValue(ADC1_Channel_TypeDef ADC1_Channel,\
                                     ADC1_SchmittTrigg_TypeDef ADC1_SchmittTriggerChannel);
 
 void ADCShortValue(uint16_t *p,uint8_t len)；


#endif
