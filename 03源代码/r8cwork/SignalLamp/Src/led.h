/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     led.h
*
* [DESCRIPTION]   
*     led�\����`�t�@�C��
*
* [NOTE]
*
*
* [VERSION]
*     v1.00 2012/04/26�@�I�� �V�K�쐬
* ---------------------------------------------------------------------------*/
#ifndef __LED_H
#define __LED_H

extern struct ColorTime g_ctTimeSet;              //�ݒu�������Ԃ�ۑ�����B
extern struct ColorTime g_ctTimeDown;             //�����������Ԃ�ۑ�����B
extern struct ColorTime g_ctTimeInitial;          //�������������Ԃ�ۑ�����B


//�O���[�o���֐�
void g_SingalDisplay(void);
//�X�^�e�B�b�N�֐�
static void s_SetLed(u8 u8color, u8 u8colortime);

#endif /*__LEDDISP_H*/
/******************************************************************************
    end of file
******************************************************************************/