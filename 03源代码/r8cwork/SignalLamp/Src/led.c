/* ----------------------------------------------------------------------------
*  COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     led.c
*
* [DESCRIPTION]   
*     �^�C�}�[X�p�̊��荞�ݎ����t�@�C��
*
* [NOTE]
*     
*
* [VERSION]
*    v1.00  2012/04/26 �I�� �V�K�쐬
* ---------------------------------------------------------------------------*/
#define __LED_C

#include "defs.h"
#include "oaks8lib.h"
//�O���[�o���ϐ�
struct ColorTime g_ctTimeSet = {13, 5, 13};      //�ݒu�������Ԃ�ۑ�����
struct ColorTime g_ctTimeDown = {12, 4, 12};     //�����������Ԃ�ۑ�����B
struct ColorTime g_ctTimeInitial = {10, 3, 10};  //�������������Ԃ�ۑ�����B


//�O���[�o���֐�
void g_SingalDisplay(void);
//�X�^�e�B�b�N�֐�
static void s_SetLed(u8 u8color, u8 u8colortime);

/* ----------------------------------------------------------------------
* [FUNCTION]
*      g_SingalDisplay
*
* [DESCRIPTION]
*      �F�Ǝ��Ԃ𔻒f����
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
void g_SingalDisplay(void)
{
	
	
	//�ԐF�M�����f
	if(0 != g_ctTimeDown.m_u8Red)
	{
		g_ctTimeDown.m_u8Red--;
		 //�ԐF�M���Ǝ��ԕ\��
		s_SetLed(RED, g_ctTimeDown.m_u8Red);
	}
	else
	{
		 //�F�M�����f
		if(0 != g_ctTimeDown.m_u8Green)
		{
			g_ctTimeDown.m_u8Green--;
			//�F�M�Ǝ��ԕ\��
			s_SetLed(GREEN, g_ctTimeDown.m_u8Green);
		}
		else
		{
			//���F�M�����f
			if(0 != g_ctTimeDown.m_u8Yellow)
			{
				g_ctTimeDown.m_u8Yellow--;
				//���F�M�Ǝ��ԕ\��
				s_SetLed(YELLOW, g_ctTimeDown.m_u8Yellow);
				if(0 == g_ctTimeDown.m_u8Yellow)
				{
					//�\����TimeDown�ɍ\����TimeSet�̐ԐF���Ԃ��R�s�[����
					g_ctTimeDown.m_u8Red = g_ctTimeSet.m_u8Red;         
					//�\����TimeDown�ɍ\����TimeSet�̐F���Ԃ��R�s�[����
					g_ctTimeDown.m_u8Green = g_ctTimeSet.m_u8Green;
					//�\����TimeDown�ɍ\����TimeSet�̉��F���Ԃ��R�s�[����
					g_ctTimeDown.m_u8Yellow = g_ctTimeSet.m_u8Yellow; 
				}
			}
		}	
	}	
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      s_SetLed
*
* [DESCRIPTION]
*      LED�ɐF�Ǝ��Ԃ�\������B
*
* [PARAMETERS]
* 		u8color:�F��\������
*		u8colortime:�F�̎��Ԃ�\������
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
* ---------------------------------------------------------------------- */
void s_SetLed(u8 u8color, u8 u8colortime)
{
	//LED3�ɐF��\��
	SetLedDec(3, u8color);
	//LED2�`0�Ɏ��Ԃ�\������
	SetLed3Dec(u8colortime);
}








