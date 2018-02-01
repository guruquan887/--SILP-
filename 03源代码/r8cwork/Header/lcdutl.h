/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2011 RENESAS TECHNOLOGY CORPORATION
*   AND RENESAS SOLUTIONS CORPORATION ALL RIGHTS RESERVED
*
* [FILE]
*     lcdutl.h
*
* [DESCRIPTION]
*     LCDの制御
*
* [NOTE]
*     1. このプログラムは教育用です。(転用不可)
*     2. OAKS8-LCD Board対応
*     3. OAKS8-R5F21114FP(R8C/11グループ,20MHz)対応
*
* [VERSION]
*     v1.00  2011/05/20 RENESAS Semiconductor Training Center  新規作成
* ---------------------------------------------------------------------------*/

#ifndef __LCDUTL_H
#define __LCDUTL_H

void LCD__initialize(void);				/* LCDモジュールの初期設定			 */
int LCD__clear(void);               	/* LCDクリア               			 */
int LCD__setcursol(int x, int y); 		/* 表示位置を指定する      			 */
int LCD__putchar(int c);     			/* 1文字表示する        			 */
int LCD__puts(const unsigned char *s);  /* 文字列を表示する     			 */
int LCD__putdec(unsigned int dec);		/* 数値を10進表示する				 */
int LCD__puthex(unsigned int dec);		/* 数値を16進表示する				 */

#endif /*__LCDUTL_H*/

/******************************************************************************
    end of file
******************************************************************************/
