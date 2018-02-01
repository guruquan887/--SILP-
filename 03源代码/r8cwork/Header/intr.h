/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2011 RENESAS TECHNOLOGY CORPORATION
*   AND RENESAS SOLUTIONS CORPORATION ALL RIGHTS RESERVED
*
* [FILE]
*     intr.h
*
* [DESCRIPTION]
*     割り込み制御用定義ファイル
*
* [NOTE]
*     1. このプログラムは教育用です。(転用不可)
*     2. OAKS8-LCD Board対応
*     3. OAKS8-R5F21114FP(R8C/11グループ,20MHz)対応
*
* [VERSION]
*    v1.00  2011/05/20 RENESAS Semiconductor Training Center 新規作成
* ---------------------------------------------------------------------------*/

#ifndef __INTR_H
#define __INTR_H

extern void ei(void);                /* 割り込み許可関数 */
extern void di(void);                /* 割り込み禁止関数 */

#endif /* __INTR_H */


/******************************************************************************
    end of file
******************************************************************************/
