#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "hx711.h"
#include "oled.h"

 int main(void)
 {
	 char buffer[6];
	 delay_init();	    	 //延时函数初始化	 
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	 uart_init(115200);	 
	 OLED_Init();
	 init_hx711();
	 weight_maopi = Get_Maopi();
	 delay_ms(1000);
	 OLED_Clear();
	 OLED_ShowString(0, 2, "weight:", 16);
	 delay_ms(1000);
	 weight_maopi = Get_Maopi();
	 
	 
 	while(1)
	{
		sprintf(buffer, "%0.1f", Get_Weight());
		OLED_ShowString(64, 2, (uint8_t*)buffer, 16);
		OLED_ShowString(110, 2, "g", 16);
		delay_ms(1000);
		delay_ms(1000);
	}		
 }

