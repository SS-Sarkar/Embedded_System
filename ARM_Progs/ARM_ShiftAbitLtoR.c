//Continuosly rotate a single bit from Left to Right in Port0
#include<lpc21xx.h>
#define BIT(x) (1<<x)
void delay()
{
	unsigned int x,y;
	for(x=0;x<6;x++)
	{
			for(y=0;y<65000;y++);
	}
}
void main()
{

	PINSEL1 = 0;
	IO0DIR = 0xffffffff;

	while(1)
	{
		int i;
		for(i=31;i>=0;i--)
		{
			IO0CLR = BIT(i+1);
			IO0SET = BIT(i);
			delay();
		}
	}
}
