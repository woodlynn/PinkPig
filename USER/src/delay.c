/* 自定义新类型 */

/* 自定义宏 */

/* 全局变量定义 */

/* 简单的延时函数 */

static void Delay_us(u32 nCount){
	unsigned int i;
	
  	for (i = 0; i < 2000; i++) {
		for (; nCount > 0; nCount--)
			;
  	}
}