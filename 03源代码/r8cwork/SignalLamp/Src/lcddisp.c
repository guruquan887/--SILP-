/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     lcddisp.c
*
* [DESCRIPTION]   
*     lcd����
*
* [NOTE]
*     �Ȃ�
* 
* [VERSION]
*     v1.00  2012/04/26 �@�I��  �V�K�쐬
* ---------------------------------------------------------------------------*/
//#ifndef __LCDDISP_C
#define __LCDDISP_C
//#endif  __LCDDISP_C

#include "oaks8lib.h"     /*"ledutl.h","lcdutl.h","swutl.h","intr.h" */
#include  "defs.h" 
#include   "lcd.h"
#include   "lcddisp.h"


void g_DisplayWelcome(void);
void g_DisplayMainMenu(void);
void g_DisplayMainMenuError(void);
void g_DisplaySingalSwitch(void);
void g_DisplaySingalEnsure(void);
void g_DisplayTimeEdit(void);
void g_DisplayTimeEditError(void);
void g_LCDTimeInput(s16 s16Time);
void g_DisplayReset(void);
void g_DisplayReseting(void);
void g_DisplaySingalEnsureError(void);


/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_DisplayWelcome()
*
* [DESCRIPTION]
*      ���}�ҏW��ʊ֐�
*
* [PARAMETERS]
*      void
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
* ---------------------------------------------------------------------- */
void g_DisplayWelcome(void)
{
	//LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Welcome!0(n_n)0");
	LCD__setcursol(0, 1);
	LCD__puts("We are T04!");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*     g_DisplayMainMenu()
*
* [DESCRIPTION]
*      ���C�����j���[��ʊ֐�
*
* [PARAMETERS]
*      void
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
* ---------------------------------------------------------------------- */
void g_DisplayMainMenu(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("1:Start");
	LCD__setcursol(8, 0);
	LCD__puts("2:Reset");
	LCD__setcursol(0, 1);
	LCD__puts("3:Pause");
	LCD__setcursol(8, 1);
	LCD__puts("4:Edit");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_DisplayMainMenuError()
*
* [DESCRIPTION]
*      ���C�����j���[�̃G���[��ʊ֐�
*
* [PARAMETERS]
*      void
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
* ---------------------------------------------------------------------- */
void g_DisplayMainMenuError(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Error!");
	LCD__setcursol(0, 1);
	LCD__puts("Pause first!");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_DisplaySingalSwitch()
*
* [DESCRIPTION]
*      �M���I����ʊ֐�
*
* [PARAMETERS]
*      void
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
* ---------------------------------------------------------------------- */
void g_DisplaySingalSwitch(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("1:Red");
	LCD__setcursol(8, 0);
	LCD__puts("2:Yellow");
	LCD__setcursol(0, 1);
	LCD__puts("3:Green");
	LCD__setcursol(8, 1);
	LCD__puts("4:Back");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_DisplaySingalEnsure()
*
* [DESCRIPTION]
*      ���Ԃ̐ݒu��ʊ֐�
*
* [PARAMETERS]
*      void
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
* ---------------------------------------------------------------------- */
void g_DisplaySingalEnsure(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Ensure?");
	LCD__setcursol(0, 1);
	LCD__puts("*:Ok");
	LCD__setcursol(8, 1);
	LCD__puts("#:Back");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_DisplayTimeEdit()
*
* [DESCRIPTION]
*      ���Ԃ̐ݒu��ʊ֐�
*
* [PARAMETERS]
*      void
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
* ---------------------------------------------------------------------- */
void g_DisplayTimeEdit(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Set time:");
	LCD__setcursol(0, 1);
	LCD__puts("*:Save");
	LCD__setcursol(8, 1);
	LCD__puts("#:Clear");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_DisplayTimeEditError()
*
* [DESCRIPTION]
*      ���Ԃ̐ݒu�̃G���[���
*
* [PARAMETERS]
*      void
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
* ---------------------------------------------------------------------- */
void g_DisplayTimeEditError(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Yellow:3~10");
	LCD__setcursol(0, 1);
	LCD__puts("Red/Green:10~120");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_LCDTimeInput()
*
* [DESCRIPTION]
*      ���͎��Ԋ֐�
*
* [PARAMETERS]
*      s16 �i0-999�j
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
* ---------------------------------------------------------------------- */
void g_LCDTimeInput(s16 s16Time)
{
	//LCD__clear();   //
	//�J�[�\���̕\���ʒu���w�肷��
	LCD__setcursol(10, 0);
	//�����ȓ��͎��Ԃ�\������
	LCD__puts("     ");
	//�J�[�\���̕\���ʒu���w�肷��
	LCD__setcursol(10, 0);
	//�L���ȓ��͎��Ԃ�\������
	LCD__putdec(s16Time);	
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*     g_DisplayReset()
*
* [DESCRIPTION]
*      �������I����ʊ֐�
*
* [PARAMETERS]
*      void
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
* ---------------------------------------------------------------------- */
void g_DisplayReset(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Reset?");
	LCD__setcursol(0, 1);
	LCD__puts("*:ok   #:back");
	
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*     g_DisplayReseting()
*
* [DESCRIPTION]
*    ��������ʊ֐�
*
* [PARAMETERS]
*      void
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
* ---------------------------------------------------------------------- */
void g_DisplayReseting(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Reseting");
	LCD__setcursol(0, 1);
	LCD__puts("R:10s Y:3s G:10s");
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*     g_Error()
*
* [DESCRIPTION]
*    Error��ʊ֐�
*
* [PARAMETERS]
*      void
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
* ---------------------------------------------------------------------- */
void g_DisplaySingalEnsureError(void)
{
	LCD__clear();
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Error!");
}
















