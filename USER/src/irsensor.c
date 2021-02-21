#include "irsensor.h"
#include "adc.h"
#include "delay.h"

u16 ircalvalue;

void init_sensor(void){
	GPIO_Init(IR_PORT1, IR_LED1, GPIO_MODE_OUT_PP_LOW_FAST );	
    IRLEDOFF;
}

u16 GetSensorRawValue(){
	u16 tmp[8];
	u32 tmp;
	for (u8 i=0;i<8;i++){
		tmp[i]=OneChannelGetADValue(adc_1,linshi)//get adc value
	}
	ADCShortValue (tmp);//short the value 
	tmp = tmp[2]+tmp[3]+tmp[4]+tmp[5]; //get average value
	tmp /= 4;
	return (u16)tmp;
}

void GetSensorCalValue(void){
	IRLED1OFF;
	Delay_us(10);
	ircalvalue = GetSensorRawValue();

}

u16 GetSensorValue(){
	u16 irsensorvalue;
	IRLED1ON;
	Delay_us(10);
	irsensorvalue = GetSensorRawValue();
	irsensorvalue -= ircalvalue;
	return irsensorvalue;

}