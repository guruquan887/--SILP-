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

void LED__initialize(void);           	/* LED���W���[���̏����ݒ�			*/
int LED__putchar(int led, int c);       /* �w�肳�ꂽ����1�����\������		*/
int LED__puthex(int led, int hex);		/* �w�肳�ꂽ���ɐ�����\������		*/

void LED__clear(void);					/* LED�N���A               			*/
int  LED__putdec(int led, int dec);		/* �w�肳�ꂽ���ɐ�����10�i�\������ */
int  LED__put3dec(int dec);				/* LED2�`0�ɐ�����10�i�\������ 		*/
int  LED__put4dec(int dec);				/* LED3�`0�ɐ�����10�i�\������ 		*/


//-------------------------------------------------------
// �Â����C�u�����݊��̂���
//-------------------------------------------------------
#define SetLedDisp()	 		LED__initialize()		
#define ClearLedDisp()			LED__clear()	
#define SetLedDec(led, dec)		LED__putdec(led, dec)
#define SetLed3Dec(dec)			LED__put3dec(dec)
#define SetLed4Dec(dec)			LED__put4dec(dec)

//-------------------------------------------------------


#endif /*__LEDUTL_H*/


/******************************************************************************
    end of file
******************************************************************************/
