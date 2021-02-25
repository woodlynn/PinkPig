#include "main.h"
#include "adc.h"


u16 ircalvalue;

void Sensor_Init(void){
	GPIO_Init(IR_PORT1, IR_LED1, GPIO_MODE_OUT_PP_LOW_FAST );	
    IRLEDOFF;

}

u16 GetSensorRawValue(){ //返回adc值
	u16 tmp[8];
	u32 tmp;
	for (u8 i=0;i<8;i++){
		tmp[i]=OneChannelGetADValue(SENSOR_CHANNEL,SENSOR_CHANNEL)//get adc value 8 times
	}
	ADCShortValue(tmp,8);//short the value 
	tmp = tmp[2]+tmp[3]+tmp[4]+tmp[5]; //get average value
	tmp /= 4;
	return (u16)tmp;
}

void GetSensorCalValue(void){ //关灯底噪值
	IRLED1OFF;
	Delay_us(10);
	ircalvalue = GetSensorRawValue();

}

u16 GetSensorValue(){ //返回测试原始值
	u16 irsensorvalue;
	IRLED1ON;
	Delay_us(10);
	irsensorvalue = GetSensorRawValue();
	irsensorvalue -= ircalvalue;
	return irsensorvalue;

}