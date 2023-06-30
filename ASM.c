/*Recieve a character,
if 'A' add the values of P1 and P2
if 'S' substract the values of P1 and P2
if 'M' Multiply the values of P1 and P2
Show the result in P0.
If any other key is pressed Transmit "INVALID KEY PRESSED"*/
#include<reg51.h>
char a[] = "Sorry,INVALID KEY PRESSED";
int x;
char c;
void main()
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1 = 1;
		while(RI == 0);
		c = SBUF;
		RI = 0;
	if(c == 'A')
	{
		P0 = P1+ P2;
	}
	else if(c == 'S')
	{
		P0 = P1-P2;
	}
	else if(c == 'M')
	{
		P0 = P1*P2;
	}
	else
	{
		for(x = 0;x < sizeof(a);x++)
	{
		SBUF = a[x];
		while(TI == 0);
		TI = 0;
	}
}
}
