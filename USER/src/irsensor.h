#ifndef _IRSENSOR_H_
#define _IRSENSOR_H_

#include "stm8s.h"

#define IRLED_PORT1        GPIOC
#define IRLED1             GPIO_PIN_3//LED GPIO ONLE ONE LED  

#define IRLED1ON            GPIO_WriteHigh(IRLED_PORT1,IRLED1);
#define IRLED1OFF           GPIO_WriteLow(IRLED_PORT1,IRLED1);
#define IRLED1REVERSE       GPIO_WriteReverse(IRLED_PORT1,IRLED1);
void init_sensor(void);
u16 ircalvalue;
u16 GetSensorRawValue();
void GetSensorCalValue(void);
u16 GetSensorValue();
	

#endif