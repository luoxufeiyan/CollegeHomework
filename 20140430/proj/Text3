#include <reg51.h>
          void delay(unsigned char i)
          {  unsigned char j;
  	         while(i--)	
                for(j=0;j<200;j++);
          }
          void main() 
          {  unsigned char i;  
             for(i=0;i<3;i++)  	 
               {	  P2=0x00;	  
                  delay(200);	  
	              P2=~P2;	  
	              delay(200);	  
	           }   
             while(1) 
               P2=P1;
          }