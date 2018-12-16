#ifndef __OLED_H
#define __OLED_H

#include "stdlib.h"
# include "stm32f10x.h"

#define OLED GPIOA        
#define DATA GPIO_Pin_1	  
#define SCLK  GPIO_Pin_0	  
#define OLEDCLK RCC_APB2Periph_GPIOA 

#define OLED_MODE 0
#define SIZE 8
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF
#define X_WIDTH 	128
#define Y_WIDTH 	64
//-----------------OLED IIC端口定义----------------

#define OLED_SCLK_Clr() GPIO_ResetBits(OLED,SCLK) //CLK   GPIOA->BRR = 1 << 0     
#define OLED_SCLK_Set() GPIO_SetBits(OLED,SCLK)     //GPIOA->BSRR = 1 << 0     

#define OLED_SDIN_Clr() GPIO_ResetBits(OLED,DATA)//DIN   //GPIOA->BRR = 1 << 1     
#define OLED_SDIN_Set() GPIO_SetBits(OLED,DATA)    //GPIOA->BSRR = 1 << 1    

#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据


//OLED控制用函数
void OLED_WR_Byte(unsigned dat,unsigned cmd);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(uint8_t x,uint8_t y,uint8_t t);
void OLED_Fill(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t dot);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size); //size有效数字: 12,16
void OLED_ShowString(uint8_t x,uint8_t y, uint8_t *p,uint8_t Char_Size); //	Char_Size有效数字：8，16
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
void fill_picture(unsigned char fill_Data);
void Picture(void);
void IIC_Start(void);
void IIC_Stop(void);
void Write_IIC_Command(unsigned char IIC_Command);
void Write_IIC_Data(unsigned char IIC_Data);
void Write_IIC_Byte(unsigned char IIC_Byte);

void IIC_Wait_Ack(void);
#endif

