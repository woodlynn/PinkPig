#include "i2c.h"
#include "delay.h"


void HwI2c_Init (void){
#ifdef STM8S003
	I2C_DeInit();
  	I2C_Init(IICSPEED, FDC2214_ADDR<<1, I2C_DUTYCYCLE_2, I2C_ACK_CURR, I2C_ADDMODE_7BIT,CLK_GetClockFreq()/1000000);
	I2C_Cmd(ENABLE);
#endif

}

void HwI2cStart(u8 reg){
	while(I2C_GetFlagStatus(I2C_FLAG_BUSY));
    /* 发起始位 */
    I2C_GenerateSTART(ENABLE);
    /* 测试EV5 ，检测从器件返回一个应答信号*/
    while(!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT)); 
    /* 设置I2C从器件地址，I2C主设备为写模式*/
    I2C_Send7bitAddress(FDC2214_ADDR, I2C_Direction_Transmitter);
  
    /* 测试EV6 ，检测从器件返回一个应答信号*/
  while(!I2C_CheckEvent(I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
    
  
    I2C_SendData((u8)reg); 
    /* 测试EV8 ，检测从器件返回一个应答信号*/
    while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTING));  
  
    /* 不断往从设备写数据*/

      
      I2C_SendData(I2C1,MSB);
      delay_us(10);
      while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
      I2C_AcknowledgeConfig(ENABLE);
      I2C_SendData(LSB);   
      delay_us(10);      
      while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED));
      I2C_AcknowledgeConfig(ENABLE);
  
    /* 发结束位*/
    I2C_GenerateSTOP(I2C1,ENABLE);
      I2C_AcknowledgeConfig(I2C1,ENABLE);
    return 0;

}