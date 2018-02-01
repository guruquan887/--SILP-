#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
u8 g_LCD_CLEAR = 0;
u8 g_DTE = 0;
u8 u8singalColor; 
u8 u8singalTime;
u8 g_LCDTI = 0;
u8 count = 0;
u8 u8SN;
u8 u8ST;
u8 u8num = 0;
s16 s16Time;
u8 u8Limit;

void LCD__clear();
void g_DisplayTimeEdit(); 
void g_LCDTimeInput(u8singalTime);
s_TimeJudge(u8singalColor, s16Time);
SW__getnum();
void s_TimeEdit(u8 u8singalColor, u8 u8singalTime);


void main()
{
	u8SN = 1;
	u8ST = 10;
	s_TimeEdit(u8SN,u8ST);

	return ;
}

void LCD__clear()
{
	g_LCD_CLEAR = 1;
	printf("----------LCD__CLEAR()-----------\n");
	printf("g_LCD_CLEAR = %d\n",g_LCD_CLEAR);
}
void g_DisplayTimeEdit()
{
	g_DTE = 1;
	printf("----------g_DisplayTimeEdit()-----------\n");
	printf("g_DTE = %d\n",g_DTE);
}
void g_LCDTimeInput(u8singalTime)
{
	g_LCDTI = 1;
	printf("----------g_LCDTimeInput()-----------\n");
	printf("u8swcounter <= 3!\n");
	printf("g_LCDTI = %d\n",g_LCDTI);
	printf("u8ST = %d\n",u8singalTime);
}
s_TimeJudge(u8singalColor, s16Time)
{
	u8Limit = 1;
	printf("--------------s_TimeJudge(u8singalColor, s16Time)------------\n");
	printf("u8Limit = %d\n",u8Limit);
	printf("u8SN = %d\n",u8singalColor);
	printf("s16Time = %d\n",s16Time);
}
SW__getnum()
{
	char t;
	printf("--------------s16Time--------------\n");
	printf("s16Time = %d\n",s16Time);
	printf("--------------g_LCDTimeInput(s16Time)------------\n");
	printf("g_LCDTI = %d\n",g_LCDTI);
	printf("s16Time = %d\n",s16Time);
	
	count++;
	if(count==10)
	{
		exit(count);
	}
	printf("***************************************\n");
	printf("Input a u8num:");
	scanf("%c",&t);
	getchar();
	if(t >= '0' && t <= '9')
	{
		t = t-0x30;
	}
	return t;

}

void s_TimeEdit(u8 u8singalColor, u8 u8singalTime)
{
	u8 u8num = CLEAR;
	u8 u8Limit = FALSE;
	u8 u8swcounter = CLEAR;
	s16 s16Time = CLEAR;
	LCD__clear();													/*LCDクリア*/
	g_DisplayTimeEdit();											/*時間設置画面関数を呼びる*/
	g_LCDTimeInput(u8singalTime);									/*上回の数値を表示する*/
	for(;;)
	{		
		u8num = SW__getnum();  										/*スイッチの状態を獲得する */
		if(u8num <= 9)
		{
			u8swcounter++;
			if(u8swcounter <= 3)
			{	
				s16Time = s16Time * 10 + u8num;						/*時間を計算する*/	
				g_LCDTimeInput(s16Time);							/*LCDに時間の入力関数を呼びる*/		
			}
			
		}
		else if('#' == u8num) 										/*「＃」を押す、クリアする*/
		{
			s16Time = -1;
			g_LCDTimeInput(s16Time);    							/*LCDに時間の入力関数を呼びる */  
			s16Time = 0;
			u8swcounter = 0;
		}
		else if('*' == u8num)     									/*「＊」を押す、保存する*/  
		{
			
			u8Limit = s_TimeJudge(u8singalColor, s16Time);			/*時間の範囲を判断する*/
			if(TRUE == u8Limit)
			{
				return ;	
			}
			u8swcounter = 0;
			LCD__clear();											/*LCDクリア	*/
			g_DisplayTimeEdit(); 									/*時間設置画面関数を呼びる*/	
			g_LCDTimeInput(u8singalTime);							/*上回の数値を表示する*/
		}	
	}	
}