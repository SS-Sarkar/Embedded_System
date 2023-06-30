//Shift right the input given in PORT1 and show the result in PORT0.
#include<reg51.h>

void delay ()
{
	unsigned int x;
	for(x = 0; x< 30000;x++);
}
void main()
{
	P0 = P1 >>1;
	delay();
}