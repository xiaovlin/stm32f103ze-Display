#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "hx711.h"
#include "hc595.h"
#include "lcd.h"
#include "view.h"

 int main(void)
 {
	 char buffer[5];
	 delay_init();	    	 //延时函数初始化	  
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	 uart_init(115200);	 //串口初始化为115200
	 //LCD_Init();
	 //init_hx711();
	 //POINT_COLOR=RED;
	 //LCD_Display_Dir(0);   //0--竖屏   1--横
	 //LCD_Clear(WHITE);		 
   //LCD_ShowString(30,90,200,16,16,"weight: ");
	 init_hx711();
	 //Get_Maopi();		
	 //Get_Maopi();
	 
 	while(1)
	{
		printf("%0.1fg\r\n", Get_Weight());
//		sprintf(buffer, "%0.1f", Get_Weight());
//		LCD_ShowString(90, 90, 200, 16, 16, (uint8_t*)buffer);
//		LCD_ShowString(150, 90, 200, 16, 16, "g");
		delay_ms(500);
	}		
 }

