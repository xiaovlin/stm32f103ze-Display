#ifndef __LCD1602_H 
#define __LCD1602_H 

#include "sys.h"

#define rs PCout(0) 
#define rw PCout(1)
#define en PCout(2) 

void LCD1602_Init(void); 
void LCD_Write_Command(unsigned char com); 
void LCD_Write_Date(unsigned char date);   
void LCD_ClearScrren(void);
void LCD_DisChar(u8 x,u8 y,u8 ch);
void LCD_DisNumber(u8 x,u8 y,u16 Num);
void LCD_DisString(u8 x,u8 y,u8 *str);

#endif
