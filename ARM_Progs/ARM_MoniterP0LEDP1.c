/*Check the value of port 0, 
if >0xffff,glow P1.18
if <0xffff,glow P1.19
if =0xffff,glow P1.20
(only one led should glow at a time)*/
#include<lpc21xx.h>
#define BIT(x) (1<<x)
unsigned int x;
void delay()
{
	for(x=0;x<65000;x++);
}
void main()
{
	IO0DIR =  0x00000000;
	IO1DIR = 0xffffffff;
	PINSEL1 = 0;
	PINSEL2 = 0;
	while(1)
	{
		if(IO0PIN > 0xffff)
		{
			IO1SET |=BIT(18) ;
			IO1CLR |=BIT(19);
			IO1CLR |=BIT(20);
		}
		else if(IO0PIN < 0xffff)
		{
			IO1SET |=BIT(19);
			IO1CLR |=BIT(18);
			IO1CLR |=BIT(20);
		}
		else
		{
			IO1SET |=BIT(20) ;
			IO1CLR |=BIT(18);
			IO1CLR |=BIT(19);
		}
	}
}
