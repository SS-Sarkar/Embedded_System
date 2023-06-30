//Send the value  -4 to +4 TO PORT 3 with some delay
#include<reg51.h>

void delay ()
{
	unsigned int x;
	for(x = 0; x< 50000;x++);
}
void main()
{
	while(1)
	{
		signed int i;
		for(i = -4;i< 5;i++)
		{
			P3 = i;
			delay();
		}
	}
}