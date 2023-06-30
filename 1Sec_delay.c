//1 sec delay using mode 1
#include<reg51.h>
unsigned int x;
void delay()
{
	for(x = 0;x<14;x++)
	{
	TMOD = 0x01 ; 
	TH0 = 0 ;
	TL0 = 0;
	TR0 = 1;
	while( TF0 == 0);
	TR0 = 0;
	TF0 = 0;
	}
}
void main()
{
	while(1)
	{
	P1 = ~P1 ;
	delay();
	}
}