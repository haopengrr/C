#include "timer.h"

 void TIM3_Int_Init()
 {
	TIM_TimeBaseInitTypeDef TIM3_TimeBaseInitTypeDef;
	u16 arr;
	u16 psc;
	 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
//	TIM3_TimeBaseInitTypeDef.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM3_TimeBaseInitTypeDef.TIM_CounterMode=TIM_CounterMode_Up;
	TIM3_TimeBaseInitTypeDef.TIM_Period=arr;
	TIM3_TimeBaseInitTypeDef.TIM_Prescaler=psc;
//	TIM3_TimeBaseInitTypeDef.TIM_RepetitionCounter=	 
	TIM_TimeBaseInit(TIM3,)
	 
	
 
 
 
 
 }
	 