//Addition and Substraction of PortsS
#include<reg51.h>
sbit a= P1^3;
void main()
{
	if(a == 1)
	{
	P0 = P2+P3;
	}
	else 
	{
	P0 = P2-P3;
	}
}