//Toggle Port1 continuosly with some delay.
#include<lpc21xx.h>

unsigned int x;
void delay()
{
	for(x=0;x<30000;x++);
}
void main()
{
	IO1DIR=0xffffffff;
	while(1)
	{
		IO1PIN = ~IO1PIN;
		delay();
	} 
}