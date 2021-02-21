#include "irsensor.h"
#include "adc.h"

void init_sensor(void){
	GPIO_Init(IR_PORT, IR_LED, GPIO_MODE_OUT_PP_HIGH_FAST );	
    LEDOFF;
    


}