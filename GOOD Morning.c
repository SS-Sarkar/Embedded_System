//Transmit "GOOD MORNING " to the Virtual terminal continuously.
#include<reg51.h>
char s[] = "GOOD MORNING :)";
int x;
void main()
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1 = 1;
	for(x = 0;x < sizeof(s);x++)
	{
		SBUF = s[x];
		while(TI == 0);
		TI = 0;
	}
}