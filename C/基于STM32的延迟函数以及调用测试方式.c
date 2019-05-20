#include "stm32f10x.h"
#include <stdio.h>

void delay(void)
{
	uint16_t x1;
	
	x1=60000;	//可以根据延时长短，设置任意值
	while(x1)
	{
		x1=x1-1;
	}
}

//调用方式
while(1)
{
	delay();
	printf("%d",1);		//根据1的打印间隔，判断delay函数的延迟时间
}
