/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2012 Hangzhou TotyuEdu Co., LTD
*   ALL RIGHTS RESERVED
*
* [FILE]      
*     SignalLamp.c
*
* [DESCRIPTION]   
*     マインファイル
*
* [NOTE]
*
*
* [VERSION]
*     v1.00  2012/04/25 totyuedu  新規作成
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
*      マイン関数
*
* [PARAMETERS]
*      void
*
* [RETURN VALUE]
*     void
*
* [NOTE]
*      なし
* [VERSION]
*     v1.00  2012/4/25 姜泉  新規作成
* ---------------------------------------------------------------------- */
void main(void)
{
	u8 u8State = CLEAR;      //unsigned char u8State = CLEAR;　文件域変数　/* SW番号変数名定義及び初期化　*/
	u8 u8StateOld = CLEAR;   //unsigned char u8 u8StateOld = CLEAR;   文件域変数 /* メインメニュー画面状態変数名定義及び初期化,判断"3:Pause"を押す？　*/
	u8 u8Rest = CLEAR;                                                 /*Rest画面の値,本地関数域変数*/
	
	//ei();
	
	//LCD__initialize();                                                 /*LCD初期化*/
	//SetLedDisp();                                    /*Header/ledutl.h,LED初期化,古いライブラリ互換*/
	LED__initialize(); 				                   /*LED初期化*/
	//SW__initialize1();                                                 /*キーマトリクス関連初期化*/
	
	g_TimerXInit();										               /*Src/timerx.h,TX初期化*/	        	                               
	g_DisplayWelcome(); 								               /*Src/lcddisp.h,歓迎画面*/
	g_Time2sDelay();									               /*Src/lcddisp.h,2秒遅延*/
	ei();                                                               /*割り込み許可関数*/  
	
	for(;;)
	{
		g_DisplayMainMenu();							                /*Src/lcddisp.h,メインメニュー画面*/
		u8State = SW__getnum();	 							            /*SW番号入力関数*/
	//	if(ERR != u8State)
	//	{
	//		return OK;                                                   //正常
	//	}
	//	return ERR;                                                       //異常
		
		switch(u8State)
		{
			case S_U8_STATE_START :                                     /*開始状態,S_U8_STATE_STARTの値は1,スタティックのマクロ定義*/  
				g_bLEDIsRun = TRUE;  					            	/*LED運行状態,時間控,グローバルの変数定義*/                   
				u8StateOld = S_U8_STATE_START;
				break;
				
			case S_U8_STATE_RESET :	                                    /*リセット状態,S_U8_STATE_RESEの値は2,スタティックのマクロ定義*/		
				
				g_DisplayReset();
				u8Rest = SW__getnum();
				if(u8Rest == '#')
				{
					break;
				}
				else if(u8Rest == '*')
				{
					g_DisplayReseting();					
					g_ctTimeDown.m_u8Red = g_ctTimeInitial.m_u8Red;			/*Src/led.c,初期時間の構造体を設置する。*/
					g_ctTimeDown.m_u8Yellow = g_ctTimeInitial.m_u8Yellow;
					g_ctTimeDown.m_u8Green = g_ctTimeInitial.m_u8Green;	
					
					g_ctTimeSet.m_u8Red = g_ctTimeInitial.m_u8Red;			/*Src/led.c,初期時間の構造体を設置する。*/
					g_ctTimeSet.m_u8Yellow = g_ctTimeInitial.m_u8Yellow;
					g_ctTimeSet.m_u8Green = g_ctTimeInitial.m_u8Green;	
									
					g_Time2sDelay();
					
					LCD__clear();
					
					g_DisplayWelcome();
					g_Time2sDelay();
										
				}				
				//g_ctTimeDown.m_u8Red = g_ctTimeInitial.m_u8Red;			/*Src/led.c,初期時間の構造体を設置する。*/
				//g_ctTimeDown.m_u8Yellow = g_ctTimeInitial.m_u8Yellow;
				//g_ctTimeDown.m_u8Green = g_ctTimeInitial.m_u8Green;				
				g_bLEDIsRun = TRUE;       								/*LED運行*/        
				u8StateOld = S_U8_STATE_RESET;      
				break;
				
			case S_U8_STATE_PAUSE :                                      /*停止状態,S_U8_STATE_PAUSEの値は3,スタティックのマクロ定義*/
				g_bLEDIsRun = FALSE;    					             /*LED一時停止*/         
				u8StateOld = S_U8_STATE_PAUSE;
				break;
								
			case S_U8_STATE_EDIT :                                      /*編集状態,S_U8_STATE_EDITの値は4,スタティックのマクロ定義*/
				if(S_U8_STATE_PAUSE == u8StateOld)                      /*判断"3:Pause"を押す？*/
				{	
					s_SingalSwitch();									/*Src/lcd.c,信号選択関数,スタティックのマクロ定義*/
				}	
				else
				{
					g_DisplayMainMenuError();							/*メインメニューのエラー画面*/
					g_Time2sDelay();									/*2秒遅延*/				
				}
				break;

			default :  
																		/*ほかのキー処理する必要がありません*/
				break;
		}		
	}
}

