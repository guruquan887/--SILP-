#include<stdio.h>
#include"defs.h"
#include"unoion.h"
union byte_def TCSS_ADDR={0x00};

u8 TXMR=0;
u8 PREX=0;
u8 TX=0;         
u8 TXIC=0;
u8 TXS=0;
void g_TimerXInit(void);

void main()
{
	u8 TX_TXMR[]={0x00,0x01,0xff,0xff};
	u8 TX_TCSS_ADDRb0[]={0,1,0,1};
	u8 TX_TCSS_ADDRb1[]={0,1,0,1};
	u8 TX_PREX[]={0,1,124,255};
	u8 TX_TX[]={0,1,199,255}; 
	u8 TX_TXIC[]={0x00,0x04,0xff,0xff};
	u8 TX_TXS[]={0,1,255,255};
	u8 counter;
	for(counter=0;counter<4;counter++)
	{
		printf("TX_TXMR[counter]=%x\n",TX_TXMR[counter]);
		TXMR=TX_TXMR[counter];
		printf("TX_TCSS_ADDRb0[counter]=%d\n",TX_TXMR[counter]);
		TCSS_ADDR.bit.b0=TX_TCSS_ADDRb0[counter];
		printf("TX_TCSS_ADDRb1[counter]=%d\n",TX_TXMR[counter]);
		TCSS_ADDR.bit.b1=TX_TCSS_ADDRb1[counter];
		printf("TX_PREX[counter]=%d\n",TX_TXMR[counter]);
		PREX=TX_PREX[counter];
		printf("TX_TX[counter]=%d\n",TX_TXMR[counter]);
		TX=TX_TX[counter];
		printf("TX_TXIC[counter]=%x\n",TX_TXMR[counter]);
		TXIC=TX_TXIC[counter];
		printf("TX_TXS[counter]=%d\n",TX_TXMR[counter]);
		TXS=TX_TXS[counter];
		g_TimerXInit();
		printf("------------------------TXMR=0x%x\n",TXMR);
		printf("------------------------TCSS_ADDR.bit.b0=%d\n",TCSS_ADDR.bit.b0);
		printf("------------------------TCSS_ADDR.bit.b1=%d\n",TCSS_ADDR.bit.b1);
		printf("------------------------PREX=%d\n",PREX);
		printf("------------------------TX=%d\n",TX);
		printf("------------------------TXIC=0x%x\n",TXIC);
		printf("------------------------TXS=%d\n",TXS);



	}

}

void g_TimerXInit(void)
{
	//�Z���t�^�C�}�[�͎��ݒu
	TXMR = 0x00;
	//�^�C�}�J�E���g�\�[�X�ݒ�f8
	TCSS_ADDR.bit.b0 = 1;
	TCSS_ADDR.bit.b1 = 0; 
	//10mS���Ԃ��v�Z����
	PREX = 125 - 1;
	TX = 200 - 1;           
	//���荞�ݗD�惌�x��4
	TXIC = 0x04;	
	//���荞�݂��n��
	TXS = 1;			         
}
