// different delays on 500 mili sec and off 30 mili sec
#include<reg51.h>
sbit a = P3^5;
unsigned int x;
void delay1()
{
	for(x = 0;x<7;x++)
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
void delay2()
{
	TMOD = 0x10 ; 
	TH1 = 0x93 ;
	TL1 = 0xFF;
	TR1 = 1;
	while( TF1 == 0);
	TR1 = 0;
	TF1 = 0;
}
void main()
{
	while(1)
	{
	a = 1;
	delay1();
	a = 0;
	delay2();
	}
	
}