/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2011 RENESAS TECHNOLOGY CORPORATION
*   AND RENESAS SOLUTIONS CORPORATION ALL RIGHTS RESERVED
*
* [FILE]
*     lcd1.h
*
* [DESCRIPTION]
*     LCD�p�჌�x��(�A�Z���u������)�v���O������`�t�@�C��
*
* [NOTE]
*     1. ���̃v���O�����͋���p�ł��B(�]�p�s��)
*     2. OAKS8-LCD Board�Ή�
*     3. OAKS8-R5F21114FP(R8C/11�O���[�v,20MHz)�Ή�
*
* [VERSION]
*     v1.00  2011/05/20 RENESAS Semiconductor Training Center  �V�K�쐬
* ---------------------------------------------------------------------------*/

#ifndef __LCD1_H
#define __LCD1_H

void _lcd1__initial(void);              /* LCD����|�[�g�̏����ݒ�          */
void _lcd1__wait(unsigned int t);       /* t�~100��s�\�t�g�E�F�A�E�F�C�g    */
void _lcd1__wr_nibble_creg(int command);/* LCD�փR�}���h����������          */
void _lcd1__wr_nibble_dreg(int data);   /* LCD�փf�[�^����������            */
int _lcd1__rd_nibble_creg(void);        /* LCD����R�}���h��ǂݍ���        */
int _lcd1__rd_nibble_dreg(void);        /* LCD����f�[�^��ǂݍ���          */


#endif /*__LCD1_H*/


/******************************************************************************
    end of file
******************************************************************************/
