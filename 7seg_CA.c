//Display 0 to F using 7 segment common anode with  1 second delay
#include<reg51.h>
unsigned int a,x;
unsigned char Data[] = {0x8F,0x9F,0x7B,0x9D,0x3F,0xEF,0xF7,0xFF,0xE1,0xBF,0xB7,0x67,0xF3,0xDB,0x61,0xFD};
void delay()
{
	for(x =0;x <14;x++)
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
		for (a = 0;a < sizeof Data;a++)
		{
			P2 = ~Data[a];
			delay();
		}
	}
}