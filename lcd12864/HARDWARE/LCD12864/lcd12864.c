#include "lcd12864.h"
#include "delay.h"

/*******************LCD1602初始化************************/
void LCD12864_Init(void) 
{ 	    
     GPIO_InitTypeDef  GPIO_InitStructure;
 		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);	 
	  
     GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2
	   |GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;   		 
     GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
     GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
     GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;		 
     GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
     GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
     GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	   LCD_Write_Command(0x38);//设置LCD两行显示，一个数据由5*7点阵表示,数据由8跟线传输
     delay_ms(2);
	   LCD_Write_Command(0x01);//清除屏幕显示
	   delay_ms(2);
	   LCD_Write_Command(0x06);//设定输入方式，增量不移位
	   delay_ms(2);
	   LCD_Write_Command(0x0c);//开整体显示，关光标，不闪烁
	   delay_ms(2); 
}


/*******************写指令函数************************/
void LCD_Write_Command(u8 com)	 			  
{
  rs=0; //写指令函数和写数据函数其实可以并一起价格 BOOL变量判断是写指令就rs=0写数据就rs=1。
	rw=0;
	en=1;  //写指令     输入：RS=L，RW=L，E=下降沿脉冲 
	GPIOA->ODR=GPIOA->ODR&0xff00|com;//该函数一般用来往一次性一个GPIO的多个端口设置
  delay_ms(2); 
  en=0;
	delay_ms(2); 
}
 
/*******************写数据函数************************/
void LCD_Write_Date(u8 date)	     	  
{  
  rs=1;
	rw=0;
	en=1;	//写数据     输入：RS=H，RW=L，E=下降沿脉冲
  GPIOA->ODR=GPIOA->ODR&0xff00|date;//GPIOA的第八位用来作为8位数据口	
  delay_ms(2); 
  en=0;
	delay_ms(2);
}

//LCD清屏
void LCD_ClearScrren(void)
{
     LCD_Write_Command(0x01);
}
//根据xy坐标，写入对应的数据位置
void LCD_SetCursor(u8 X, u8 Y)
{
    switch(X)
	{
		case 1: LCD_Write_Command(0x80+Y); break;
		case 2: LCD_Write_Command(0x90+Y); break;
		case 3: LCD_Write_Command(0x88+Y); break;
		case 4: LCD_Write_Command(0x98+Y); break;
	}
		
}
/*********显示字符串的函数  ****************/
void DisStr(u8 *s)     //显示字符串的函数。
{
    while(*s != '\0')
    {
        LCD_Write_Date(*s);
        s++;
        delay_ms(2);//控制每一个字符之间显示的时间 间隔
    }
}

/********位置显示字符串函数  ****************/
void lcd_DisStr(u8 X,u8 Y,u8 *s)
{
   LCD_SetCursor( X, Y);
	 DisStr( s );
}

