/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2011 RENESAS TECHNOLOGY CORPORATION
*   AND RENESAS SOLUTIONS CORPORATION ALL RIGHTS RESERVED
*
* [FILE]
*     lcdutl.h
*
* [DESCRIPTION]
*     LCD�̐���
*
* [NOTE]
*     1. ���̃v���O�����͋���p�ł��B(�]�p�s��)
*     2. OAKS8-LCD Board�Ή�
*     3. OAKS8-R5F21114FP(R8C/11�O���[�v,20MHz)�Ή�
*
* [VERSION]
*     v1.00  2011/05/20 RENESAS Semiconductor Training Center  �V�K�쐬
* ---------------------------------------------------------------------------*/

#ifndef __LCDUTL_H
#define __LCDUTL_H

void LCD__initialize(void);				/* LCD���W���[���̏����ݒ�			 */
int LCD__clear(void);               	/* LCD�N���A               			 */
int LCD__setcursol(int x, int y); 		/* �\���ʒu���w�肷��      			 */
int LCD__putchar(int c);     			/* 1�����\������        			 */
int LCD__puts(const unsigned char *s);  /* �������\������     			 */
int LCD__putdec(unsigned int dec);		/* ���l��10�i�\������				 */
int LCD__puthex(unsigned int dec);		/* ���l��16�i�\������				 */

#endif /*__LCDUTL_H*/

/******************************************************************************
    end of file
******************************************************************************/
