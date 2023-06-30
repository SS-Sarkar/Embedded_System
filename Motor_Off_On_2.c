//	Rotate a motor 5sec clockwise, 2sec anticlockwise and 3sec off.
#include<reg51.h>
sbit a = P3^0;
sbit b = P3^1;
unsigned int i;
unsigned int x;
unsigned int y;
unsigned int z;
void delay()
{
	for(i = 0;i < 3600;i++)
	{
		TMOD = 0x02;
		TH0 = 0x00;
		TR0 = 1;
		while(TF0 == 0);
		TF0 = 0;
		TR0 = 0;
	}
}
void main()
{
	a = 0;
	b = 1;
	for(x = 0;x < 5;x++)
	{
		delay();
	}
	a = 1;
	b = 0;
	for(y = 0;y < 2;y++)
	{
		delay();
	}
	 a = 1;
	 b = 1;
	 for(z = 0;z < 3;z++)
	{
		delay();
	}
}