#include "stm32f10x.h"



void My_USART1_Init(void)			//完整初始化一个可用的串口
{
//定义GPIO和USART初始化要使用的结构体
	GPIO_InitTypeDef GPIO_UART1;
	USART_InitTypeDef USART_InitUART1;
//	NVIC_InitTypeDef NVIC_InitUART1;
	
//使能GPIO和USART的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);

//GPIO初始化	
	GPIO_UART1.GPIO_Mode= GPIO_Mode_AF_PP;				//TX为复用推挽输出
	GPIO_UART1.GPIO_Pin=GPIO_Pin_9;								//UART1的TX为GPIOA的PIN9
	GPIO_UART1.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_UART1);

	GPIO_UART1.GPIO_Mode= GPIO_Mode_IN_FLOATING;	//RX为浮空输入
	GPIO_UART1.GPIO_Pin=GPIO_Pin_10;							//UART1的RX为GPIOA的PIN10
	GPIO_UART1.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_UART1);	

//USART初始化
	USART_InitUART1.USART_BaudRate=115200;
	USART_InitUART1.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitUART1.USART_Mode=USART_Mode_Tx | USART_Mode_Rx;
	USART_InitUART1.USART_Parity=USART_Parity_Even;
	USART_InitUART1.USART_StopBits=USART_StopBits_1;
	USART_InitUART1.USART_WordLength=USART_WordLength_9b;//如果设置奇偶校验的话，此处的长度应该为9bits.不设置奇偶校验，长度可以为8bits.
	USART_Init(USART1,&USART_InitUART1);

//USART使能
	USART_Cmd(USART1,ENABLE);

////USART中断设置
//	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);	//读数据寄存器非空
//	
////初始化中断	
//	NVIC_InitUART1.NVIC_IRQChannel=USART1_IRQn;		//USART1 global Interrupt.60个可屏蔽中断
//	NVIC_InitUART1.NVIC_IRQChannelCmd=ENABLE;			//USART1中断使能
//	NVIC_InitUART1.NVIC_IRQChannelPreemptionPriority=1;		
//	NVIC_InitUART1.NVIC_IRQChannelSubPriority=1;					
//	NVIC_Init(&NVIC_InitUART1);
	

}

////中断服务函数
//void USART1_IRQHandler(void)
//{
//	u16 res;
//	if(USART_GetITStatus(USART1,USART_IT_RXNE))
//	{
//		res=USART_ReceiveData(USART1);						//虽然接收函数的返回值和发送函数的Data参数类型都是uint16_t，但是DR寄存器只有8bits.
//		USART_SendData(USART1, res);							//所以变量res的类型可以为u16，也可以为u8
//	}
//}

int main(void)
{
	uint8_t res=0;
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	My_USART1_Init();
	
	while(1)
	{
		res=USART_ReceiveData(USART1);
		if((res!=0) && (res!=0X0A))
		{
			USART_SendData(USART1, res);

		}
		

	}
	
}
