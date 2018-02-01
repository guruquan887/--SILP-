#include"stdio.h"
#include"defs.h"

void g_LCDTimeInput(s16 s16Time);
int LCD__clear(void);   
int LCD__setcursol(int x, int y); 	    			
int LCD__puts(const unsigned char *s);
int LCD__putdec(unsigned int dec);

u8 t_LCDclear = 0;
u8 t_LCDsetcursol = 0;
u8 t_setcursol1[] = {2};
u8 t_setcursol2[] = {2};
u8 t_LCDputs = 0;
const u8 *t_s;
u8 t_LCDputdec = 0;
u8 t_dec;
s16 t_Time=1;

void main()
{
	printf("----****g_LCDTimeInput�e�X�g****----\n");
	g_LCDTimeInput(t_Time);
}

void g_LCDTimeInput(s16 s16Time)
{
	//�J�[�\���̕\���ʒu���w�肷��
	LCD__setcursol(5, 0);
	//�����ȓ��͎��Ԃ�\������
	LCD__puts("   ");
	//�J�[�\���̕\���ʒu���w�肷��
	LCD__setcursol(5, 0);
	//�L���ȓ��͎��Ԃ�\������
	LCD__putdec(s16Time);	
}

int LCD__clear(void)
{
	printf("****LCD__clear�e�X�g****\n");
	printf("t_LCDclear = %d\n",t_LCDclear);
	t_LCDclear=1;
	printf("t_LCDclear = %d\n",t_LCDclear);
	return 0;
}

int LCD__setcursol(int x, int y)
{
	printf("-----LCD__setcursol�e�X�g-----\n");
	t_LCDsetcursol++;
	printf("t_LCDsetcursol = %d(LCD__setcursol %d�Ԗڂ̌Ăяo�� )\n",t_LCDsetcursol,t_LCDsetcursol);
	t_setcursol1[t_LCDsetcursol]=x;
	t_setcursol2[t_LCDsetcursol]=y;
	printf("t_setcursol1 = %d\n",t_setcursol1[t_LCDsetcursol]);
	printf("t_setcursol2 = %d\n",t_setcursol2[t_LCDsetcursol]);
	return 0;

}

int LCD__puts(const unsigned char *s)
{	
	printf("*****LCD__puts�e�X�g*****\n");
	t_LCDputs++;
	printf("�iLCD__puts %d�Ԗڂ̌Ăяo���j\n",t_LCDputs);
	t_s=s;
	printf("%s\n",t_s);
	return 0;

}

int LCD__putdec(unsigned int dec)
{
	printf("----LCD__putdec�e�X�g----\n");
	t_LCDputdec++;
	printf(" (LCD__putdec %d�Ԗڂ̌Ăяo���j\n",t_LCDputdec);
	t_dec=dec;
	printf("t_dec=%d\n",t_dec);
	return 0;
}
