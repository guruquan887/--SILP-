/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     timerx.h
*
* [DESCRIPTION]   
*     タイマーX用の割り込み定義ファイル
*
* [NOTE]
*
*
* [VERSION]
*     v1.00  2012/04/25 姜泉  新規作成
* ---------------------------------------------------------------------------*/
#ifndef __TIMERX_H
#define __TIMERX_H

extern BOOL g_bLEDIsRun;          /*LED運行状態,グローバルの変数定義*/

void g_TimerXInit(void);
void g_Time2sDelay(void);


#endif /*__TIMERX_H*/
/******************************************************************************
    end of file
******************************************************************************/
