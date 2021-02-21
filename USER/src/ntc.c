

/* 包含系统头文件 */


/* 包含自定义头文件 */


#include "ntc.h"

/* 自定义新类型 */

/* 自定义宏 */

/* 全局变量定义 */
//static uint16_t OneChannelGetADValue(ADC1_Channel_TypeDef ADC1_Channel,ADC1_SchmittTrigg_TypeDef ADC1_SchmittTriggerChannel);
/*
const unsigned int ad_data[]=
{
        1009,1008,1007,1006,1004,1003,1002,1000,999,997,996,994,992,
        990,988,986,983,981,979,976,973,970,967,964,961,957,954,950,
        946,942,938,933,929,924,919,914,909,903,898,892,886,880,873,
        867,860,853,846,839,831,823,815,807,799,791,782,773,764,755,
        746,737,727,718,708,698,688,678,668,658,648,637,627,616,606,
        596,585,575,564,554,543,533,523,512,502,492,480,472,462,452,
        442,433,423,414,404,395,386,377,368,360,351,343,335,327,319,
        311,303,296,288,281,274,267,261,254,248,241,235,229,223,218,
        212,207,201,196,191,186,181,177,172,168,163,159,155,151,147,
        143,139,136,132,129,126,122,119,116,113,110,108,105
};
*/
////////////////////////////         5K        ///////////////////////
const unsigned int ad_data[]=
{
        966,963,960,957,954,950,947,944,940,936,932,928,924,920,915,911,
        906,901,896,891,885,880,874,868,862,856,849,843,836,829,822,815,
        808,800,793,785,777,769,761,753,744,736,727,718,709,700,691,682,
        672,663,653,644,634,624,615,605,595,585,575,566,556,546,536,526,
        517,507,497,488,478,469,459,450,440,431,422,413,404,395,387,378,
        370,361,353,345,337,329,321,314,306,299,292,285,278,271,264,258,
        251,245,239,233,227,221,216,210,205,200,195,190,185,180,176,171,
        167,162,158,154,150,146,143,139,135,132,128,125,122,119,116,113,
        110,107,104,102,99,97,94,92,89,87,85,83,81,116,113,110,
        108,105
};

const  signed  char temp_tab[]=
{
    -40,-39,-38,-37,-36,-35,-34,-33,-32,-31,-30,-29,-28,-27,-26,-25,-24,-23,-22,-21,-20,-19,-18,
    -17,-16,-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,
    14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,
    45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,
    76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100

};

u16 GetAvgValue(u8 adch)
{   
    u8 adcchannel=adch,adcschmittrigchannel=adch;
    u16 ad,tm;
    u8 i,j;
    u16 tmpad[16];
    for(i = 0; i < 16; i++)
    {
        _delay_ms(8);
        tmpad[i]=OneChannelGetADValue(adcchannel,adcschmittrigchannel);
        for (j=i;j>0;j--)
        {
            if (tmpad[j]<tmpad[j-1])
            {
                tm=tmpad[j-1];
                tmpad[j-1]=tmpad[j];
                tmpad[j]=tm;
            }
        }
    }
   
    ad=(tmpad[6]+tmpad[7]+tmpad[8]+tmpad[9])/4;
    
    return ad;
}
 s8 GetNtcTemp(u8 ch)
{
    s8 ksc=0;//////////////////////////////////////////////////////////////////测试用
    unsigned char i;
     s8 temp=0;
    unsigned int TempAD=0;
    //if(ADCFilter(10))
    {
        
        TempAD=GetAvgValue(ch);
        //SendData(TempAD);
        if(TempAD>1000)
            return 0x80;
        if(TempAD<81)
          return 100;
        for(i=0;TempAD<ad_data[i];i++)
        {
            if(i>970)
            {
                return -42;
            }
                
        }
        temp=temp_tab[i]+ksc;
        //SendData(i);
    //    temp=temp*10-((TempAD-ad_data[i])*10)/(ad_data[i-1]-ad_data[i]);
        //SendData(temp);
    }
    return temp;
}
/*******************************************************************************
 * 名称: ADC_Init
 * 功能: ADC1初始化操作
 * 形参: 无
 * 返回: 无
 * 说明: ADC1_Init函数的形参不能使用或运算初始化多通道ADC 
 ******************************************************************************/
void ADC_Init(void)
{
    /**< 连续转换模式 */
    /**< 使能通道 */
    /**< ADC时钟：fADC1 = fcpu/18 */
    /**< 这里设置了从TIM TRGO 启动转换，但实际是没有用到的*/
    /**  不使能 ADC1_ExtTriggerState**/
    /**< 转换数据右对齐 */
    /**< 不使能通道10的斯密特触发器 */
    /**  不使能通道10的斯密特触发器状态 */
    ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS , ADC1_CHANNEL_1, ADC1_PRESSEL_FCPU_D18,\
		ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, ADC1_SCHMITTTRIG_CHANNEL1,DISABLE);
    ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS , ADC1_CHANNEL_2, ADC1_PRESSEL_FCPU_D18,\
		ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, ADC1_SCHMITTTRIG_CHANNEL2,DISABLE);
  
    ADC1_Cmd(ENABLE);
  
}


/*******************************************************************************
 * 名称: OneChannelGetADValue
 * 功能: ADC1单通道选择读取AD值
 * 形参: ADC1_Channel,ADC1_SchmittTriggerChannel
 * 返回: 该通道的AD值
 * 说明: 当要读取多通道AD值采调用该函数，否则只是初始化ADC_Init即可 
 ******************************************************************************/
 uint16_t OneChannelGetADValue(ADC1_Channel_TypeDef ADC1_Channel,\
                                     ADC1_SchmittTrigg_TypeDef ADC1_SchmittTriggerChannel)
{
    uint16_t ADConversion_Value;
    /**< 连续转换模式 */
    /**< 使能通道 */
    /**< ADC时钟：fADC1 = fcpu/18 */
    /**< 这里设置了从TIM TRGO 启动转换，但实际是没有用到的*/
    /**  不使能 ADC1_ExtTriggerState**/
    /**< 转换数据右对齐 */
    /**< 不使能通道10的斯密特触发器 */
    /**  不使能通道10的斯密特触发器状态 */
    ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS , ADC1_Channel, ADC1_PRESSEL_FCPU_D18,\
		ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, ADC1_SchmittTriggerChannel,DISABLE);
    ADC1_Cmd(ENABLE);
    ADC1_StartConversion();
    ADConversion_Value = ADC1_GetConversionValue();
    return ADConversion_Value;
}

