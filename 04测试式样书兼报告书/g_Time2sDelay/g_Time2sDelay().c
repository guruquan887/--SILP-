#include<stdio.h>
#include"defs.h"

u8 s_u8timer2sCount = 0;
void g_Time2sDelay(); 

void main()
{  
	int i;
	for(i = 0; i < 5; i++)
	{
		g_Time2sDelay();
	}
}
void g_Time2sDelay()
{
	s_u8timer2sCount=s_u8timer2sCount++;
	printf("-------------g_Time2sDelay()----------------\n");
	printf("s_u8timer2sCount = %d\n",s_u8timer2sCount);
	printf("---------------------------------------\n");
}
