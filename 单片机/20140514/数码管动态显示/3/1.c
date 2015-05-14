#include<reg51.h>
char led_mod[]={0x76,0x79,0x38,0x38,0x3f};
char shu_mod[]={0xf0,0xe8,0xd8,0xb8,0x78};
void delay(unsigned int i)
{
 	unsigned int j=0;
 	for(;i>0;i--)
 	for(j=0;j<125;j--);
}
void main()
{
 	int i=0;
 	while(1)
 { 
 	for(i=0;i<5;i++)
 	{
 		P3=shu_mod[i];
  		P2=led_mod[i];
  		delay(30);
 	 }
  }
}