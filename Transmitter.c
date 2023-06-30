//Transmitter OR Toggle A
#include<reg51.h>
void main()
{	
	SCON = 0x50;
	TMOD = 0X20;
	TH1 = 0XFD;
	TR1 = 1;
	while(1)
	{
		SBUF = 'A';
		while(TI == 0);
		TI = 0;
	}
}