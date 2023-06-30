//Monitor P1.20,if 1 send 0x0000FFFF to PORT0 ,Else send 0xFFFF0000 to PORT0

#include<lpc21xx.h>
#define BIT(x) (1<<x)
void delay()
{
	unsigned int y;
	for(y=0;y<65000;y++);
}
void main()
{
	PINSEL2 = 0;
	PINSEL1 = 0;
	while(1)
	{
		if(IO1PIN & BIT(20))
	 	{
	  		IO0DIR = 0x0000FFFF;
		} 
		else
		{
			IO0DIR = 0xFFFF0000;
		}
	}
}
