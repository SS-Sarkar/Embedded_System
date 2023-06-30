//Toggle all pins of Port0 continuosly with some delay.
#include<lpc21xx.h>
unsigned int x;
void delay()
{
	for(x=0;x<30000;x++);
}
void main()
{	PINSEL1 = 0;
	IO0DIR=0xffffffff;
	while(1)
	{
		IO0PIN = ~IO0PIN;
		delay();
	} 
}