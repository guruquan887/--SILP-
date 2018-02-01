#include"stdio.h"
#include"defs.h"

void g_DisplayMainMenuError(void);
int LCD__clear(void);   
int LCD__setcursol(int x, int y); 	    			
int LCD__puts(const unsigned char *s);

u8 t_LCDclear = 0;
u8 t_LCDsetcursol = 0;
u8 t_setcursol1[] = {2};
u8 t_setcursol2[] = {2};
u8 t_LCDputs = 0;
const u8 *t_s;

void main()
{
	printf("---****g_DisplayMainMenuErrorテスト****---\n");
	g_DisplayMainMenuError();
}

void g_DisplayMainMenuError(void)
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
	printf("****LCD__clearテスト****\n");
	printf("t_LCDclear = %d\n",t_LCDclear);
	t_LCDclear=1;
	printf("t_LCDclear = %d\n",t_LCDclear);
	return 0;
}

int LCD__setcursol(int x, int y)
{
	printf("-----LCD__setcursolテスト-----\n");
	t_LCDsetcursol++;
	printf("t_LCDsetcursol = %d(LCD__setcursol %d番目の呼び出し )\n",t_LCDsetcursol,t_LCDsetcursol);
	t_setcursol1[t_LCDsetcursol]=x;
	t_setcursol2[t_LCDsetcursol]=y;
	printf("t_setcursol1 = %d\n",t_setcursol1[t_LCDsetcursol]);
	printf("t_setcursol2 = %d\n",t_setcursol2[t_LCDsetcursol]);
	return 0;

}

int LCD__puts(const unsigned char *s)
{	
	printf("*****LCD__putsテスト*****\n");
	t_LCDputs++;
	printf("（LCD__puts %d番目の呼び出し）\n",t_LCDputs);
	t_s=s;
	printf("%s\n",t_s);
	return 0;

}




