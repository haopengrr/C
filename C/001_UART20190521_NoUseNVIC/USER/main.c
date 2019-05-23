#include "stm32f10x.h"



void My_USART1_Init(void)			//������ʼ��һ�����õĴ���
{
//����GPIO��USART��ʼ��Ҫʹ�õĽṹ��
	GPIO_InitTypeDef GPIO_UART1;
	USART_InitTypeDef USART_InitUART1;
//	NVIC_InitTypeDef NVIC_InitUART1;
	
//ʹ��GPIO��USART��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);

//GPIO��ʼ��	
	GPIO_UART1.GPIO_Mode= GPIO_Mode_AF_PP;				//TXΪ�����������
	GPIO_UART1.GPIO_Pin=GPIO_Pin_9;								//UART1��TXΪGPIOA��PIN9
	GPIO_UART1.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_UART1);

	GPIO_UART1.GPIO_Mode= GPIO_Mode_IN_FLOATING;	//RXΪ��������
	GPIO_UART1.GPIO_Pin=GPIO_Pin_10;							//UART1��RXΪGPIOA��PIN10
	GPIO_UART1.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_UART1);	

//USART��ʼ��
	USART_InitUART1.USART_BaudRate=115200;
	USART_InitUART1.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitUART1.USART_Mode=USART_Mode_Tx | USART_Mode_Rx;
	USART_InitUART1.USART_Parity=USART_Parity_Even;
	USART_InitUART1.USART_StopBits=USART_StopBits_1;
	USART_InitUART1.USART_WordLength=USART_WordLength_9b;//���������żУ��Ļ����˴��ĳ���Ӧ��Ϊ9bits.��������żУ�飬���ȿ���Ϊ8bits.
	USART_Init(USART1,&USART_InitUART1);

//USARTʹ��
	USART_Cmd(USART1,ENABLE);

////USART�ж�����
//	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);	//�����ݼĴ����ǿ�
//	
////��ʼ���ж�	
//	NVIC_InitUART1.NVIC_IRQChannel=USART1_IRQn;		//USART1 global Interrupt.60���������ж�
//	NVIC_InitUART1.NVIC_IRQChannelCmd=ENABLE;			//USART1�ж�ʹ��
//	NVIC_InitUART1.NVIC_IRQChannelPreemptionPriority=1;		
//	NVIC_InitUART1.NVIC_IRQChannelSubPriority=1;					
//	NVIC_Init(&NVIC_InitUART1);
	

}

////�жϷ�����
//void USART1_IRQHandler(void)
//{
//	u16 res;
//	if(USART_GetITStatus(USART1,USART_IT_RXNE))
//	{
//		res=USART_ReceiveData(USART1);						//��Ȼ���պ����ķ���ֵ�ͷ��ͺ�����Data�������Ͷ���uint16_t������DR�Ĵ���ֻ��8bits.
//		USART_SendData(USART1, res);							//���Ա���res�����Ϳ���Ϊu16��Ҳ����Ϊu8
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
