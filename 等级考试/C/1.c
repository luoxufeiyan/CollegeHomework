#include<stdio.h>
void main() 
{ 
    int i,b=1; 
    double s; 
    s=0;  
    for(i=1;i<=20;i++)
    { 
        if(i%2)  
        s=s+ ((double)i/(double)b) ; 
        else 
        s=s- ((double)i/(double)b) ; 
        b+=2;
    } 
    printf("sum=%lf\n",s); 
}

