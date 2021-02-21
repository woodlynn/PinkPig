/*************************************

**************************************/

#ifndef  _EEPROM_H
#define  _EEPROM_H
#include "stm8s.h"

#define EEPROM_BASE_ADDRESS 0x4000
#define EEPROM_BASE_END_ADDRESS 0x4080

#define EEPROM_USEDHOUR_ADDRESS 0X4010


#define EEPROM_INITFLAG_ADDRESS 0X4000

#define EEPROM_TEMP1_ADDRESS    0x00
#define EEPROM_TEMP2_ADDRESS    0x02
#define EEPROM_TBMASK_ADDRESS   0x04
#define EEPROM_TBDEBUG_ADDRESS  0x06
#define EEPROM_TBSET_ADDRESS    0x08
#define EEPROM_FREZZ_ADDRESS    0x0A //·À¶³¹¦ÄÜ

#define EEPROM_SLEEP_TEMP1_ADDR 0x10
#define EEPROM_SLEEP_TEMP2_ADDR 0x20
#define EEPROM_SLEEP_TEMP3_ADDR 0x30

#define EEPROM_SLEEP_TIM1_ADDR 0x40
#define EEPROM_SLEEP_TIM2_ADDR 0x50
#define EEPROM_SLEEP_TIM3_ADDR 0x60









void EEPROM_Init(void);
void EEPROM_ON(void);
void EEPROM_OFF(void);
void EEPROM_nms(unsigned char ms);
void EEPROM_write_one_char(unsigned long address, unsigned char value);
void EEPROM_write_two_char(unsigned long address, unsigned char *value);
unsigned int  EEPROM_return_two_char(unsigned long address);
unsigned char EEPROM_return_one_char(unsigned long address);
void EEPROM_write_filter_usedhour(u16 *value);
void EEPROM_read_filter_usedhour(u16 * value);
void chip_eeprom_clear_all();



#endif
