#include "stdio.h"
#include "delay.h"
#include "sys.h"
#include "hx711.h"
#include "lcd1602.h"
#include "usart.h"


 int main(void)
 {
	 char buffer[5];
	 delay_init();	    	 //延时函数初始化	  
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	 uart_init(115200);	
	 init_hx711();
	 weight_maopi = Get_Maopi();
	 LCD1602_Init();
	 LCD_DisString(0, 0, "weight:");
	 weight_maopi = Get_Maopi();
	 
 	while(1)
	{
		sprintf(buffer, "%0.1f", Get_Weight());
		LCD_DisString(7, 0, (uint8_t*)buffer);
		LCD_DisString(12, 0, "g");
		delay_ms(1000);
		delay_ms(1000);
	}		
 }

