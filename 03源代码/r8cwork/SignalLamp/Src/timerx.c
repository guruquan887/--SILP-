/* ----------------------------------------------------------------------------
*  COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     timerx.c
*
* [DESCRIPTION]   
*     タイマーX用の割り込み実現ファイル
*
* [NOTE]
*     
*
* [VERSION]
*    v1.00  2012/04/25 姜泉  新規作成
* ---------------------------------------------------------------------------*/
#define __TIMERX_C

#include "defs.h"                  /*添加自帯ソース文件*/
#include "target.h"
#include "oaks8lib.h"

#include "led.h"                   /*添加文件*/
#include "timerx.h"

//gloabl
BOOL g_bLEDIsRun = FALSE;          /*LED停止状態,グローバルの変数定義*/

void g_TimerXInit(void);
void g_Time2sDelay(void);          /*遅延2秒関数,グローバルの関数定義*/

//staic
static u8 s_u8timer1sCount = 0;    /*本地文件域変数*/
static u8 s_u8timer2sCount = 0;    /*本地文件域変数*/

/* ----------------------------------------------------------------------
* [FUNCTION]
*      IntrTimerX()
*
* [DESCRIPTION]
*      タイマー(TX)割り込み,グローバルの定義の関数
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
#pragma interrupt IntrTimerX();            /*この関数は運行状態に保持しています*/
void IntrTimerX(void)
{
	//1s時間判断
	if(s_u8timer1sCount == 0)
	{
		s_u8timer1sCount = S_U8_TIME_1S;   /*1ミリ秒待ち時間,S_U8_TIME_1Sの値は200,スタティックのマクロ定義*/
		//LED運行であるかどうか
		if(g_bLEDIsRun == TRUE)
		{			
			g_SingalDisplay();           /*Src/led.h,LED初めて運行,グローバルの関数*/
		}		
	}
	//1s時間ない	
	else
	{
		s_u8timer1sCount--;                              
	}
	
	
	//2s時間ない
	if(s_u8timer2sCount != 0)                         
	{
		s_u8timer2sCount--;         
	}
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_TimerXInit()
*
* [DESCRIPTION]
*      タイマー(TX)初期化,グローバルの定義の関数
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
void g_TimerXInit(void)
{
	//セルフタイマー模式設置
	TXMR = 0x00;
	//タイマーカウントソース設定f8
	TCSS_ADDR.bit.b0=1;
	TCSS_ADDR.bit.b1=0; 
	//10mS時間を計算する
	PREX = 125 - 1;
	TX = 200 - 1;
	//割り込み優先レベル4
	TXIC = 0x04;
	//割り込みを始む
	TXS = 1;
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      s_Time2sDelay()
*
* [DESCRIPTION]
*      2秒遅延関数,グローバルの定義の関数
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
void g_Time2sDelay(void)
{
	//タイマーに数値を授ける。
	s_u8timer2sCount = G_U8_TIME_2S;  /*2ミリ秒待ち時間,G_U8_TIME_2Sの値は100,グローバルのマクロ定義*/
	//2s待つ
	while(s_u8timer2sCount != 0)
	{
	//何もしません
	}
	//終了
	return;	
}








