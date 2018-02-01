/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2011 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     lcddisp.h
*
* [DESCRIPTION]   
*     lcd表示定義ファイル
*
* [NOTE]
*
*
* [VERSION]
*     v1.00  2012/04/26 　姜泉  新規作成
* ---------------------------------------------------------------------------*/
#ifndef __LCDDISP_H
#define __LCDDISP_H

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

#endif /*__LCDDISP_H*/
/******************************************************************************
    end of file
******************************************************************************/

