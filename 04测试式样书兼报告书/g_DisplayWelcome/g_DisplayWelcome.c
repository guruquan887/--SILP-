#include"stdio.h"
#include  "defs.h"

void g_DisplayWelcome(void);

int LCD__clear(void);   
int LCD__setcursol(int x, int y); 		/* �\���ʒu���w�肷��      			 */
int LCD__puts(const unsigned char *s);  /* �������\������     			 */


u8 g_u8LCDclear = 0;
u8 g_u8setcursol1[] ={0,1,2,255};
u8 g_u8setcursol2[] ={0,1,2,255};

void main(void)
{
	printf("----�e�X�g�P�[�X----\n\n");
	printf("-------------------------------------\n");
	g_DisplayWelcome();
}

void g_DisplayWelcome(void)
{
	LCD__clear();
	LCD__setcursol(0, 0);
	LCD__puts("Welcome!");
	LCD__setcursol(0, 1);
	LCD__puts("We are T01!");	
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
		printf("g_u8setcursol1 = %d\n",x);
		printf("g_u8setcursol2 = %d\n",y);
		printf("-------------------------------------\n");
	}
	return 0;

}

int LCD__puts(const unsigned char *s)
{
	printf("----�������\������----\n");
	printf("%s\n",s);
	printf("-------------------------------------\n");
	return 0;

}

