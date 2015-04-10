#include"reg51.h"
void delay(unsigned int time){
	unsigned int j=0;
	for(time=time;time>0;time--)
		for(j=0;j<125;j++);
}
void main(){
	unsigned char i;
	P0=1;
	delay(50);
	while(1){
		for(i=1;i<=7;i++){
			P0>>=1;
			delay(50);
		}
		for(i=1;i<=7;i++){
			P0<<=1;
			delay(50);
		}
	}
}