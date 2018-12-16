#include <stdio.h>
#include <stdlib.h>
#include "view.h"
#include "lcd.h"
#include "delay.h"

uint8_t a = 0;


void float_char(float slope, uint8_t *buffer, int n)  //浮点型数，存储的字符数组，字符数组的长度
{
    int temp, i, j;

    if (slope >= 0)//判断是否大于0
    {
        buffer[0] = '+';
    }
    else
    {
        buffer[0] = '-';
        slope = -slope;
    }

    temp = (int)slope;//取整数部分

    for ( i = 0; temp != 0; i++)//计算整数部分的位数
    {
        temp /= 10;
    }
    temp =(int)slope;
    for (j = i; j > 0; j--)//将整数部分转换成字符串型
    {
        buffer[j] = temp % 10 + '0';
        temp /= 10;
    }
    buffer[i + 1] = '.';
    slope -= (int)slope;
    for (i = i + 2; i < n - 1; i++)//将小数部分转换成字符串型
    {
        slope *= 10;
        buffer[i] = (int)slope + '0';
        slope -= (int)slope;
    }

    buffer[n - 1] = '\0';
}

void View_weight(float data)
{
	  
    

    if ( a == 0) 
    {
        a = 1;
        LCD_Clear(WHITE);		 
        LCD_ShowString(30,90,200,16,16,"weight: ");
    }

    //LCD_ShowString(90, 90, 200, 16, 16, buffer);
    delay_ms(500);
}


