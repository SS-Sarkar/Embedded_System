//Project :Digital Clock using Timer void delay()
#include<reg51.h>
unsigned int x;
void delay()
{
	for(x= 0;x<14;x++)
	{
	TMOD = 0x01;
	TH0 = 0;
	TL0 = 0;
	TR0 = 1;
	while(TF0 == 0);
	TF0 = 0;
	TR0 = 0;
	}
}
//int a[];
int i,j,k ;
void main()
{	
		for(k= 0;k<24;k++)//Hour
			{
				P3 = k;
				for(j= 0;j<60;j++)//minute
					{
						P2 = j ;
						for(i= 0;i<60;i++)//second
							{
								P1 =i;
								delay();
							}
					}
			}
}