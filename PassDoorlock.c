//Project :4 Password Protected Doorlock
#include<reg51.h>
unsigned char a[] = "ENTER PASSWORD:";
unsigned char op[] = "Virus";
unsigned char p[5];

unsigned char r[] ="WRONG PASSWORD,TRY AGAIN!";
unsigned char cr[] ="CORRECT PASSWORD";
int x,y,m,n,k,j=0;
void nextline()
{
	    SBUF=0X0D;
			while(TI == 0);
		  TI = 0;
}
void main()
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1 = 1;
	for(x = 0;x <15;x++)
	{
		SBUF = a[x];
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
	}}
		if(j==5)
		{
			for(m = 0;m <16 ;m++)
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
		for(n = 0;n<25;n++)
		{
			SBUF = r[n];
			while(TI == 0);
			TI = 0;
			j=0;
		}
		nextline();
	}
}
