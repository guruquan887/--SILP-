#include<stdio.h>
#include"defs.h"

void s_SetLed(u8 u8color, u8 u8colortime);

void SetLedDec(u8 SLD, u8 u8color);
void SetLed3Dec(u8 u8colortime);

u8 col[]={0,1,2,3,255};
u8 colt[]={0,1,199,244,255};
int main()
{
	int count;
	for(count=0;count<5;count++)
	{
		printf("col[count]=%d\n",col[count]);
		printf("colt[count]=%d\n",colt[count]);
		s_SetLed(col[count],colt[count]);
	}

}
void s_SetLed(u8 u8color, u8 u8colortime)
{
	//LED3‚ÉF‚ð•\Ž¦
	SetLedDec(3, u8color);
	//LED2`0‚ÉŽžŠÔ‚ð•\Ž¦‚·‚é
	SetLed3Dec(u8colortime);
}

void SetLedDec(u8 SLD, u8 u8color)
{
	printf("---------------SLD=%d\n",SLD);
	printf("---------------u8color=%d\n",u8color);
}
void SetLed3Dec(u8 u8colortime)
{
	printf("---------------u8colortime=%d\n",u8colortime);
}
