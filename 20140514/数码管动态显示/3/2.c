#include<reg51.h>
char led_mod[]={0x76,0x79,0x38,0x38};
char fact[]={0x0e,0x0d,0x0b,0x07};
void delay(unsigned int i)
{unsigned int j=0;
 for(;i>0;i--)
 for(j=0;j<125;j--);
 }
 void main()
 {int i=0;
 while(1)
 { for(i=0;i<4;i++)
 {P3=fact[i];
  P2=led_mod[i];
  delay(30);
  }}
  }