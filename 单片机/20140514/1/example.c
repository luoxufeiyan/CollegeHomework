#include<reg51.h> 
sbit D1=P0^4; 
unsigned char num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71}; 
unsigned char i;  
fanzhuan () interrupt 0  
{
	D1=!D1; 
} 
jishu () interrupt 2
{
	i++;  
	P2=num[i];
		  if (i==15)
		 {
		 	 i=0;
		 }
} 
void main ()
{
	  P2=0x00;
	  D1=0;
	  EA=1; //ʹ��Ƭ�������ж�
	  IT0=1;//�����ⲿ�ж�0Ϊ�ߵ�ƽ����
	  EX0=1;
	  IT1=1;//�����ⲿ�ж�1Ϊ�ߵ�ƽ����
	  EX1=1;
	  while (1);
}