#include<reg51.h>
sbit P2_0=P2^0;
unsigned char time;
unsigned char period=5;
unsigned char high=1;
timer0 () interrupt 1{
	if(++time== high)P2_0=0;
	else if(time== period)
{ time=0; P2_0=1;}
}
main()
{
	TMOD=0x02;
	TL0=0x38;
	EA=1;
	ET0=1;
	TR0=1;
do{}while(1);
}