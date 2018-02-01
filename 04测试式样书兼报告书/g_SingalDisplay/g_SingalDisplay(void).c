#include"stdio.h"
#include  "defs.h"

void g_SingalDisplay(void);

void s_SetLed(colour,time);

struct ColorTime g_ctTimeDown={0,0,0};
struct ColorTime g_ctTimeSet={0,0,0};

u8 t_TimeSetRED[]={0,120};
u8 t_TimeSetGREEN[]={0,120};
u8 t_TimeSetYELLOW[]={0,120};

u8 t_TimeDownRED[]={0,120};
u8 t_TimeDownGREEN[]={0,120};
u8 t_TimeDownYELLOW[]={0,120};
s16 t_count1,t_count2,t_count3;



void main(void)
{
	printf("-------------テストケース------------\n");
	for(t_count1=0;t_count1<2;t_count1++)
	{
	printf("---------------------------%d番目のテスト--------------------STRAT---------------\n",t_count1+1);
		for(t_count2=0;t_count2<2;t_count2++)
		{
			for(t_count3=0;t_count3<2;t_count3++)
			{
				g_ctTimeSet.m_u8Red=t_TimeSetRED[t_count1];
				printf("g_ctTimeSet.m_u8Red=%d\n",g_ctTimeSet.m_u8Red);
				g_ctTimeSet.m_u8Green=t_TimeSetGREEN[t_count1];
				printf("g_ctTimeSet.m_u8Green=%d\n",g_ctTimeSet.m_u8Green);
				g_ctTimeSet.m_u8Yellow=t_TimeSetYELLOW[t_count1];
				printf("g_ctTimeSet.m_u8Yellow=%d\n",g_ctTimeSet.m_u8Yellow);

				g_ctTimeDown.m_u8Red=t_TimeDownRED[t_count1];
				printf("g_ctTimeDown.m_u8Red=%d\n",g_ctTimeDown.m_u8Red);
				g_ctTimeDown.m_u8Green=t_TimeDownGREEN[t_count2];
				printf("g_ctTimeDown.m_u8Green=%d\n",g_ctTimeDown.m_u8Green);
				g_ctTimeDown.m_u8Yellow=t_TimeDownYELLOW[t_count3];
				printf("g_ctTimeDown.m_u8Yellow=%d\n",g_ctTimeDown.m_u8Yellow);
				g_SingalDisplay();
				printf("--------------------g_ctTimeSet.m_u8Red=%d\n",g_ctTimeSet.m_u8Red);
				printf("--------------------g_ctTimeSet.m_u8Green=%d\n",g_ctTimeSet.m_u8Green);
				printf("--------------------g_ctTimeSet.m_u8Yellow=%d\n",g_ctTimeSet.m_u8Yellow);

				printf("--------------------g_ctTimeDown.m_u8Red=%d\n",g_ctTimeDown.m_u8Red);
				printf("--------------------g_ctTimeDown.m_u8Green=%d\n",g_ctTimeDown.m_u8Green);
				printf("--------------------g_ctTimeDown.m_u8Yellow=%d\n",g_ctTimeDown.m_u8Yellow);
				
			}
		}
	printf("---------------------------%d番目のテスト--------------------END---------------\n",t_count1+1);
	}
}

void g_SingalDisplay(void)
{
	//赤色信号判断
	if(0 != g_ctTimeDown.m_u8Red)
	{
		g_ctTimeDown.m_u8Red--;
		 //赤色信号と時間表示
		s_SetLed(RED, g_ctTimeDown.m_u8Red);
	}
	else
	{
		 //青色信号判断
		if(0 != g_ctTimeDown.m_u8Green)
		{
			g_ctTimeDown.m_u8Green--;
			//青色信と時間表示
			s_SetLed(GREEN, g_ctTimeDown.m_u8Green);
		}
		else
		{
			//黄色信号判断
			if(0 != g_ctTimeDown.m_u8Yellow)
			{
				g_ctTimeDown.m_u8Yellow--;
				//黄色信と時間表示
				s_SetLed(YELLOW, g_ctTimeDown.m_u8Yellow);
				if(0 == g_ctTimeDown.m_u8Yellow)
				{
					//構造式TimeDownに構造式TimeSetの赤色時間をコピーする
					g_ctTimeDown.m_u8Red = g_ctTimeSet.m_u8Red;         
					//構造式TimeDownに構造式TimeSetの青色時間をコピーする
					g_ctTimeDown.m_u8Green = g_ctTimeSet.m_u8Green;
					//構造式TimeDownに構造式TimeSetの黄色時間をコピーする
					g_ctTimeDown.m_u8Yellow = g_ctTimeSet.m_u8Yellow; 
				}
			}
		}	
	}	
}

void s_SetLed(colour,time)
{
	printf("--------------------colour=%d\n",colour);
	printf("--------------------time=%d\n",time);
	return ;
}

