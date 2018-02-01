/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     SignalLamp.c
*
* [DESCRIPTION]   
*     �}�C���t�@�C��
*
* [NOTE]
*
*
* [VERSION]
*     v1.00  2012/04/25 totyuedu  �V�K�쐬
* ---------------------------------------------------------------------------*/
//#ifndef __SIGNALLAMP_C
#define __SIGNALLAMP_C
//#endif /*__SIGNALLAMP_C*/

#include "defs.h"

#include "oaks8lib.h"       /*"ledutl.h","lcdutl.h","swutl.h","intr.h" */
//#include "target.h"
                 

#include "timerx.h"
#include "led.h"
#include "lcddisp.h"
#include "lcd.h"
/* ----------------------------------------------------------------------
* [FUNCTION]
*      main
*
* [DESCRIPTION]
*      �}�C���֐�
*
* [PARAMETERS]
*      void
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
* [VERSION]
*     v1.00  2012/4/25 �I��  �V�K�쐬
* ---------------------------------------------------------------------- */
void main(void)
{
	u8 u8State = CLEAR;      //unsigned char u8State = CLEAR;�@������ϐ��@/* SW�ԍ��ϐ�����`�y�я������@*/
	u8 u8StateOld = CLEAR;   //unsigned char u8 u8StateOld = CLEAR;   ������ϐ� /* ���C�����j���[��ʏ�ԕϐ�����`�y�я�����,���f"3:Pause"�������H�@*/
	u8 u8Rest = CLEAR;                                                 /*Rest��ʂ̒l,�{�n�֐���ϐ�*/
	
	//ei();
	
	//LCD__initialize();                                                 /*LCD������*/
	//SetLedDisp();                                    /*Header/ledutl.h,LED������,�Â����C�u�����݊�*/
	LED__initialize(); 				                   /*LED������*/
	//SW__initialize1();                                                 /*�L�[�}�g���N�X�֘A������*/
	
	g_TimerXInit();										               /*Src/timerx.h,TX������*/	        	                               
	g_DisplayWelcome(); 								               /*Src/lcddisp.h,���}���*/
	g_Time2sDelay();									               /*Src/lcddisp.h,2�b�x��*/
	ei();                                                               /*���荞�݋��֐�*/  
	
	for(;;)
	{
		g_DisplayMainMenu();							                /*Src/lcddisp.h,���C�����j���[���*/
		u8State = SW__getnum();	 							            /*SW�ԍ����͊֐�*/
	//	if(ERR != u8State)
	//	{
	//		return OK;                                                   //����
	//	}
	//	return ERR;                                                       //�ُ�
		
		switch(u8State)
		{
			case S_U8_STATE_START :                                     /*�J�n���,S_U8_STATE_START�̒l��1,�X�^�e�B�b�N�̃}�N����`*/  
				g_bLEDIsRun = TRUE;  					            	/*LED�^�s���,���ԍT,�O���[�o���̕ϐ���`*/                   
				u8StateOld = S_U8_STATE_START;
				break;
				
			case S_U8_STATE_RESET :	                                    /*���Z�b�g���,S_U8_STATE_RESE�̒l��2,�X�^�e�B�b�N�̃}�N����`*/		
				
				g_DisplayReset();
				u8Rest = SW__getnum();
				if(u8Rest == '#')
				{
					break;
				}
				else if(u8Rest == '*')
				{
					g_DisplayReseting();					
					g_ctTimeDown.m_u8Red = g_ctTimeInitial.m_u8Red;			/*Src/led.c,�������Ԃ̍\���̂�ݒu����B*/
					g_ctTimeDown.m_u8Yellow = g_ctTimeInitial.m_u8Yellow;
					g_ctTimeDown.m_u8Green = g_ctTimeInitial.m_u8Green;	
					
					g_ctTimeSet.m_u8Red = g_ctTimeInitial.m_u8Red;			/*Src/led.c,�������Ԃ̍\���̂�ݒu����B*/
					g_ctTimeSet.m_u8Yellow = g_ctTimeInitial.m_u8Yellow;
					g_ctTimeSet.m_u8Green = g_ctTimeInitial.m_u8Green;	
									
					g_Time2sDelay();
					
					LCD__clear();
					
					g_DisplayWelcome();
					g_Time2sDelay();
										
				}				
				//g_ctTimeDown.m_u8Red = g_ctTimeInitial.m_u8Red;			/*Src/led.c,�������Ԃ̍\���̂�ݒu����B*/
				//g_ctTimeDown.m_u8Yellow = g_ctTimeInitial.m_u8Yellow;
				//g_ctTimeDown.m_u8Green = g_ctTimeInitial.m_u8Green;				
				g_bLEDIsRun = TRUE;       								/*LED�^�s*/        
				u8StateOld = S_U8_STATE_RESET;      
				break;
				
			case S_U8_STATE_PAUSE :                                      /*��~���,S_U8_STATE_PAUSE�̒l��3,�X�^�e�B�b�N�̃}�N����`*/
				g_bLEDIsRun = FALSE;    					             /*LED�ꎞ��~*/         
				u8StateOld = S_U8_STATE_PAUSE;
				break;
								
			case S_U8_STATE_EDIT :                                      /*�ҏW���,S_U8_STATE_EDIT�̒l��4,�X�^�e�B�b�N�̃}�N����`*/
				if(S_U8_STATE_PAUSE == u8StateOld)                      /*���f"3:Pause"�������H*/
				{	
					s_SingalSwitch();									/*Src/lcd.c,�M���I���֐�,�X�^�e�B�b�N�̃}�N����`*/
				}	
				else
				{
					g_DisplayMainMenuError();							/*���C�����j���[�̃G���[���*/
					g_Time2sDelay();									/*2�b�x��*/				
				}
				break;

			default :  
																		/*�ق��̃L�[��������K�v������܂���*/
				break;
		}		
	}
}

