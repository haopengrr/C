#include "led.h"
#include "stm32f10x.h"

void LED_Init(void)
{
	
RCC->APB2ENR |= 1<<3;
RCC->APB2ENR |= 1<<6;

//GPIOB.5
GPIOB->CRL &= 0xff0fffff;	//�ȶ�GPIOB.5��0
GPIOB->CRL |= 0x00300000;	//CRLΪ0011����GPIOB.5��λ0011
GPIOB->ODR |= 1<<5;


//GPIOE.5	
GPIOE->CRL &= 0xff0fffff;	//�ȶ�GPIOB.5��0
GPIOE->CRL |= 0x00300000;	//CRLΪ0011����GPIOB.5��λ0011
GPIOE->ODR |= 1<<5;

	
}
