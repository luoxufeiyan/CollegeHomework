#include<reg51.h>
void delay();
sbit p1_0=P0.4;
sbit p2_0=P2.0;
void main()
{
	while(1)
	{
		p1_0=0;
		delay();
		p2_0=1;
		daley();
	}