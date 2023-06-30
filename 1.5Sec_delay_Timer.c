//1.5 sec delay
#include<reg51.h>
unsigned int x;
void delay()
{
	for(x=0;x<21;x++)
	{
	TMOD = 0x10 ; 
	TH1 = 0 ;
	TL1 = 0;
	TR1 = 1;
	while( TF1 == 0);
	TR1 = 0;
	TF1 = 0;
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