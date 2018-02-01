#include<stdio.h>
#include"defs.h"

void IntrTimerX(void);

u8 u8tC[]={0,1,100,255};
BOOL bLEDIR[]={TRUE,FALSE,TRUE,FALSE};
u8 g_SDisp=0;

u8 s_u8timer1sCount=0;
u8 s_u8timer2sCount=0;
u8 g_bLEDIsRun=FALSE;

void main()
{
	int counter1,counter2;
	for(counter1=0;counter1<4;counter1++)
	{
		s_u8timer2sCount=u8tC[counter1];
		s_u8timer1sCount=u8tC[counter1];
		for(counter2=0;counter2<2;counter2++)
		{
			g_bLEDIsRun=bLEDIR[counter2];
			printf("g_SDisp=%d\n",g_SDisp);
			printf("s_u8timer1sCount=%d\n",s_u8timer1sCount);
			printf("g_bLEDIsRun=%d\n",g_bLEDIsRun);
			printf("s_u8timer2sCount=%d\n",s_u8timer2sCount);
			IntrTimerX();
			printf("----------g_SDisp=%d\n",g_SDisp);
			printf("----------s_u8timer1sCount=%d\n",s_u8timer1sCount);
			printf("----------g_bLEDIsRun=%d\n",g_bLEDIsRun);
			printf("----------s_u8timer2sCount=%d\n",s_u8timer2sCount);
			g_SDisp=0;
		}

	}

}
void g_SingalDisplay(void)
{
	g_SDisp=1;
}

void IntrTimerX(void)
{
	//1sŽžŠÔ”»’f
	if(0 == s_u8timer1sCount)
	{
		s_u8timer1sCount = S_U8_TIME_1S;  
		//LED‰^s‚Å‚ ‚é‚©‚Ç‚¤‚©
		if(TRUE == g_bLEDIsRun)
		{
			//LED‰‚ß‚Ä‰^s
			g_SingalDisplay();
		}
	}
	//1sŽžŠÔ‚È‚¢
	else
	{
		s_u8timer1sCount--;                              
	}
	 //2sŽžŠÔ‚È‚¢
	if(0 != s_u8timer2sCount)                         
	{
		s_u8timer2sCount--;         
	}	
}
	

