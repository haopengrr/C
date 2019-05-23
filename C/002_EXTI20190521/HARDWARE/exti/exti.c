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
	

	
//ʹ��AFIOʱ��	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
//ʹ���ض�GPIO�ڵ��ⲿ�ж�
   GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
	
//��ʼ���ⲿ�ж�EXTI	
	 EXTI_InitGPIOE.EXTI_Line=EXTI_Line4;
	 EXTI_InitGPIOE.EXTI_LineCmd= ENABLE;
	 EXTI_InitGPIOE.EXTI_Mode=EXTI_Mode_Interrupt;
	 EXTI_InitGPIOE.EXTI_Trigger=EXTI_Trigger_Falling;//��ť����ʱ��PE4�ɸߵ�ƽת�͵�ƽ������ѡ���½��ش���
	 EXTI_Init(&EXTI_InitGPIOE);

//��ʼ���ж�	
	 NVIC_InitUART1.NVIC_IRQChannel=EXTI4_IRQn;		//USART1 global Interrupt.60���������ж�
	 NVIC_InitUART1.NVIC_IRQChannelCmd=ENABLE;			//USART1�ж�ʹ��
	 NVIC_InitUART1.NVIC_IRQChannelPreemptionPriority=1;		
	 NVIC_InitUART1.NVIC_IRQChannelSubPriority=1;					
	 NVIC_Init(&NVIC_InitUART1);
	
}

//�ض���EXTI4_IRQHandler�жϷ�����
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
