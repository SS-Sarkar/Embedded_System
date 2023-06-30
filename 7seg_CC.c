//Display 0 to F using 7 segment common cathode with  1 second delay
#include<reg51.h>
unsigned int a,x;
unsigned char Data[] = {0xFD,0x61,0xDB,0XF3,0X67,0XB7,0XBF,0XE1,0XFF,0XF7,0XEF,0X3F,0X9D,0X7B,0X9F,0X8F};
void delay()
{
	for(x =0;x <14;x++)
	{
		TMOD = 0x01;
		TH0 = 0;
		TL0 = 0;
		TR0 =1;
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
			P2 = Data[a];
			delay();
		}
	}
}