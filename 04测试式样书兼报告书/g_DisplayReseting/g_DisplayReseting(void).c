#include"stdio.h"
#include  "defs.h"

void g_DisplayReseting(void);

int LCD__clear(void);   
int LCD__setcursol(int x, int y); 		
int LCD__puts(const unsigned char *s);  


u8 t_LCDclear = 0;
u8 t_setcursol = 0;
u8 t_setcursol1[] = {10};
u8 t_setcursol2[] = {20};
const u8 *t_s;
s16 lcd__puts = 0;

void main(void)
{
	printf("-------------�e�X�g�P�[�X------------\n");
	g_DisplayReseting();
	printf("-------------------------------------\n");
}

void g_DisplayReseting(void)
{
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Reseting");
	LCD__setcursol(0, 1);
	LCD__puts("R:100sG:100sY:5s");
}

int LCD__clear(void)
{
	printf("t_LCDclear = %d\n",t_LCDclear);
	printf("----------------LCD�N���A------------\n");

	t_LCDclear = 1;
	printf("t_LCDclear = %d\n",t_LCDclear);
	printf("-------------------------------------\n");
	return 0;
}

int LCD__setcursol(int x, int y)
{
	t_setcursol++;
	printf("----�\���ʒu���w�肷��----\n");
	printf("---------%d�Ԗڂ̃e�X�g--------\n",t_setcursol);
	t_setcursol1[t_setcursol] = x;
	t_setcursol2[t_setcursol] = y;
	printf("t_setcursol1 = %d\n",t_setcursol1[t_setcursol]);
	printf("t_setcursol2= %d\n",t_setcursol2[t_setcursol]);
	printf("-------------------------------------\n");
	return 0;
}

int LCD__puts(const unsigned char *s)
{
	printf("-----------�������\������----------\n");
	lcd__puts++;
	printf("---------%d�Ԗڂ̃e�X�g--------\n",lcd__puts);
	t_s=s;
	printf("%s\n",t_s);
	printf("-------------------------------------\n");
	return 0;

}
