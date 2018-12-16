#ifndef __HX711_H_
#define __HX711_H_

#define GPIO_HX711  		GPIOD        
#define DOUT   					GPIO_Pin_1	  
#define SCLK    				GPIO_Pin_0	  
#define RCC_GPIO 				RCC_APB2Periph_GPIOD 

#include "sys.h"

extern uint32_t weight_maopi;

void init_hx711(void); 
unsigned long HX711_Read_DATA(void); 
float Get_Weight(void);
double Get_Maopi(void);

#endif

