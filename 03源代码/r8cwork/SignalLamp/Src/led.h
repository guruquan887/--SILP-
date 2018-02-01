/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     led.h
*
* [DESCRIPTION]   
*     led表示定義ファイル
*
* [NOTE]
*
*
* [VERSION]
*     v1.00 2012/04/26　姜泉 新規作成
* ---------------------------------------------------------------------------*/
#ifndef __LED_H
#define __LED_H

extern struct ColorTime g_ctTimeSet;              //設置した時間を保存する。
extern struct ColorTime g_ctTimeDown;             //減少した時間を保存する。
extern struct ColorTime g_ctTimeInitial;          //初期化した時間を保存する。


//グローバル関数
void g_SingalDisplay(void);
//スタティック関数
static void s_SetLed(u8 u8color, u8 u8colortime);

#endif /*__LEDDISP_H*/
/******************************************************************************
    end of file
******************************************************************************/