/* ----------------------------------------------------------------------------
*  COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     timerx.c
*
* [DESCRIPTION]   
*     �^�C�}�[X�p�̊��荞�ݎ����t�@�C��
*
* [NOTE]
*     
*
* [VERSION]
*    v1.00  2012/04/25 �I��  �V�K�쐬
* ---------------------------------------------------------------------------*/
#define __TIMERX_C

#include "defs.h"                  /*�Y�����у\�[�X����*/
#include "target.h"
#include "oaks8lib.h"

#include "led.h"                   /*�Y������*/
#include "timerx.h"

//gloabl
BOOL g_bLEDIsRun = FALSE;          /*LED��~���,�O���[�o���̕ϐ���`*/

void g_TimerXInit(void);
void g_Time2sDelay(void);          /*�x��2�b�֐�,�O���[�o���̊֐���`*/

//staic
static u8 s_u8timer1sCount = 0;    /*�{�n������ϐ�*/
static u8 s_u8timer2sCount = 0;    /*�{�n������ϐ�*/

/* ----------------------------------------------------------------------
* [FUNCTION]
*      IntrTimerX()
*
* [DESCRIPTION]
*      �^�C�}�[(TX)���荞��,�O���[�o���̒�`�̊֐�
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
#pragma interrupt IntrTimerX();            /*���̊֐��͉^�s��Ԃɕێ����Ă��܂�*/
void IntrTimerX(void)
{
	//1s���Ԕ��f
	if(s_u8timer1sCount == 0)
	{
		s_u8timer1sCount = S_U8_TIME_1S;   /*1�~���b�҂�����,S_U8_TIME_1S�̒l��200,�X�^�e�B�b�N�̃}�N����`*/
		//LED�^�s�ł��邩�ǂ���
		if(g_bLEDIsRun == TRUE)
		{			
			g_SingalDisplay();           /*Src/led.h,LED���߂ĉ^�s,�O���[�o���̊֐�*/
		}		
	}
	//1s���ԂȂ�	
	else
	{
		s_u8timer1sCount--;                              
	}
	
	
	//2s���ԂȂ�
	if(s_u8timer2sCount != 0)                         
	{
		s_u8timer2sCount--;         
	}
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_TimerXInit()
*
* [DESCRIPTION]
*      �^�C�}�[(TX)������,�O���[�o���̒�`�̊֐�
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
void g_TimerXInit(void)
{
	//�Z���t�^�C�}�[�͎��ݒu
	TXMR = 0x00;
	//�^�C�}�[�J�E���g�\�[�X�ݒ�f8
	TCSS_ADDR.bit.b0=1;
	TCSS_ADDR.bit.b1=0; 
	//10mS���Ԃ��v�Z����
	PREX = 125 - 1;
	TX = 200 - 1;
	//���荞�ݗD�惌�x��4
	TXIC = 0x04;
	//���荞�݂��n��
	TXS = 1;
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      s_Time2sDelay()
*
* [DESCRIPTION]
*      2�b�x���֐�,�O���[�o���̒�`�̊֐�
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
void g_Time2sDelay(void)
{
	//�^�C�}�[�ɐ��l��������B
	s_u8timer2sCount = G_U8_TIME_2S;  /*2�~���b�҂�����,G_U8_TIME_2S�̒l��100,�O���[�o���̃}�N����`*/
	//2s�҂�
	while(s_u8timer2sCount != 0)
	{
	//�������܂���
	}
	//�I��
	return;	
}








