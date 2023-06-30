//Project :Digital Clock using Normal void delay()
#include<reg51.h>
unsigned int x,y,z;
void delay()
{
	for(x= 0;x<32790;x++);
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