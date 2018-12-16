#include "hx711.h"
#include "delay.h"
#include "usart.h"

uint32_t weight_maopi = 82240;
static float sum = 0;

void init_hx711(void) 
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_GPIO, ENABLE); 
    GPIO_InitStructure.GPIO_Pin = SCLK;				 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
    GPIO_Init(GPIO_HX711, &GPIO_InitStructure);
	
    GPIO_InitStructure.GPIO_Pin = DOUT; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIO_HX711, &GPIO_InitStructure);
}

unsigned long HX711_Read_DATA(void) 
{
		uint8_t i;
    unsigned long val = 0;
    
    GPIO_SetBits(GPIO_HX711, DOUT);
    GPIO_ResetBits(GPIO_HX711, SCLK); 
	
    while(GPIO_ReadInputDataBit(GPIO_HX711, DOUT))
		{
		}
		
    delay_us(1);
		
    for(i = 0; i < 24; i++)     
    {
        GPIO_SetBits(GPIO_HX711, SCLK); 
        val = val << 1; 
        delay_us(1);
        GPIO_ResetBits(GPIO_HX711, SCLK); 
        if(GPIO_ReadInputDataBit(GPIO_HX711, DOUT))
				{
					val++;
				}
            
        delay_us(1);
    }
    GPIO_SetBits(GPIO_HX711, SCLK);
    val = val ^ 0x800000; 
    delay_us(1);
    GPIO_ResetBits(GPIO_HX711, SCLK);
    delay_us(1);
		
    return val;
}

double Get_Maopi(void)
{
    return HX711_Read_DATA() / 100;
}

float Get_Weight(void)
{
		printf("%f\r\n", Get_Maopi());
		printf("%dy\r\n", weight_maopi);
		if (Get_Maopi() > weight_maopi)
		{
			sum = Get_Maopi() - weight_maopi;
		} 
		
		return sum / 4.03;
}
