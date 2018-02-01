/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2011 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]
*     ledutl.h
*
* [DESCRIPTION]
*     LEDの制御
*
* [NOTE]
*     1. このプログラムは教育用です。(転用不可)
*     2. OAKS8-LCD Board対応
*     3. OAKS8-R5F21114FP(R8C/11グループ,20MHz)対応
*
* [VERSION]
*     v1.00  2011/05/20 totyuedu  新規作成
* ---------------------------------------------------------------------------*/

#ifndef __LEDUTL_H
#define __LEDUTL_H

void LED__initialize(void);           	/* LEDモジュールの初期設定			*/
int LED__putchar(int led, int c);       /* 指定された桁に1文字表示する		*/
int LED__puthex(int led, int hex);		/* 指定された桁に数字を表示する		*/

void LED__clear(void);					/* LEDクリア               			*/
int  LED__putdec(int led, int dec);		/* 指定された桁に数字を10進表示する */
int  LED__put3dec(int dec);				/* LED2～0に数字を10進表示する 		*/
int  LED__put4dec(int dec);				/* LED3～0に数字を10進表示する 		*/


//-------------------------------------------------------
// 古いライブラリ互換のため
//-------------------------------------------------------
#define SetLedDisp()	 		LED__initialize()		
#define ClearLedDisp()			LED__clear()	
#define SetLedDec(led, dec)		LED__putdec(led, dec)
#define SetLed3Dec(dec)			LED__put3dec(dec)
#define SetLed4Dec(dec)			LED__put4dec(dec)

//-------------------------------------------------------


#endif /*__LEDUTL_H*/


/******************************************************************************
    end of file
******************************************************************************/
