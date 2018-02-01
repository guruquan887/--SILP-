#include <stdio.h>
#include "defs.h"

struct ColorTime g_ctTimeSet;
u8 u8singalColor[10] = {0,1,2,3,4,5,6,7,8,9};
s16 s16Time[11] = {-1,0,1,10,19,20,21,100,199,200,201};
u8 g_DisplayTimeError = 0;
u8 g_Time2sDe = 0;
u8 u8Limit = 2;

u8 s_TimeJudge(u8 u8singalColor, s16 s16Time);
void g_DisplayTimeEditError();
void g_Time2sDelay(); 

void main()
{
	int i,j;
	u8 u8singalColor[10] = {0,1,2,3,4,5,6,7,8,9};
	s16 s16Time[11] = {-1,0,1,10,19,20,21,100,199,200,201};
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 11; j++)
		{
			printf("****************TESTSTART****************\n");
			u8Limit = s_TimeJudge(u8singalColor[i], s16Time[j]);
			printf("u8singalColor[i] = %d\n",u8singalColor[i]);
			printf("s16Time = %d\n",s16Time[j]);
			printf("g_ctTimeSet.m_u8Red = %d\n",g_ctTimeSet.m_u8Red);
			printf("g_ctTimeSet.m_u8Yellow = %d\n",g_ctTimeSet.m_u8Yellow);
			printf("g_ctTimeSet.m_u8Green = %d\n",g_ctTimeSet.m_u8Green);
			printf("u8Limt = %d\n",u8Limit);
		}
	}
}

u8 s_TimeJudge(u8 u8singalColor, s16 s16Time)
{
	u8 Judge = FALSE; 
	switch(u8singalColor)
	{
		case S_U8_COLOR_GREEN: 										/*�M���͈̔͂𔻒f����*/	
			if((s16Time > 120) || (s16Time < 10))					/*�M���͈̔͂̃G���[��ʊ֐����Ăт�*/  
			{			
				g_DisplayTimeEditError();							/*2s�x���֐����Ăт�*/
				g_Time2sDelay();
				Judge = FALSE;  				
				return Judge;		
			}
			else
			{
				g_ctTimeSet.m_u8Green = s16Time;					/*�\���̂ɐݒu�������Ԃ�������*/
				Judge = TRUE; 
				return Judge;	 
			}				 
			break;

							 
		case S_U8_COLOR_YELLOW: 									/*���M���͈̔͂𔻒f����*/
			if((s16Time > 10) || (s16Time < 3)) 
			{
				
				g_DisplayTimeEditError(); 							/*���M���͈̔͂̃G���[��ʊ֐����Ăт�*/
				g_Time2sDelay();     								/*2s�x���֐����Ăт� */   
				Judge = FALSE; 
				return Judge;			
			}
			else
			{	
				g_ctTimeSet.m_u8Yellow = s16Time;					/*�\���̂ɐݒu�������Ԃ�������*/
				Judge = TRUE; 
				return Judge;	 
			}						 
			break;
			
						
		case S_U8_COLOR_RED: 
			if((s16Time > 120) || (s16Time < 10))					/*�ԐM���͈̔͂𔻒f����*/
			{
				
				g_DisplayTimeEditError();							/*�ԐM���͈̔͂̃G���[��ʊ֐����Ăт�*/	
				g_Time2sDelay();    								/*2s�x���֐����Ăт�*/					
				Judge = FALSE; 
				return Judge;		
			}
			else
			{
				g_ctTimeSet.m_u8Red = s16Time;						/*�\���̂ɐݒu�������Ԃ�������*/
				Judge = TRUE; 
				return Judge;	 
			}				 
			break;
							 					 						 						
		default:
																	/*�ق��̏󋵏�������K�v������܂���*/
       		break;					 	
	}
	return Judge;	
}






void g_DisplayTimeEditError()
{
	g_DisplayTimeError=1;
	printf("-------------g_DisplayTimeEditError()----------------\n");
	printf("g_DisplayTimeError = %d\n",g_DisplayTimeError);

}

void g_Time2sDelay()
{
	g_Time2sDe=1;
	printf("-------------g_Time2sDelay()----------------\n");
	printf("g_Time2sDe = %d\n",g_Time2sDe);
	printf("---------------------------------------\n");
}