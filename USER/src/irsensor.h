#ifndef _IRSENSOR_H_
#define _IRSENSOR_H_

#include "stm8s.h"

#define IRLED_PORT1        GPIOC
#define IRLED1             GPIO_PIN_3//LED GPIO ONLE ONE LED  

#define IRLEDON            GPIO_WriteHigh(IRLED_PORT1,IRLED1);
#define IRLEDOFF           GPIO_WriteLow(IRLED_PORT1,IRLED1);
#define IRLEDREVERSE       GPIO_WriteReverse(IRLED_PORT1,IRLED1);
void init_sensor(void);

#endif