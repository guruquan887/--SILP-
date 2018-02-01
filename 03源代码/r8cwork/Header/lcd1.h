/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2011 RENESAS TECHNOLOGY CORPORATION
*   AND RENESAS SOLUTIONS CORPORATION ALL RIGHTS RESERVED
*
* [FILE]
*     lcd1.h
*
* [DESCRIPTION]
*     LCD用低レベル(アセンブリ言語)プログラム定義ファイル
*
* [NOTE]
*     1. このプログラムは教育用です。(転用不可)
*     2. OAKS8-LCD Board対応
*     3. OAKS8-R5F21114FP(R8C/11グループ,20MHz)対応
*
* [VERSION]
*     v1.00  2011/05/20 RENESAS Semiconductor Training Center  新規作成
* ---------------------------------------------------------------------------*/

#ifndef __LCD1_H
#define __LCD1_H

void _lcd1__initial(void);              /* LCD制御ポートの初期設定          */
void _lcd1__wait(unsigned int t);       /* t×100μsソフトウェアウェイト    */
void _lcd1__wr_nibble_creg(int command);/* LCDへコマンドを書き込む          */
void _lcd1__wr_nibble_dreg(int data);   /* LCDへデータを書き込む            */
int _lcd1__rd_nibble_creg(void);        /* LCDからコマンドを読み込む        */
int _lcd1__rd_nibble_dreg(void);        /* LCDからデータを読み込む          */


#endif /*__LCD1_H*/


/******************************************************************************
    end of file
******************************************************************************/
