#include <REG51.H>
unsigned char code table1[]={0x06,0x5b,0x4f,0x66,0x6d};
unsigned char code table2[]={0x78,0x79,0x38,0x38,0x3f};
unsigned char i;
unsigned char a,b;
unsigned char temp;
void main(void)
{
  while(1)
    {
      temp=0xfe;
      for(i=0;i<5;i++)
        {
          if(P1_7==1)
            {
              P0=table1[i];
            }
            else
              {
                P0=table2[i];
              }
          P2=temp;
          a=temp<<(i+1);
          b=temp>>(7-i);
          temp=a|b;
　　　　　for(a=4;a>0;a--)
          for(b=248;b>0;b--);
        }
    }
}