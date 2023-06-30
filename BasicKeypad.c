//Matrix Keypad
#include<reg51.h>
unsigned int row[]={0xfe,0xfd,0xfb,0xf7};
unsigned int col[]={0xef,0xdf,0xbf,0x7f};
unsigned int key[] = {0x0A,9,8,7,0x0B,6,5,4,0x0C,3,2,1,0x0D,0x0E,0,0x0F};
unsigned int a,b ,c;
void main()
{
	a =0;
	P2 = 0xf0;
	while(P2 == 0xf0);
	for(b=0;b<4;b++)
	{
		P2 = row[b];
		for(c=0;c<4;c++)
		{
			if((P2|0x0f)==col[c])
				P3 = key[a];
			else
				a=a+1;
		}
	}
}