#include "stm8s.h"
#include "ntc.h"
#include "led.h"
#include "uart.h"
#include "fdc2214.h"
#include "keyled.h"

void InitAll (void){

	Uart_Init();
	Adc_Init();
	LED_Init();
	Sensor_Init();
	FDC2214_Init();
	HwI2c_Init();

}



int main( void ){
    
  
  
  
  return 0;
}
