//71 msec delay
#include<reg51.h>
unsigned int x;
void delay()
{
	TMOD = 0x01 ; 
	TH0 = 0 ;
	TL0 = 0;
	TR0 = 1;
	while( TF0 == 0);
	TR0 = 0;
	TF0 = 0;
}
void main()
{
	while(1)
	{
	P1 = ~P1 ;
	delay();
	}
}