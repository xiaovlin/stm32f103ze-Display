#ifndef __LCD12864_H_
#define __LCD12864_H_

#include "sys.h"

#define rs PCout(0) 
#define rw PCout(1)
#define en PCout(2) 

void LCD12864_Init(void);
void LCD_Write_Command(unsigned char com); 
void LCD_Write_Date(unsigned char date);  
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal); 
void LCD_ClearScrren(void);
void lcd_DisStr(u8 X,u8 Y,u8 *s);
void DisStr(u8 *s);void lcd_DisStr(u8 X,u8 Y,u8 *s);
#endif

