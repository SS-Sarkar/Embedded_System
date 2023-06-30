//In P3.7 crate the given Waveform 150ms using T0M2 and 30ms using T1M1.
#include<reg51.h>
sbit a = P3^7;
unsigned int x;
void delay1()
{
	for(x = 0; x < 540 ;x++)
	{
		TMOD = 0x02;
		TH0 = 0x00;
		TR0 = 1;
		while(TF0 == 0);
		TF0 = 0;
		TR0 = 0;
	}
}
void delay2()
{
	TMOD = 0x10;
	TH1 = 0x93;
	TL1 = 0xFF;
	TR1 = 1;
	while(TF1 == 0);
	TF1 = 0;
	TR1 = 0;
}
int y ;
void main()
{
	while(1)
	{
		a = 1;
		delay1();
		a = 0;
		delay1();
		for(y =0;y <3;y++)
		{
			a = 1;
			delay2();
			a = 0;
			delay2();
		}
	}
}