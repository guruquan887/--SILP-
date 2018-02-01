/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2011 RENESAS TECHNOLOGY CORPORATION
*   AND RENESAS SOLUTIONS CORPORATION ALL RIGHTS RESERVED
*
* [FILE]
*     defs.h
*
* [DESCRIPTION]
*     共通のシンボル定義
*
* [NOTE]
*     1. このプログラムは教育用です。(転用不可)
*     2. OAKS8-LCD Board対応
*     3. OAKS8-R5F21114FP(R8C/11グループ,20MHz)対応
*
* [VERSION]
*     v1.00  2011/05/20 RENESAS Semiconductor Training Center  新規作成
* ---------------------------------------------------------------------------*/

#ifndef __DEFS_H
#define __DEFS_H

#define SET     1               /* 1を設定する                              */
#define CLEAR   0               /* 0を設定する                              */

#define TRUE    1               /* 条件が成り立つ                           */
#define FALSE   0               /* 条件が成り立たない                       */

#define OK      0               /* 正常終了                                 */
#define ERR     -1              /* 異常終了                                 */

/*----- 型のの再定義］ -----*/
typedef unsigned char       u8;
typedef unsigned int        u16;
typedef unsigned long       u32;
typedef signed char         s8;
typedef signed int          s16;
typedef signed long         s32;

typedef unsigned char       BOOL;

/*----- 共用体ユーザ用フラグ型の宣言 -----*/
typedef union user_F{
   unsigned char all;           /* バイトアクセス用 */
   struct{
        unsigned char b0 : 1;   /* ビット0(LSB)     */
        unsigned char b1 : 1;   /* ビット1          */
        unsigned char b2 : 1;   /* ビット2          */
        unsigned char b3 : 1;   /* ビット3          */
        unsigned char b4 : 1;   /* ビット4          */
        unsigned char b5 : 1;   /* ビット5          */
        unsigned char b6 : 1;   /* ビット6          */
        unsigned char b7 : 1;   /* ビット7(MSB)     */
    }bit;                       /* ビットアクセス用 */
}FLAG;

/*120210 陳飛 begin*/
#define GREEN   1
#define YELLOW  2
#define RED     3
struct ColorTime
{
	u8 m_u8Red;
	u8 m_u8Yellow;
	u8 m_u8Green;
};
/*120210 陳飛 end*/
#endif /*__DEFS_H*/


/******************************************************************************
    end of file
******************************************************************************/
