/* ----------------------------------------------------------------------------
*  COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     led.c
*
* [DESCRIPTION]   
*     タイマーX用の割り込み実現ファイル
*
* [NOTE]
*     
*
* [VERSION]
*    v1.00  2012/04/26 姜泉 新規作成
* ---------------------------------------------------------------------------*/
#define __LED_C

#include "defs.h"
#include "oaks8lib.h"
//グローバル変数
struct ColorTime g_ctTimeSet = {13, 5, 13};      //設置した時間を保存する
struct ColorTime g_ctTimeDown = {12, 4, 12};     //減少した時間を保存する。
struct ColorTime g_ctTimeInitial = {10, 3, 10};  //初期化した時間を保存する。


//グローバル関数
void g_SingalDisplay(void);
//スタティック関数
static void s_SetLed(u8 u8color, u8 u8colortime);

/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_SingalDisplay
*
* [DESCRIPTION]
*      色と時間を判断する
*
* [PARAMETERS]
*      void
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      なし
* ---------------------------------------------------------------------- */
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
/* ----------------------------------------------------------------------
* [FUNCTION]
*      s_SetLed
*
* [DESCRIPTION]
*      LEDに色と時間を表示する。
*
* [PARAMETERS]
* 		u8color:色を表示する
*		u8colortime:色の時間を表示する
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      なし
* ---------------------------------------------------------------------- */
void s_SetLed(u8 u8color, u8 u8colortime)
{
	//LED3に色を表示
	SetLedDec(3, u8color);
	//LED2～0に時間を表示する
	SetLed3Dec(u8colortime);
}








