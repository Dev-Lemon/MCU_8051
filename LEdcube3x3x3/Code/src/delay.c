#include"..\inc\delay.h"
/*------------------------*/
int delay(int t){
	while(t--);
	return 0;
}
/*------------------------*/
int delay_ms(int t){
	unsigned int i,j;
	for(i=0;i<t;i++){
		for(j=0;j<125;j++);
	}	
	return 0;
}
/*------------------------*/
int delay_s(int t){
	delay_ms(t*1000);
	return 0;
}