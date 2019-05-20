#include "beep.h"
#include "stm32f10x.h"

void BEEP_Init(void)
{
	
RCC->APB2ENR |= 1<<3;

//GPIOB.8
GPIOB->CRH &= 0xfffffff0;	//先对GPIOB.8清0
GPIOB->CRH |= 0x00000003;	//CRH为0011，对GPIOB.8置位0011,Output mode| max speed 50 MHz|General purpose output push-pull
GPIOB->ODR |= 1<<8;



	
}
