//Project:7 Password Protected Doorlock system using LCD and Keypad
#include<reg51.h>
sbit rs=P1^1;
sbit rw=P1^2;
sbit en=P1^3;
int row[]={0xfe,0xfd,0xfb,0xf7};
int col[]={0xef,0xdf,0xbf,0x7f};
char key[] = "A987B654C321DE0F";
int a,b,c,d;
int cmmd[]={0x38,0x0E,0x01,0x06,0x80};
char a1[] = "ENTER PASSWORD:";
char op[] = "Virus";
int p[5];

char r[] ="PASSWORD DENIED,TRY AGAIN!";
char cr[] ="PASSWORD ACCEPTED";
int x,y,m,n,k,j=0;
void nextline()
{
	    SBUF=0X0D;
			while(TI == 0);
		  TI = 0;
}
void delay()
{
	int x;
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
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1 = 1;
	for(x = 0;x <15;x++)
	{
		SBUF = a1[x];
		while(TI == 0);
		TI = 0;
	}
  nextline();
	for(y = 0;y<5;y++)
	{
		while(RI == 0);
		p[y] = SBUF;
		
		RI = 0;
			SBUF='*';
			while(TI == 0);
		TI = 0;
		
	}
	nextline();
	for(k=0;k<5;k++)
	{
		if(p[k] == op[k])
		{
			j=j+1;
		}
	}
		if(j==5)
		{
			for(m = 0;m <17 ;m++)
		{
			SBUF = cr[m];
			while(TI == 0);
			TI = 0;
			j=0;
		}
		nextline();
	}
	else
	{
		for(n = 0;n<26;n++)
		{
			SBUF = r[n];
			while(TI == 0);
			TI = 0;
			j=0;
		}
		nextline();
	}
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
