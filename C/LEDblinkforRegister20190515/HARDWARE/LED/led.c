#include "led.h"
#include "stm32f10x.h"

void LED_Init(void)
{
	
RCC->APB2ENR |= 1<<3;
RCC->APB2ENR |= 1<<6;

//GPIOB.5
GPIOB->CRL &= 0xff0fffff;	//先对GPIOB.5清0
GPIOB->CRL |= 0x00300000;	//CRL为0011，对GPIOB.5置位0011
GPIOB->ODR |= 1<<5;


//GPIOE.5	
GPIOE->CRL &= 0xff0fffff;	//先对GPIOB.5清0
GPIOE->CRL |= 0x00300000;	//CRL为0011，对GPIOB.5置位0011
GPIOE->ODR |= 1<<5;

	
}
