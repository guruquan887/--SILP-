/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     lcddisp.c
*
* [DESCRIPTION]   
*     lcd入力
*
* [NOTE]
*     なし
* 
* [VERSION]
*     v1.00  2012/04/26 　姜泉  新規作成
* ---------------------------------------------------------------------------*/
//#ifndef __LCDDISP_C
#define __LCDDISP_C
//#endif  __LCDDISP_C

#include "oaks8lib.h"     /*"ledutl.h","lcdutl.h","swutl.h","intr.h" */
#include  "defs.h" 
#include   "lcd.h"
#include   "lcddisp.h"


void g_DisplayWelcome(void);
void g_DisplayMainMenu(void);
void g_DisplayMainMenuError(void);
void g_DisplaySingalSwitch(void);
void g_DisplaySingalEnsure(void);
void g_DisplayTimeEdit(void);
void g_DisplayTimeEditError(void);
void g_LCDTimeInput(s16 s16Time);
void g_DisplayReset(void);
void g_DisplayReseting(void);
void g_DisplaySingalEnsureError(void);


/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_DisplayWelcome()
*
* [DESCRIPTION]
*      歓迎編集画面関数
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
void g_DisplayWelcome(void)
{
	//LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Welcome!0(n_n)0");
	LCD__setcursol(0, 1);
	LCD__puts("We are T04!");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*     g_DisplayMainMenu()
*
* [DESCRIPTION]
*      メインメニュー画面関数
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
void g_DisplayMainMenu(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("1:Start");
	LCD__setcursol(8, 0);
	LCD__puts("2:Reset");
	LCD__setcursol(0, 1);
	LCD__puts("3:Pause");
	LCD__setcursol(8, 1);
	LCD__puts("4:Edit");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_DisplayMainMenuError()
*
* [DESCRIPTION]
*      メインメニューのエラー画面関数
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
void g_DisplayMainMenuError(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Error!");
	LCD__setcursol(0, 1);
	LCD__puts("Pause first!");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_DisplaySingalSwitch()
*
* [DESCRIPTION]
*      信号選択画面関数
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
void g_DisplaySingalSwitch(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("1:Red");
	LCD__setcursol(8, 0);
	LCD__puts("2:Yellow");
	LCD__setcursol(0, 1);
	LCD__puts("3:Green");
	LCD__setcursol(8, 1);
	LCD__puts("4:Back");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_DisplaySingalEnsure()
*
* [DESCRIPTION]
*      時間の設置画面関数
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
void g_DisplaySingalEnsure(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Ensure?");
	LCD__setcursol(0, 1);
	LCD__puts("*:Ok");
	LCD__setcursol(8, 1);
	LCD__puts("#:Back");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_DisplayTimeEdit()
*
* [DESCRIPTION]
*      時間の設置画面関数
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
void g_DisplayTimeEdit(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Set time:");
	LCD__setcursol(0, 1);
	LCD__puts("*:Save");
	LCD__setcursol(8, 1);
	LCD__puts("#:Clear");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_DisplayTimeEditError()
*
* [DESCRIPTION]
*      時間の設置のエラー画面
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
void g_DisplayTimeEditError(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Yellow:3~10");
	LCD__setcursol(0, 1);
	LCD__puts("Red/Green:10~120");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_LCDTimeInput()
*
* [DESCRIPTION]
*      入力時間関数
*
* [PARAMETERS]
*      s16 （0-999）
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      なし
* ---------------------------------------------------------------------- */
void g_LCDTimeInput(s16 s16Time)
{
	//LCD__clear();   //
	//カーソルの表示位置を指定する
	LCD__setcursol(10, 0);
	//無効な入力時間を表示する
	LCD__puts("     ");
	//カーソルの表示位置を指定する
	LCD__setcursol(10, 0);
	//有効な入力時間を表示する
	LCD__putdec(s16Time);	
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*     g_DisplayReset()
*
* [DESCRIPTION]
*      初期化選択画面関数
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
void g_DisplayReset(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Reset?");
	LCD__setcursol(0, 1);
	LCD__puts("*:ok   #:back");
	
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*     g_DisplayReseting()
*
* [DESCRIPTION]
*    初期化画面関数
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
void g_DisplayReseting(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Reseting");
	LCD__setcursol(0, 1);
	LCD__puts("R:10s Y:3s G:10s");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*     g_Error()
*
* [DESCRIPTION]
*    Error画面関数
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
void g_DisplaySingalEnsureError(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Error!");
}
















