/* ----------------------------------------------------------------------------
*  COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     lcd.c
*
* [DESCRIPTION]   
*     
*
* [NOTE]
*     
*
* [VERSION]
*    v1.00  2012/04/26 姜泉  新規作成
* ---------------------------------------------------------------------------*/
#define __LCD_C                

#include "oaks8lib.h"   /*"ledutl.h","lcdutl.h","swutl.h","intr.h" */
//#include "target.h"

#include "defs.h"

#include "led.h"
#include "timerx.h"
#include "lcddisp.h"
#include "lcd.h"

/*
static void s_SingalSwitch(void);
static void s_TimeEdit(u8 u8singalColor, u8 u8singalTime);
static u8 s_TimeJudge(u8 u8singalColor, s16 s16Time);
*/
//static void s_SingalRest(void);

/* ----------------------------------------------------------------------
* [FUNCTION]
*      s_SwitchSingal
*
* [DESCRIPTION]
*      信号の色を選択する関数
*
* [PARAMETERS]
*      u8 u8singalColor:  1:赤信号、2:黄信号、3:青信号
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      なし
*
* [VERSION]
*     v1.00  2012/04/26 姜泉  新規作成
* ---------------------------------------------------------------------- */
void s_SingalSwitch(void)
{
	u8 u8singalColor = CLEAR;                                       /*本地関数域変数*/
	
	for(;;)
	{
		g_DisplaySingalSwitch();									/*Src/lcddisp.h,信号選択画面*/
		u8singalColor = SW__getnum();								/*キーの入力を受信する*/
		switch(u8singalColor)	
		{			
			case S_U8_COLOR_RED :
				s_TimeEdit(u8singalColor,g_ctTimeSet.m_u8Red);  	/*Src/lcd.h,赤色の時間を編集する*/	
				break;
					
			case S_U8_COLOR_YELLOW :
				s_TimeEdit(u8singalColor,g_ctTimeSet.m_u8Yellow);	/*黄色の時間を編集する*/
				break;
			
			case S_U8_COLOR_GREEN :
				s_TimeEdit(u8singalColor,g_ctTimeSet.m_u8Green);	/*青色の時間を編集する*/
				break;
												
			case S_U8_COLOR_BACK : 
				return ;							                /*メインメニューへ戻る*/
													                   	
			default : 
																	/*ほかのキー処理する必要がありません*/
       			break;
		}
	}
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      void s_TimeEdit
*
* [DESCRIPTION]
*      時間設置関数
*
* [PARAMETERS]
*		u8 u8singalColor:  1:赤信号、2:黄信号、3:青信号
*		u8 u8singalTime:　信号の時間
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      なし
*
* [VERSION]
*     v1.00  2012/04/26 姜泉  新規作成
* ---------------------------------------------------------------------- */
void s_TimeEdit(u8 u8singalColor, u8 u8singalTime)
{
	u8 u8sure = CLEAR;
	u8 u8num = CLEAR;                                             /*入力の値,本地関数域変数*/
	u8 u8Limit = FALSE;                                           /*時間の範囲を判断する,本地関数域変数*/
	u8 u8swcounter = CLEAR;                                       /*入力の値の範囲は3位,本地関数域変数*/
	s16 s16Time = CLEAR;                                           /*入力した時間,本地関数域変数*/
	
	//LCD__clear();													/*LCDクリア*/	
	g_DisplaySingalEnsure();
	u8sure = SW__getnum();
	if(u8sure == '#')
	{
		return;	                                                        /*信号選択画面へ戻る*/
	}
	else if(u8sure == '*')
	{
		
		u8singalTime = 0;												/*上回の数値を初始化する*/
		//LCD__clear();													/*LCDクリア*/	
		g_DisplayTimeEdit();											/*Src/lcddisp.h,時間設置画面関数を呼びる*/
		g_LCDTimeInput(u8singalTime);									/*Src/lcddisp.h,上回の数値を表示する*/
		for(;;)
		{		
			u8num = SW__getnum();  										/*スイッチの状態を獲得する */
			if(u8num <= 9)                                              /*入力の値 */
			{
				u8swcounter++;
				if(u8swcounter <= 3)                                     /*入力の値の範囲は3位 */
				{	
					s16Time = s16Time * 10 + u8num;						/*時間を計算する*/	
					g_LCDTimeInput(s16Time);							/*LCDに時間の入力関数を呼びる*/		
				}
			
			}
			else if(u8num == '#') 										/*「＃」を押す、クリアする*/
			{
				s16Time = 0;                                            /*"# clear"の値 */ 
				g_LCDTimeInput(s16Time);    							/*LCDに時間の入力関数を呼びる */  
				u8swcounter = 0;
			}
			else if('*' == u8num)     									/*「＊」を押す、保存する*/  
			{
			
				u8Limit = s_TimeJudge(u8singalColor, s16Time);			/*Src/lcd.h,時間の範囲を判断する*/
				if(TRUE == u8Limit)
				{
					return ;                                            /*信号選択画面へ戻る*/	
				}
				
				u8swcounter = 0;				
				s16Time = 0;                                             /*	*/
				
								
				//LCD__clear();											/*LCDクリア	*/
				g_DisplayTimeEdit(); 									/*時間設置画面関数を呼びる*/
				g_LCDTimeInput(s16Time);    							/*LCDに時間の入力関数を呼びる */ 	
				//g_LCDTimeInput(u8singalTime);							/*上回の数値を表示する*/
			}	
		}		
	}
	else
	{
		g_DisplaySingalEnsureError();
		g_Time2sDelay();
		return;	                                                       /*信号選択画面へ戻る*/	
	}	
}

/* ----------------------------------------------------------------------
* [FUNCTION]
*      u8 s_TimeLimitJudge
*
* [DESCRIPTION]
*      時間範囲判断関数
*
* [PARAMETERS]
*		u8 u8singalColor: 1:赤信号、2:黄信号、3:青信号
* 		s16 s16Time: 入力した時間
*
* [RETURN VALUE]
*     u8
*
* [NOTE]
*      なし
*
* [VERSION]
*     v1.00  2012/04/26 姜泉  新規作成
* ---------------------------------------------------------------------- */
u8 s_TimeJudge(u8 u8singalColor, s16 s16Time)
{
	switch(u8singalColor)
	{
		case S_U8_COLOR_RED: 
			if((s16Time >= 120) || (s16Time <= 10))					/*赤信号の範囲を判断する*/
			{
				
				g_DisplayTimeEditError();							/*Src/lcddisp.h,赤信号の範囲のエラー画面関数を呼びる*/	
				g_Time2sDelay();    								/*2s遅延関数を呼びる*/					
				return FALSE;		
			}
			else
			{
				g_ctTimeSet.m_u8Red = s16Time;						/*構造体に設置した時間を授ける*/
				
				g_ctTimeDown.m_u8Red = g_ctTimeSet.m_u8Red;
				
				return TRUE;	 
			}				 
			break;
										 
		case S_U8_COLOR_YELLOW: 									/*黄信号の範囲を判断する*/
			if((s16Time >= 10) || (s16Time <= 3)) 
			{
				
				g_DisplayTimeEditError(); 							/*黄信号の範囲のエラー画面関数を呼びる*/
				g_Time2sDelay();     								/*2s遅延関数を呼びる */   
				return FALSE;			
			}
			else
			{	
				g_ctTimeSet.m_u8Yellow = s16Time;					/*構造体に設置した時間を授ける*/
				
				g_ctTimeDown.m_u8Yellow = g_ctTimeSet.m_u8Yellow;
				
				return TRUE;	 
			}						 
			break;
			
		case S_U8_COLOR_GREEN: 										/*青信号の範囲を判断する*/	
			if((s16Time >= 120) || (s16Time <= 10))					/*青信号の範囲のエラー画面関数を呼びる*/  
			{			
				g_DisplayTimeEditError();							/*2s遅延関数を呼びる*/
				g_Time2sDelay();  				
				return FALSE;		
			}
			else
			{
				g_ctTimeSet.m_u8Green = s16Time;					/*構造体に設置した時間を授ける*/
				
				g_ctTimeDown.m_u8Green = g_ctTimeSet.m_u8Green;
				
				return TRUE;	 
			}				 
			break;							 					 						 						
		default:
																	/*ほかの状況処理する必要がありません*/
       		break;					 	
	}
	return FALSE;                                                 	
}
