//A digital temperature sensor is connected to port3 .if temp>50 ,display the temp. on P0,if temp.<50 ,display on P1.
#include<reg51.h>
 /*void delay()
 {
	unsigned int x;
	for(x= 0;x<35000; x++);
}*/
void main()
{
	if(P3 > 50)
	{
		P0 = P3;
	}
	else if(P3 < 50)
	{
		P1 = P3;
	}

}