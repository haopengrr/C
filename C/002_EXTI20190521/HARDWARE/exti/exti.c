#include "exti.h"
#include "key.h"
#include "led.h"
#include "stm32f10x.h"
#include "delay.h"

void EXTIX_Init(void)
{
	delay_init();
	KEY_Init();
	LED_Init();

	
	 EXTI_InitTypeDef EXTI_InitGPIOE;
	 NVIC_InitTypeDef	NVIC_InitUART1;
	

	
//使能AFIO时钟	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
//使能特定GPIO口的外部中断
   GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
	
//初始化外部中断EXTI	
	 EXTI_InitGPIOE.EXTI_Line=EXTI_Line4;
	 EXTI_InitGPIOE.EXTI_LineCmd= ENABLE;
	 EXTI_InitGPIOE.EXTI_Mode=EXTI_Mode_Interrupt;
	 EXTI_InitGPIOE.EXTI_Trigger=EXTI_Trigger_Falling;//按钮按下时，PE4由高电平转低电平，所以选择下降沿触发
	 EXTI_Init(&EXTI_InitGPIOE);

//初始化中断	
	 NVIC_InitUART1.NVIC_IRQChannel=EXTI4_IRQn;		//USART1 global Interrupt.60个可屏蔽中断
	 NVIC_InitUART1.NVIC_IRQChannelCmd=ENABLE;			//USART1中断使能
	 NVIC_InitUART1.NVIC_IRQChannelPreemptionPriority=1;		
	 NVIC_InitUART1.NVIC_IRQChannelSubPriority=1;					
	 NVIC_Init(&NVIC_InitUART1);
	
}

//特定的EXTI4_IRQHandler中断服务函数
void EXTI4_IRQHandler(void)
{
	
	delay_ms(10);
	if(KEY0==0)
	{
		LED0=!LED0;
		LED1=!LED1;
	}
	EXTI_ClearITPendingBit(EXTI_Line4);
	
	
}
