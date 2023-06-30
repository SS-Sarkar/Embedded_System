//Monitor P3.5,if '1' display your name ,else display your surname in a 16x2 LCD
#include<reg51.h>
sbit m = P3^5;
sbit rs=P1^1;
sbit rw=P1^2;
sbit en=P1^3;
unsigned char data1[]="SADASIBA";
unsigned char data2[]="SARKAR";
unsigned int cmmd[]={0x38,0x0E,0x01,0x06,0x80};
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
	int a,b,c;
	while(1)
	{
		for(a=0;a<5;a++)
		{
			P2 = cmmd[a];
			cmm();
		}
		if(m == 1)
		{
			for(b=0;b<8;b++)
			{
				P2 = data1[b];
				dat();
			}
		}
		else
		{
			for(c=0;c<6;c++)
			{
				P2 = data2[c];
				dat();
			}
		}
	}
}