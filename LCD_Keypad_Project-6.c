//Miniproject 6:LCD and Keypad interfacing
#include<reg51.h>
sbit rs=P1^1;
sbit rw=P1^2;
sbit en=P1^3;
unsigned int row[]={0xfe,0xfd,0xfb,0xf7};
unsigned int col[]={0xef,0xdf,0xbf,0x7f};
unsigned char key[] = "A987B654C321DE0F";
unsigned int a,b,c,d;
unsigned int cmmd[]={0x38,0x0E,0x01,0x06,0x80};
void delay()
{
	unsigned int x;
	for(x=0;x<33000;x++);
}
void cmm()
{
	rs = 0;
	rw = 0;
	en = 1;
	delay();
	en = 0;
}
void dat()
{
	rs = 1;
	rw = 0;
	en = 1;
	delay();
	en = 0;
}
void main()
{
	for(d=0;d<5;d++)
		{
			P3 = cmmd[d];
			cmm();
		}
	while(1)
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
			{
				P3 = key[a];
			  dat();
			}
			else
				a=a+1;
		}
	}
	
}
	}