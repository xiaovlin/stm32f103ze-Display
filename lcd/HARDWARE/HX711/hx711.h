#ifndef __HX711_H_
#define __HX711_H_

#define GPIO_HX711  		GPIOA  
#define SCLK    				GPIO_Pin_3	 
#define DOUT   					GPIO_Pin_4	  
#define RCC_GPIO 				RCC_APB2Periph_GPIOA

#include "stm32f10x.h"
#include "stdio.h"
#include "sys.h" 

extern uint32_t weight_maopi;

void init_hx711(void); 
unsigned long HX711_Read_DATA(void); 
float Get_Weight(void);
double Get_Maopi(void);

#endif

