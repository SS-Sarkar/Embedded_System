//Actuate a relay 5sec NO and 2 sec NC
#include<reg51.h>
sbit b = P3^0;
unsigned int x,i,j;
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
void main()
{
	while(1)
	{
			b = 0;
			for(i = 0;i<2;i++)
			{
				delay();
			}
			b = 1;
			for(j = 0;j<5;j++)
			{
				delay();
			}
		}
}