/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2011 RENESAS TECHNOLOGY CORPORATION
*   AND RENESAS SOLUTIONS CORPORATION ALL RIGHTS RESERVED
*
* [FILE]
*     defs.h
*
* [DESCRIPTION]
*     ���ʂ̃V���{����`
*
* [NOTE]
*     1. ���̃v���O�����͋���p�ł��B(�]�p�s��)
*     2. OAKS8-LCD Board�Ή�
*     3. OAKS8-R5F21114FP(R8C/11�O���[�v,20MHz)�Ή�
*
* [VERSION]
*     v1.00  2011/05/20 RENESAS Semiconductor Training Center  �V�K�쐬
* ---------------------------------------------------------------------------*/

#ifndef __DEFS_H
#define __DEFS_H

#define SET     1               /* 1��ݒ肷��                              */
#define CLEAR   0               /* 0��ݒ肷��                              */

#define TRUE    1               /* ���������藧��                           */
#define FALSE   0               /* ���������藧���Ȃ�                       */

#define OK      0               /* ����I��                                 */
#define ERR     -1              /* �ُ�I��                                 */


#define S_U8_STATE_START  1
#define S_U8_STATE_PAUSE  2
#define S_U8_STATE_RESET  3
#define S_U8_STATE_EDIT   4
#define S_U8_COLOR_RED    1
#define S_U8_COLOR_YELLOW 2
#define S_U8_COLOR_GREEN  3
#define S_U8_COLOR_BACK   4
#define S_U8_TIME_1S      100
#define G_U8_TIME_2S      200

#define RED    1
#define GREEN  2
#define YELLOW 3
/*----- �^�̂̍Ē�`�n -----*/
typedef unsigned char       u8;
typedef unsigned int        u16;
typedef unsigned long       u32;
typedef signed char         s8;
typedef signed int          s16;
typedef signed long         s32;

typedef unsigned char       BOOL;

/*----- ���p�̃��[�U�p�t���O�^�̐錾 -----*/
typedef union user_F{
   unsigned char all;           /* �o�C�g�A�N�Z�X�p */
   struct{
        unsigned char b0 : 1;   /* �r�b�g0(LSB)     */
        unsigned char b1 : 1;   /* �r�b�g1          */
        unsigned char b2 : 1;   /* �r�b�g2          */
        unsigned char b3 : 1;   /* �r�b�g3          */
        unsigned char b4 : 1;   /* �r�b�g4          */
        unsigned char b5 : 1;   /* �r�b�g5          */
        unsigned char b6 : 1;   /* �r�b�g6          */
        unsigned char b7 : 1;   /* �r�b�g7(MSB)     */
    }bit;                       /* �r�b�g�A�N�Z�X�p */
}FLAG;

struct ColorTime
{
	u8 m_u8Red;
	u8 m_u8Yellow;
	u8 m_u8Green;
};
#endif /*__DEFS_H*/


/******************************************************************************
    end of file
******************************************************************************/
