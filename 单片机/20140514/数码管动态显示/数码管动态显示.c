#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar led_mod[]={0x12,0x06,0xfe,0x12,0x45};
uchar hh[]={0x00,0x10,0x20,0x30,0x40};
void delay(uint time)
{
	uint j;
	for(;time>0;time--)
	for(j=0;j<125;j++);
}
void main()
{
	char i=0,j;
	while(1)
	{
		for(j=0;j<5;j++){
		P3=hh[i];			//0
		P2=led_mod[i];	//
		delay(300);}
	}
}
