/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     lcd.h
*
* [DESCRIPTION]   
*     lcd表示定義ファイル
*
* [NOTE]
*
*
* [VERSION]
*     v1.00 2012/04/26　姜泉 新規作成
* ---------------------------------------------------------------------------*/
#ifndef __LCD_H
#define __LCD_H


void s_SingalSwitch(void);
void s_TimeEdit(u8 u8singalColor, u8 u8singalTime);
u8 s_TimeJudge(u8 u8singalColor, s16 s16Time);

#endif /*__LCDDISP_H*/
/******************************************************************************
    end of file
******************************************************************************/