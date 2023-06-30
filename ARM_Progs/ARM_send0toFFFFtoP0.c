//Send values from 0000 to ffff to PORT0
#include<lpc21xx.h>
#define BIT(x) (1<<x)
unsigned int x;
void delay()
{
	for(x=0;x<35000;x++);
}
void main()
{
	IO0DIR = 0xffffffff;
	PINSEL1 = 0;
	while(1)
	{
		int i;
		for(i=0;i<0xffff;i++)//Or in place of 0xffff we can write 256
		{
			
			IO0PIN = i;
			delay();
		}
	}
}