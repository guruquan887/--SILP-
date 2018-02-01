/* ----------------------------------------------------------------------------
*  COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     lcd.c
*
* [DESCRIPTION]   
*     
*
* [NOTE]
*     
*
* [VERSION]
*    v1.00  2012/04/26 �I��  �V�K�쐬
* ---------------------------------------------------------------------------*/
#define __LCD_C                

#include "oaks8lib.h"   /*"ledutl.h","lcdutl.h","swutl.h","intr.h" */
//#include "target.h"

#include "defs.h"

#include "led.h"
#include "timerx.h"
#include "lcddisp.h"
#include "lcd.h"

/*
static void s_SingalSwitch(void);
static void s_TimeEdit(u8 u8singalColor, u8 u8singalTime);
static u8 s_TimeJudge(u8 u8singalColor, s16 s16Time);
*/
//static void s_SingalRest(void);

/* ----------------------------------------------------------------------
* [FUNCTION]
*      s_SwitchSingal
*
* [DESCRIPTION]
*      �M���̐F��I������֐�
*
* [PARAMETERS]
*      u8 u8singalColor:  1:�ԐM���A2:���M���A3:�M��
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
*
* [VERSION]
*     v1.00  2012/04/26 �I��  �V�K�쐬
* ---------------------------------------------------------------------- */
void s_SingalSwitch(void)
{
	u8 u8singalColor = CLEAR;                                       /*�{�n�֐���ϐ�*/
	
	for(;;)
	{
		g_DisplaySingalSwitch();									/*Src/lcddisp.h,�M���I�����*/
		u8singalColor = SW__getnum();								/*�L�[�̓��͂���M����*/
		switch(u8singalColor)	
		{			
			case S_U8_COLOR_RED :
				s_TimeEdit(u8singalColor,g_ctTimeSet.m_u8Red);  	/*Src/lcd.h,�ԐF�̎��Ԃ�ҏW����*/	
				break;
					
			case S_U8_COLOR_YELLOW :
				s_TimeEdit(u8singalColor,g_ctTimeSet.m_u8Yellow);	/*���F�̎��Ԃ�ҏW����*/
				break;
			
			case S_U8_COLOR_GREEN :
				s_TimeEdit(u8singalColor,g_ctTimeSet.m_u8Green);	/*�F�̎��Ԃ�ҏW����*/
				break;
												
			case S_U8_COLOR_BACK : 
				return ;							                /*���C�����j���[�֖߂�*/
													                   	
			default : 
																	/*�ق��̃L�[��������K�v������܂���*/
       			break;
		}
	}
}
/* ----------------------------------------------------------------------
* [FUNCTION]
*      void s_TimeEdit
*
* [DESCRIPTION]
*      ���Ԑݒu�֐�
*
* [PARAMETERS]
*		u8 u8singalColor:  1:�ԐM���A2:���M���A3:�M��
*		u8 u8singalTime:�@�M���̎���
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      �Ȃ�
*
* [VERSION]
*     v1.00  2012/04/26 �I��  �V�K�쐬
* ---------------------------------------------------------------------- */
void s_TimeEdit(u8 u8singalColor, u8 u8singalTime)
{
	u8 u8sure = CLEAR;
	u8 u8num = CLEAR;                                             /*���͂̒l,�{�n�֐���ϐ�*/
	u8 u8Limit = FALSE;                                           /*���Ԃ͈̔͂𔻒f����,�{�n�֐���ϐ�*/
	u8 u8swcounter = CLEAR;                                       /*���͂̒l�͈̔͂�3��,�{�n�֐���ϐ�*/
	s16 s16Time = CLEAR;                                           /*���͂�������,�{�n�֐���ϐ�*/
	
	//LCD__clear();													/*LCD�N���A*/	
	g_DisplaySingalEnsure();
	u8sure = SW__getnum();
	if(u8sure == '#')
	{
		return;	                                                        /*�M���I����ʂ֖߂�*/
	}
	else if(u8sure == '*')
	{
		
		u8singalTime = 0;												/*���̐��l�����n������*/
		//LCD__clear();													/*LCD�N���A*/	
		g_DisplayTimeEdit();											/*Src/lcddisp.h,���Ԑݒu��ʊ֐����Ăт�*/
		g_LCDTimeInput(u8singalTime);									/*Src/lcddisp.h,���̐��l��\������*/
		for(;;)
		{		
			u8num = SW__getnum();  										/*�X�C�b�`�̏�Ԃ��l������ */
			if(u8num <= 9)                                              /*���͂̒l */
			{
				u8swcounter++;
				if(u8swcounter <= 3)                                     /*���͂̒l�͈̔͂�3�� */
				{	
					s16Time = s16Time * 10 + u8num;						/*���Ԃ��v�Z����*/	
					g_LCDTimeInput(s16Time);							/*LCD�Ɏ��Ԃ̓��͊֐����Ăт�*/		
				}
			
			}
			else if(u8num == '#') 										/*�u���v�������A�N���A����*/
			{
				s16Time = 0;                                            /*"# clear"�̒l */ 
				g_LCDTimeInput(s16Time);    							/*LCD�Ɏ��Ԃ̓��͊֐����Ăт� */  
				u8swcounter = 0;
			}
			else if('*' == u8num)     									/*�u���v�������A�ۑ�����*/  
			{
			
				u8Limit = s_TimeJudge(u8singalColor, s16Time);			/*Src/lcd.h,���Ԃ͈̔͂𔻒f����*/
				if(TRUE == u8Limit)
				{
					return ;                                            /*�M���I����ʂ֖߂�*/	
				}
				
				u8swcounter = 0;				
				s16Time = 0;                                             /*	*/
				
								
				//LCD__clear();											/*LCD�N���A	*/
				g_DisplayTimeEdit(); 									/*���Ԑݒu��ʊ֐����Ăт�*/
				g_LCDTimeInput(s16Time);    							/*LCD�Ɏ��Ԃ̓��͊֐����Ăт� */ 	
				//g_LCDTimeInput(u8singalTime);							/*���̐��l��\������*/
			}	
		}		
	}
	else
	{
		g_DisplaySingalEnsureError();
		g_Time2sDelay();
		return;	                                                       /*�M���I����ʂ֖߂�*/	
	}	
}

/* ----------------------------------------------------------------------
* [FUNCTION]
*      u8 s_TimeLimitJudge
*
* [DESCRIPTION]
*      ���Ԕ͈͔��f�֐�
*
* [PARAMETERS]
*		u8 u8singalColor: 1:�ԐM���A2:���M���A3:�M��
* 		s16 s16Time: ���͂�������
*
* [RETURN VALUE]
*     u8
*
* [NOTE]
*      �Ȃ�
*
* [VERSION]
*     v1.00  2012/04/26 �I��  �V�K�쐬
* ---------------------------------------------------------------------- */
u8 s_TimeJudge(u8 u8singalColor, s16 s16Time)
{
	switch(u8singalColor)
	{
		case S_U8_COLOR_RED: 
			if((s16Time >= 120) || (s16Time <= 10))					/*�ԐM���͈̔͂𔻒f����*/
			{
				
				g_DisplayTimeEditError();							/*Src/lcddisp.h,�ԐM���͈̔͂̃G���[��ʊ֐����Ăт�*/	
				g_Time2sDelay();    								/*2s�x���֐����Ăт�*/					
				return FALSE;		
			}
			else
			{
				g_ctTimeSet.m_u8Red = s16Time;						/*�\���̂ɐݒu�������Ԃ�������*/
				
				g_ctTimeDown.m_u8Red = g_ctTimeSet.m_u8Red;
				
				return TRUE;	 
			}				 
			break;
										 
		case S_U8_COLOR_YELLOW: 									/*���M���͈̔͂𔻒f����*/
			if((s16Time >= 10) || (s16Time <= 3)) 
			{
				
				g_DisplayTimeEditError(); 							/*���M���͈̔͂̃G���[��ʊ֐����Ăт�*/
				g_Time2sDelay();     								/*2s�x���֐����Ăт� */   
				return FALSE;			
			}
			else
			{	
				g_ctTimeSet.m_u8Yellow = s16Time;					/*�\���̂ɐݒu�������Ԃ�������*/
				
				g_ctTimeDown.m_u8Yellow = g_ctTimeSet.m_u8Yellow;
				
				return TRUE;	 
			}						 
			break;
			
		case S_U8_COLOR_GREEN: 										/*�M���͈̔͂𔻒f����*/	
			if((s16Time >= 120) || (s16Time <= 10))					/*�M���͈̔͂̃G���[��ʊ֐����Ăт�*/  
			{			
				g_DisplayTimeEditError();							/*2s�x���֐����Ăт�*/
				g_Time2sDelay();  				
				return FALSE;		
			}
			else
			{
				g_ctTimeSet.m_u8Green = s16Time;					/*�\���̂ɐݒu�������Ԃ�������*/
				
				g_ctTimeDown.m_u8Green = g_ctTimeSet.m_u8Green;
				
				return TRUE;	 
			}				 
			break;							 					 						 						
		default:
																	/*�ق��̏󋵏�������K�v������܂���*/
       		break;					 	
	}
	return FALSE;                                                 	
}
