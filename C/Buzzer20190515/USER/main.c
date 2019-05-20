#include "stm32f10x.h"
#include "delay.h"
#include "beep.h"

int main(void)
{
delay_init();
BEEP_Init();

while(1){
	GPIOB->ODR|=1<<8;

	delay_ms(5000);
	
	GPIOB->ODR&=~(1<<8);

	delay_ms(5000);
}	
		
	
	
}
