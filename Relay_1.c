//Turn on the TWO 12V lapm one at a time with some delay using a 5V relay.
#include<reg51.h>
sbit a = P1^5;
sbit b = P3^0;
unsigned int x;
void delay()
{
  for(x= 0;x<28;x++)
  {
	TMOD = 0x01;
	TH0 = 0;
	TL0 = 0;
	TR0 = 1;
	while(TF0 == 0);
	TF0 = 0;
	TR0 = 0;
	}
}
void main()
{
	while(1)
	{
			b = 0;
			delay();
			b = 1;
			delay();
		}
}