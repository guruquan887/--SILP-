/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2011 RENESAS TECHNOLOGY CORPORATION
*   AND RENESAS SOLUTIONS CORPORATION ALL RIGHTS RESERVED
*
* [FILE]
*     swutl.h
*
* [DESCRIPTION]
*     ����ظ��̐���
*
* [NOTE]
*     1. ���̃v���O�����͋���p�ł��B(�]�p�s��)
*     2. OAKS8-LCD Board�Ή�
*     3. OAKS8-R5F21114FP(R8C/11�O���[�v,20MHz)�Ή�
*
* [VERSION]
*     v1.00  2011/05/20 RENESAS Semiconductor Training Center  �V�K�쐬
* ---------------------------------------------------------------------------*/

#ifndef __SWUTL_H
#define __SWUTL_H

void SW__initialize1(void);			/* SW,�L�[�}�g���N�X�֘A�������֐�		 */
void SW__initialize2(void);			/* �v�b�V���X�C�b�`SW5�֘A�������֐�	 */
int SW__getchar(void);				/* �ꕶ�����͊֐�						 */
int SW__gets(unsigned  char * s);	/* ��������͊֐�						 */
int SW__getnum(void);				/* SW�ԍ����͊֐�						 */
int SW__getdec(void);				/* 10�i���l���͊֐�						 */


#endif /*__SWUTL_H*/

/******************************************************************************
    end of file
******************************************************************************/
