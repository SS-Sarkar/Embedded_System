//Mini Project -2:Automatic voting machine
#include<reg51.h>
sbit a = P1^0;
sbit b = P1^1;
sbit c = P1^2;
sbit result = P1^3;
sbit d = P1^4;
sbit e = P1^5;
sbit f = P1^6;

void delay()
 {
	unsigned int x;
	for(x = 0;x<35000; x++);
}

void main()
{
	if (a == 0)
	{
		P0++;
		delay();
	}
	else if(b == 0)
	{
		P2++;
		delay();
	}
	else if(c == 0)
	{
		P3++;
		delay();
	}	
	else if(result == 0)
	{
		if(P0 > P2 && P0 > P3)
		{
			d = 0;
			delay ();
			d = 1;
		}
		else if(P2 > P0 && P2 > P3)
		{
		 e = 0;
			delay();
			e = 1;
		}
		else
		{
		f = 0;
			delay();
			f = 1;
		}
		delay();
	}
}
