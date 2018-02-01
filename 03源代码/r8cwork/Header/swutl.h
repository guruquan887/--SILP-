/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2011 RENESAS TECHNOLOGY CORPORATION
*   AND RENESAS SOLUTIONS CORPORATION ALL RIGHTS RESERVED
*
* [FILE]
*     swutl.h
*
* [DESCRIPTION]
*     ｷｰﾏﾄﾘｸｽの制御
*
* [NOTE]
*     1. このプログラムは教育用です。(転用不可)
*     2. OAKS8-LCD Board対応
*     3. OAKS8-R5F21114FP(R8C/11グループ,20MHz)対応
*
* [VERSION]
*     v1.00  2011/05/20 RENESAS Semiconductor Training Center  新規作成
* ---------------------------------------------------------------------------*/

#ifndef __SWUTL_H
#define __SWUTL_H

void SW__initialize1(void);			/* SW,キーマトリクス関連初期化関数		 */
void SW__initialize2(void);			/* プッシュスイッチSW5関連初期化関数	 */
int SW__getchar(void);				/* 一文字入力関数						 */
int SW__gets(unsigned  char * s);	/* 文字列入力関数						 */
int SW__getnum(void);				/* SW番号入力関数						 */
int SW__getdec(void);				/* 10進数値入力関数						 */


#endif /*__SWUTL_H*/

/******************************************************************************
    end of file
******************************************************************************/
