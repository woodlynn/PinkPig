
#ifndef __NTC_H_
#define __NTC_H_

/* 包含系统头文件 */


/* 包含自定义头文件 */
#include "stm8s.h"
#include "tim4.h"

#include "tds.h"
/* 自定义新类型 */

/* 自定义宏 */

/* 全局变量定义 */

/**************************************************************************
 * 函数名：Send_ADC_Value
 * 描述  ：ADC转换结果显示函数
 * 输入  ：AD_Value--ADC转换结果值
 *
 * 输出  ：无
 * 返回  ：无 
 * 调用  ：内部调用 
 *************************************************************************/
void ADC_Init(void);
void Send_ADC_Value(u16 AD_Value);
void MultipleChannelGetADValue(void);
 uint16_t OneChannelGetADValue(ADC1_Channel_TypeDef ADC1_Channel,\
                                     ADC1_SchmittTrigg_TypeDef ADC1_SchmittTriggerChannel);
 s8 GetNtcTemp(u8 ch);
#endif