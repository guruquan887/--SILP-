#include "stdio.h"
#include "defs.h"
void s_SwitchSingal();
void g_DisplaySingalSwitch();
int SW__getnum();
static void s_TimeEdit(u8 u8singalColor, u8 u8singalTime);
static u8 s_TimeLimitJudge(u8 u8singalColor, s16 s16Time);

struct ColorTime g_ctTimeSet = {120,10, 120};
struct ColorTime g_ctTimeDown = {120,10, 120};
struct ColorTime g_ctTimeInitial = {120,10, 120};

int i=0,b;
int back=0;
int a[]={0,1,2,3,5,6,7,8,9,'*','#',4,10};

void main()
{	
		s_SwitchSingal();
		back=1;
		printf("   back=%d back成功\n",back);
		printf("--------------------------------------------\n\n\n");
}

void s_SwitchSingal(void)
{
	u8 u8singalColor = CLEAR;
	
	for(;;)
	{
		g_DisplaySingalSwitch();									/*信号選択画面*/
		u8singalColor = SW__getnum();								/*キーの入力を受信する*/
		switch(u8singalColor)	
		{
			case S_U8_COLOR_GREEN :
				s_TimeEdit(u8singalColor,g_ctTimeSet.m_u8Green);	/*青色の時間を編集する*/
				break;
			
			case S_U8_COLOR_RED :
				s_TimeEdit(u8singalColor,g_ctTimeSet.m_u8Red);  	/*赤色の時間を編集する*/	
				break;
					
			case S_U8_COLOR_YELLOW :
				s_TimeEdit(u8singalColor,g_ctTimeSet.m_u8Yellow);	/*黄色の時間を編集する*/
				break;
												
			case S_U8_COLOR_BACK : 
				return;												/*メインメニューへ戻る*/
													                   	
			default : 
																	/*ほかのキー処理する必要がありません*/
       			break;
		}
	}
}

void g_DisplaySingalSwitch()
{
	printf("\n-------------------------------\n");
	printf("信号選択画面\n");
}

int SW__getnum()
{
	b=a[i];
	if(i==12)
		return;
	else
		i++;
	printf("SW__getnum()\n");
	printf("キーの値=%d",b);
	return b;
}
static void s_TimeEdit(u8 u8singalColor, u8 u8singalTime)
{
	printf("   s_TimeEdit()  ");
	printf("設置:色=%d,時間=%d",u8singalColor,u8singalTime);

}