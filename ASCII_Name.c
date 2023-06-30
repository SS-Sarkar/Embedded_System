//Send the ASCII value of your name to port 2 with some delay.
#include<reg51.h>
char a[] = {"SADASIBA"};
int i;
void delay()
{
	unsigned int x;
	for(x = 0;x < 60000; x++);
}
void main()
{
	while(1)
	{
		for(i = 0;i <8;i++)
		{
			P2 = a[i];
			delay();
		}
	}
}