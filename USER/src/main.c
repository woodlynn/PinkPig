

#include "main.h"
void InitAll (void){

	Uart_Init();
	Adc_Init();
	LED_Init();
	Sensor_Init();
	FDC2214_Init();
	HwI2c_Init();

}
int GetIrsenso{
	int data;
	data= GetSensorValue();
	data-=ircalvalue;
	return data;
}



int main( void ){
	int sensordata;
	char i,value[5];
	InitAll();
	RxBuffer="Test";
	RxBuffer[5]='\n';
	Uart1_Sendstring(RxBuffer,sizeof(RxBuffer));
	sensordata=GetSensorValue();
	value=itoa (sensordata,value,10);
	RxBuffer="Sensor:";
	for (i=0;i<5;i++){
		RxBuffer[7+i]=value[i];
	}
	Uart1_Sendstring(RxBuffer,16);
}




