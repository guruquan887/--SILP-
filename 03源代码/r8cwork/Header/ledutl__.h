/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2011 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]
*     ledutl.h
*
* [DESCRIPTION]
*     LED�̐���
*
* [NOTE]
*     1. ���̃v���O�����͋���p�ł��B(�]�p�s��)
*     2. OAKS8-LCD Board�Ή�
*     3. OAKS8-R5F21114FP(R8C/11�O���[�v,20MHz)�Ή�
*
* [VERSION]
*     v1.00  2011/05/20 totyuedu  �V�K�쐬
* ---------------------------------------------------------------------------*/

#ifndef __LEDUTL_H
#define __LEDUTL_H

void SetLedDisp(void);					/* LED���W���[���̏����ݒ�		    */
void ClearLedDisp(void);				/* LED�N���A               			*/
int  SetLedDec(int led, int d);			/* �P��LED�ɐ��l��10�i�\������ 	*/
void SetLed3Dec(int d);					/* LED2�`0�ɐ��l��10�i�\������ 		*/
void SetLed4Dec(int d);					/* LED3�`0�ɐ��l��10�i�\������ 		*/

#endif /*__LEDUTL_H*/


/******************************************************************************
    end of file
******************************************************************************/
