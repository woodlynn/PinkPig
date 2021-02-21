/*************************************

**************************************/

#include "EEPROM.h"
#include "stm8s.h"
#include "filter.h"


/***********************
函数功能：初始化EEPROM
输入参数：无
输出参数：无
备    注：无
***********************/
void EEPROM_Init(void)
{    
    FLASH_DeInit();
    FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);
    
    EEPROM_read_filter_usedhour(filterusedhour);

}

/***********************
函数功能：LED开
输入参数：无
输出参数：无
备    注：无
***********************/
void EEPROM_write_one_char(uint32_t address, unsigned char value)
{
    FLASH_Unlock(FLASH_MEMTYPE_DATA);
    while (FLASH_ReadByte(address) != value)
    { 
        FLASH_ProgramByte(address, value);
        FLASH_WaitForLastOperation(FLASH_MEMTYPE_DATA);
    }
    FLASH_Lock(FLASH_MEMTYPE_DATA);
}

/***********************
函数功能：LED开
输入参数：无
输出参数：无
备    注：无
***********************/
void EEPROM_write_two_char(uint32_t address, unsigned char *value)
{
    FLASH_Unlock(FLASH_MEMTYPE_DATA);
    while (FLASH_ReadByte(address) != value[0])
    {
        FLASH_ProgramByte(address, value[0]);
        FLASH_WaitForLastOperation(FLASH_MEMTYPE_DATA);
    }
  
    while (FLASH_ReadByte(address+1) != value[1])
    {
        FLASH_ProgramByte(address+1, value[1]);
        FLASH_WaitForLastOperation(FLASH_MEMTYPE_DATA);
    }
    FLASH_Lock(FLASH_MEMTYPE_DATA);
}
void EEPROM_write_filter_usedhour (u16 *value)
{
    u8 i;
    u16 j;
    
    FLASH_Unlock(FLASH_MEMTYPE_DATA);
    for (i=0;i<6;i++)
    {
        j=(EEPROM_USEDHOUR_ADDRESS+i*2);
        while (FLASH_ReadByte(j) != (value[i]&0xff))
        {
            FLASH_ProgramByte(j,( value[i]&0xff));
            FLASH_WaitForLastOperation(FLASH_MEMTYPE_DATA);
        }
        while (FLASH_ReadByte(j+1) != value[i]>>8)
        {
            FLASH_ProgramByte(j+1, value[i]>>8);
            FLASH_WaitForLastOperation(FLASH_MEMTYPE_DATA);
        }
    }
    
   
    FLASH_Lock(FLASH_MEMTYPE_DATA);
}
void EEPROM_read_filter_usedhour(u16 * value)
{
  u8 i,tmp;
//  u16 j;
  for (i=0;i<6;i++)
  {
        tmp=FLASH_ReadByte(EEPROM_USEDHOUR_ADDRESS+i*2);
        value[i]=FLASH_ReadByte(EEPROM_USEDHOUR_ADDRESS+i*2+1);
        value[i]=value[i]<<8;
        value[i]+=tmp;
  }
  
}


void EEPROM_read_two_char(uint32_t address, unsigned char* value)
{
  value[0] = FLASH_ReadByte(address);
  value[1] = FLASH_ReadByte(address+1);
}

unsigned char EEPROM_return_one_char(uint32_t address)
{
  return FLASH_ReadByte(address);
}

unsigned int EEPROM_return_two_char(uint32_t address)
{
  unsigned int value = 0;
  EEPROM_read_two_char(address, (unsigned char*)(&value));
  return value;
}

void chip_eeprom_clear_all()
{

  for (uint32_t i=EEPROM_BASE_ADDRESS; i<EEPROM_BASE_END_ADDRESS; ++i)
  {
    EEPROM_write_one_char(i, 0);
  }

}