
#include "main.h"
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
