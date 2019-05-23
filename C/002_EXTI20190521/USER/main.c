#include "exti.h"
#include "stm32f10x.h"
int main(void)
{
	//初始化GPIO和相应时钟	

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	EXTIX_Init();
	while(1);
	
	
}
