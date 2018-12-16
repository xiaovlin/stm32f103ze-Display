#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "hx711.h"
#include "lcd12864.h"


 int main(void)
 {
	 char buffer[5];
	 delay_init();	    	 //延时函数初始化	 
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	 uart_init(115200);		 
	 init_hx711();
	 weight_maopi = Get_Maopi();
	 LCD12864_Init();
	 lcd_DisStr(0, 0, "weight:");
	 delay_ms(1000);
	 weight_maopi = Get_Maopi();
	 
 	while(1)
	{
		sprintf(buffer, "%0.1f", Get_Weight());
		lcd_DisStr(7, 0, (uint8_t*)buffer);
		lcd_DisStr(12, 0, "g");
		delay_ms(1000);
		delay_ms(1000);
	}		
 }

