#include "exti.h"
#include "stm32f10x.h"
int main(void)
{
	//��ʼ��GPIO����Ӧʱ��	

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	EXTIX_Init();
	while(1);
	
	
}
