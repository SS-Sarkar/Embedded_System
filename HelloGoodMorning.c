//WAP to dislay "HELLO" in the 1st row and "GOOD MORNING " in the 2nd row of a 16x2 LCD
#include<reg51.h>
sbit rs=P1^1;
sbit rw=P1^2;
sbit en=P1^3;
unsigned char data1[]="HELLO";
unsigned char data2[]="GOOD MORNING :)";
unsigned int cmmd1[]={0x38,0x0E,0x01,0x06,0x80};
unsigned int cmmd2[]={0x38,0x0E,0x01,0x06,0xC0};
void delay()
{
	unsigned int x;
	for(x=0;x<35000;x++);
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
	int a,b,c,d;
	while(1)
	{
		for(a=0;a<5;a++)
		{
			P2 = cmmd1[a];
			cmm();
		}
		for(b=0;b<5;b++)
		{
			P2 = data1[b];
			dat();
		}
		for(c=0;c<5;c++)
		{
			P2 = cmmd2[c];
			cmm();
		}
		for(d=0;d<15;d++)
		{
			P2 = data2[d];
			dat();
		}
	}
}