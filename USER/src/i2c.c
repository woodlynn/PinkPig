#include "i2c.h"
#include "delay.h"


void HwI2c_Init (void){
#ifdef STM8S003
	I2C_DeInit();
  	I2C_Init(IICSPEED, FDC2214_ADDR<<1, I2C_DUTYCYCLE_2, I2C_ACK_CURR, I2C_ADDMODE_7BIT,CLK_GetClockFreq()/1000000);
	I2C_Cmd(ENABLE);
#endif

}

void HwI2cStart(void){
	
	
}