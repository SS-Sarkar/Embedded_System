//Mini Project: Visitor Counter
#include <reg51.h>
void delay()
 {
	unsigned int x;
	for(x = 0;x<35000; x++);
}
sbit a = P2^3;
sbit b = P2^4;
void main()
{
	delay();
	if(a == 1)
	{
	P1 ++;
	}
	else if (b == 1)
	{
	P1--;
	}
}