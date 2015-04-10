#include<reg51.h>
#define unchar unsigned char  
unchar DispTab[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unchar i;
unchar count;
void timer0 (void) interrupt 1
{  
   
   TH0=-50000/256;
   TL0=-50000%256;
   i++;
   if (i==20)
   {
   i=0;  count++;
   }
   if (count==60) count=0;
   P0=DispTab[count/10];
   P2=DispTab[count%10];

   }
   
void main ( )
{
   TMOD=0x01;
   TH0=-50000/256;
   TL0=-50000%256;
   P0=DispTab[count/10];
   P2=DispTab[count%10];
   EA=1;
   ET0=1;
   TR0=1;
   do{}while(1);
 }
