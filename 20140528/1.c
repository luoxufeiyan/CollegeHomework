#include<reg51.h>
unsigned char time;
unsigned char period=5;
unsigned char high=50;
timer0 () interrupt 1{
	TL0=0x38;
	if(++time= = high)P1=0;
	else if(time = = period)
{ time=0; P1=1;}
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