/*Monitor P1.3 ,if 1 generate a time period on P3.3 with 500 ms delay 
using T1M2. If 0 generate a square wave on P3.3 with 100 micro sec
delay using T0M2*/
#include <reg51.h>
sbit a = P1^3;
sbit b = P3^3;
unsigned int x;
unsigned int y;
void delay1()
{
	for(x = 0; x<1800 ;x++)
	{
	TH1 = 0x00;
	TR1 = 1;
	while(TF1 == 0);
	TF1 = 0;
	TR1 = 0;
	}
}
void delay2()
{
	TH0 = 0xA4;
	TR0 = 1;
	while(TF0 == 0);
	TF0 = 0;
	TR0 = 0;
}
void main()
{
	TMOD = 0x22;
	while(1)
	{
		if (a == 1)
		{
		b = ~b;
		delay1();
		}
		else
		{
		b = ~b;
		delay2();
		}
	}
}
