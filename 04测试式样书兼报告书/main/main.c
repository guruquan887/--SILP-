#include "stdio.h"
#include "stdlib.h"
#include "defs.h"

u8 g_u8TimerXInit;
u8 g_u8LedInit;
u8 g_u8ei;
u8 g_u8DispWel;
u8 g_u82sDelay;
u8 g_bLEDIsRun;
u8 u8State;

u8 u8MainStateOld=0;
u8 g_SingalSwitch;
u8 g_DispMainError;

u8 a[]={0,1,2,3,4,2,4,5,255,'*','#'};

struct ColorTime g_ctTimeDown = {0, 0, 0};
struct ColorTime g_ctTimeInitial = {120, 10, 120};

void testmain(void);

void g_TimerXInit(void)
{
	printf("g_u8TimerXInit = %d\n", g_u8TimerXInit);
	printf("----�^�C�}�[(TX)������----\n");

	g_u8TimerXInit  = 1;
	printf("g_u8TimerXInit = %d\n", g_u8TimerXInit);
	printf("------------------------------------------------\n");
}

void s_SetLed(void)
{
	printf("g_u8LedInit = %d\n", g_u8LedInit);
	printf("----LED���W���[���̏����ݒ�----\n");
	g_u8LedInit = 1;
	printf("g_u8LedInit = %d\n", g_u8LedInit);
	printf("------------------------------------------------\n");
}

void ei(void)
{
	printf("g_u8ei = %d\n", g_u8ei);
	printf("----���荞�݋���----\n");

	g_u8ei = 1;
	printf("g_u8ei = %d\n", g_u8ei);
	printf("------------------------------------------------\n");
}

void g_DisplayWelcome(void)
{
	printf("g_u8DispWel = %d\n", g_u8DispWel);
	printf("----���}���----\n");

	g_u8DispWel = 1;
	printf("g_u8DispWel = %d\n", g_u8DispWel);
	printf("------------------------------------------------\n");
}

void g_Time2sDelay(void)
{
	printf("g_u82sDelay = %d\n", g_u82sDelay);
	printf("----2�b�x��----\n");

	g_u82sDelay = 1;
	printf("g_u82sDelay = %d\n", g_u82sDelay);
	printf("------------------------------------------------\n");
}

int SW__getnum(void)
{
	static int i;

	printf("u8State = %d\n", a[i]);
	printf("------------------------------------------------\n");
	i++;
	if(i==11)
	{
		exit(i);
	}
	return a[i];
}			

void g_DisplayMainMenu(void)
{
	static int i;
	printf("----u8State == %d----\n\n",a[i]);
	i++;

	printf("g_bLEDIsRun = %d\n", g_bLEDIsRun);

	printf("g_ctTimeDown.m_u8Red  = %d\n", 	g_ctTimeDown.m_u8Red );
	printf("g_ctTimeDown.m_u8Yellow = %d\n", g_ctTimeDown.m_u8Yellow);
	printf("g_ctTimeDown.m_u8Green = %d\n", g_ctTimeDown.m_u8Green);

	printf("g_SingalSwitch = %d\n", g_SingalSwitch);
	printf("g_DispMainError = %d\n", g_DispMainError);
	printf("g_u82sDelay = %d\n", g_u82sDelay);

	printf("------------------------------------------------\n");

	g_SingalSwitch=0;
	g_DispMainError=0;
	g_u82sDelay=0;
	
}

void g_DisplayMainMenuError(void)
{
	g_DispMainError = 1;
}

void s_SingalSwitch(void)
{
	g_SingalSwitch =1;
}


void main()
{
	g_u8TimerXInit = 0;
	g_u8LedInit = 0;
	g_u8ei = 0;
	g_u8DispWel = 0;
	g_u82sDelay = 0;

	u8State = 0;
	g_SingalSwitch = 0;
	g_DispMainError = 0;

	printf("----�e�X�g�P�[�X01----\n");

    testmain();

}



void testmain(void)
{
	u8 u8State = CLEAR;
	u8 u8MainStateOld = CLEAR;
	g_TimerXInit();
	
	s_SetLed();
	ei();                                              // ���荞�݋���
		        	                               
	g_DisplayWelcome();                                //���}���
	g_Time2sDelay();                                   //2�b�x��
	
	for(;;)
	{
		g_DisplayMainMenu();                          //���C�����j���[���
		u8State = SW__getnum();	                	//SW�ԍ����͊֐�
		
		switch(u8State)
		{
			case S_U8_STATE_START :
				g_bLEDIsRun = TRUE;                       //LED�^�s
				u8MainStateOld = S_U8_STATE_START;
				break;
				
			case S_U8_STATE_PAUSE :
				g_bLEDIsRun = FALSE;                      //LED�ꎞ��~
				u8MainStateOld = S_U8_STATE_PAUSE;
				break;
				
			case S_U8_STATE_RESET :			
				//�������Ԃ̍\���̂�ݒu����B
				g_ctTimeDown.m_u8Red = g_ctTimeInitial.m_u8Red;
				g_ctTimeDown.m_u8Yellow = g_ctTimeInitial.m_u8Yellow;
				g_ctTimeDown.m_u8Green = g_ctTimeInitial.m_u8Green;

				g_bLEDIsRun = TRUE;                      //LED�^�s
				u8MainStateOld = S_U8_STATE_RESET;      
				break;
				
			case S_U8_STATE_EDIT :
				if(S_U8_STATE_PAUSE == u8MainStateOld)
				{
					s_SingalSwitch();             //�M���I���֐�
				}	
				else
				{
					g_DisplayMainMenuError();    //���C�����j���[�̃G���[���
					g_Time2sDelay();             //2�b�x��						
				}
				break;

			default :  
				/*�ق��̃L�[��������K�v������܂���*/
       			break;
		}
	}	
}