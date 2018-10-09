#include "led.h"
#include "delay.h"
#include <math.h>

void Led_Init(void)
{	
	/* ��GPIOA������ص�APB2ʱ������ */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	/* ��������LED�˿�Ϊ������� */
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = LED_R | LED_Y | LED_G;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void Led_Breath(uint16_t GPIO_Pin, uint32_t time)
{
	/* �ı��ƽռ�ձȻ�ò�ͬ���� */
	for (int i = 1; i < time; ++i)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin);
		Delay_us(i);

		GPIO_ResetBits(GPIOA, GPIO_Pin);
		Delay_us(time -  i);
	}
	for (int i = 1; i < time; ++i)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin);
		Delay_us(time -  i);

		GPIO_ResetBits(GPIOA, GPIO_Pin);
		Delay_us(i);
	}
}
