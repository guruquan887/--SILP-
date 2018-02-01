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

void SetLedDisp(void);					/* LEDモジュールの初期設定		    */
void ClearLedDisp(void);				/* LEDクリア               			*/
int  SetLedDec(int led, int d);			/* １つのLEDに数値を10進表示する 	*/
void SetLed3Dec(int d);					/* LED2～0に数値を10進表示する 		*/
void SetLed4Dec(int d);					/* LED3～0に数値を10進表示する 		*/

#endif /*__LEDUTL_H*/


/******************************************************************************
    end of file
******************************************************************************/
