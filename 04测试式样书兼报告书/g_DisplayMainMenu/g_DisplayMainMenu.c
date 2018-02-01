#include"stdio.h"
#include  "defs.h"

void g_DisplayMainMenu(void);

int LCD__clear(void);   
int LCD__setcursol(int x, int y); 		/* �\���ʒu���w�肷��      			 */
int LCD__puts(const unsigned char *s);  /* �������\������     			 */


u8 g_u8LCDclear = 0;
u8 g_u8setcursol1[4] ={0,1,2,255};
u8 g_u8setcursol2[4] ={0,1,2,255};
const u8 *g_u8puts;

void main(void)
{
	printf("----�e�X�g�P�[�X----\n\n");
	printf("-------------------------------------\n");
	g_DisplayMainMenu();
}

void g_DisplayMainMenu(void)
{
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("1:START");
	LCD__setcursol(8, 0);
	LCD__puts("2:PAUSE");
	LCD__setcursol(0, 1);
	LCD__puts("3:RESET");
	LCD__setcursol(8, 1);
	LCD__puts("4:EDIT");
}

int LCD__clear(void)
{
	printf("g_u8LCDclear = %d\n",g_u8LCDclear);
	printf("----LCD�N���A----\n");

	g_u8LCDclear = 1;
	printf("g_u8LCDclear = %d\n",g_u8LCDclear);
	printf("-------------------------------------\n");
	return 0;
}

int LCD__setcursol(int x, int y)
{
	int i;
	for(i=0;i<4;i++)
	{
		printf("g_u8setcursol1 = %d\n",g_u8setcursol1[i]);
		printf("g_u8setcursol2 = %d\n",g_u8setcursol2[i]);
		printf("----�\���ʒu���w�肷��----\n");
	}
	return 0;

}

int LCD__puts(const unsigned char *s)
{
	g_u8puts=s;
	printf("----�������\������----\n");
	printf("%s\n",g_u8puts);
	printf("-------------------------------------\n");
	return 0;

}

