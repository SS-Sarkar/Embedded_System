//Complement port 1with 1 sec delay using T1M0.(TIMER1) using Mode 0
#include<reg51.h>
unsigned int x;
void delay()
{
	for(x =  0;x <112;x++)
	{
		TMOD = 0x00;
		TH0 = 0;
		TL0 = 0;
		TR0 = 1;
		while(TF0 == 0);
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