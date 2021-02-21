#ifndef _ADC_H_
#define _ADC_H_

#include "stm8s.h"

void ADC_Init(void);

 uint16_t OneChannelGetADValue(ADC1_Channel_TypeDef ADC1_Channel,\
                                     ADC1_SchmittTrigg_TypeDef ADC1_SchmittTriggerChannel);
 


#endif
