#include "hc595.h"

uint16_t num[8][10] = {{0x01c0, 0x01f9, 0x01a4, 0x01b0, 0x0199, 0x0192, 0x0182, 0x01f8, 0x0180, 0x0190},
			{0x02c0, 0x02f9, 0x02a4, 0x02b0, 0x0299, 0x0292, 0x0282, 0x02f8, 0x0280, 0x0290},
			{0x04c0, 0x04f9, 0x04a4, 0x04b0, 0x0499, 0x0492, 0x0482, 0x04f8, 0x0480, 0x0490},
			{0x08c0, 0x08f9, 0x08a4, 0x08b0, 0x0899, 0x0892, 0x0882, 0x08f8, 0x0880, 0x0890},
			{0x10c0, 0x10f9, 0x10a4, 0x10b0, 0x1099, 0x1092, 0x1082, 0x10f8, 0x1080, 0x1090},
			{0x20c0, 0x20f9, 0x20a4, 0x20b0, 0x2099, 0x2092, 0x2082, 0x20f8, 0x2080, 0x2090},
			{0x40c0, 0x40f9, 0x40a4, 0x40b0, 0x4099, 0x4092, 0x4082, 0x40f8, 0x4080, 0x4090},
			{0x80c0, 0x80f9, 0x80a4, 0x80b0, 0x8099, 0x8092, 0x8082, 0x80f8, 0x8080, 0x8090}};

/**
 * pin0->dio
 * pin1->sck
 * pin2->rck
 */

void init_hc595(void) 
{
    RCC->APB2ENR |= 1 << 2;
    GPIOA->CRL &= 0xFFFFF000;
    GPIOA->CRL |= 0x0333;
}

void init_view(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //声明一个结构体变量，用来初始化GPIO

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 //设置推挽输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOA, &GPIO_InitStructure); 	   /* 初始化GPIO */
}

/**
 * 8位 
 */

void hc595_control(uint16_t data)
{
	uint8_t i;
	
	GPIOA->BSRR = 1 << 0;   //dio
	GPIOA->BRR = 1 << 1;    //sck
	GPIOA->BRR = 1 << 2;   //rck
	
	for (i = 0; i < 16; i++)
	{
		GPIOB->BRR = 1 << 1;	//sck
		if (data & 0x8000)
		{
			GPIOB->BSRR = 1 << 0;	//dio
		}
		else
		{
			GPIOB->BRR = 1 << 0;	//dio
		}
		
		GPIOB->BSRR = 1 << 1;
		data <<= 1;
	}

	GPIOA->BSRR = 1 << 2;
}

