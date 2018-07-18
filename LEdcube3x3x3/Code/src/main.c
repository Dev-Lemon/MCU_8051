#include"..\inc\port.h"
#include"..\inc\delay.h"
/*khai bao dieu khien*/
#define sang 0
#define tat  1
int blink(unsigned char lan);
int sangduoilen(unsigned char lan);
int sangtrenxuong(unsigned char lan);
int sangtungcot(unsigned char lan);
int sangtungcot1(unsigned char lan);
int init();
int quaytron(unsigned char lan);
int kdh(unsigned char lan);
int bunggiuara(unsigned char lan);

int main(){
   init();	
   while(1){
   	blink(5);
	sangduoilen(5);
	sangtrenxuong(5);
	sangtungcot1(5);
	kdh(5);
	quaytron(5);
	bunggiuara(5);
   }
return 0;
}
int bunggiuara(unsigned char lan){
	 unsigned char i;
	 for(i=0;i<lan;i++){
	 	P0=P2=P1=0xFF;
		delay_ms(20);
		H1=C4=sang;delay_ms(350);
		H0=H2=C0=C2=C6=C8=sang;delay_ms(250);
		H0=H2=C0=C2=C6=C8=tat;delay_ms(250);
		H0=H2=C1=C3=C5=C7=sang;delay_ms(250);
		H0=H2=C1=C3=C5=C7=tat;delay_ms(250);
		H1=C0=C2=C6=C8=sang;delay_ms(250);
		H1=C0=C2=C6=C8=tat;delay_ms(250);
		H1=C1=C3=C5=C7=sang;delay_ms(250);
		H1=C1=C3=C5=C7=tat;delay_ms(250);
	 }
}
int quaytron(unsigned char lan){
	unsigned char i;
	for(i=0;i<lan;i++){
		P1=0x00;
		P0=P2=0xFF;delay_ms(350);
		C4=sang;
		C3=sang;delay_ms(350);
		C6=sang;C3=tat;delay_ms(350);
		C7=sang;C6=tat;delay_ms(350);
		C8=sang;C7=tat;delay_ms(350);
		C5=sang;C8=tat;delay_ms(350);
		C2=sang;C5=tat;delay_ms(350);
		C1=sang;C2=tat;delay_ms(350);
		C0=sang;C1=tat;delay_ms(350);
	/*----------------------------*/
		P0=P2=0xFF;delay_ms(350);
		C4=sang;
		C0=sang;delay_ms(350);
		C1=sang;C0=tat;delay_ms(350);
		C2=sang;C1=tat;delay_ms(350);
		C5=sang;C2=tat;delay_ms(350);
		C8=sang;C5=tat;delay_ms(350);
		C7=sang;C8=tat;delay_ms(350);
		C6=sang;C7=tat;delay_ms(350);
		C3=sang;C6=tat;delay_ms(350);			
	}
	return 0;	
}
int kdh(unsigned char lan){
	unsigned char i;
	for(i=0;i<lan;i++){
		P1=0x00;
		P0=P2=0xFF;delay_ms(350);
		C4=sang;delay_ms(350);
		C3=sang;delay_ms(350);
		C6=sang;delay_ms(350);
		C7=sang;delay_ms(350);
		C8=sang;delay_ms(350);
		C5=sang;delay_ms(350);
		C2=sang;delay_ms(350);
		C1=sang;delay_ms(350);
		C0=sang;delay_ms(350);
	/*----------------------------*/
		P0=P2=0xFF;delay_ms(350);
		C0=sang;delay_ms(350);
		C1=sang;delay_ms(350);
		C2=sang;delay_ms(350);
		C5=sang;delay_ms(350);
		C8=sang;delay_ms(350);
		C7=sang;delay_ms(350);
		C6=sang;delay_ms(350);
		C3=sang;delay_ms(350);
		C4=sang;delay_ms(350);			
	}
	return 0;
}
int sangtungcot1(unsigned char lan){
	unsigned char i;
	for(i=0;i<lan;i++){
		P1=0x00;
		P0=P2=0xFF;
		C0=sang;delay_ms(900);
		C1=sang;delay_ms(800);
		C2=sang;delay_ms(700);
		C5=sang;delay_ms(600);
		C8=sang;delay_ms(500);
		C7=sang;delay_ms(400);
		C6=sang;delay_ms(300);
		C3=sang;delay_ms(200);
		C4=sang;delay_ms(900);
	}
	return 0;
}
int sangtungcot(unsigned char lan){
	unsigned char i;
	for(i=0;i<lan;i++){
		P1=0x00;
		P0=P2=0xFF;
		C0=sang;delay_ms(350);
		C1=sang;delay_ms(350);
		C2=sang;delay_ms(350);
		C3=sang;delay_ms(350);
		C4=sang;delay_ms(350);
		C5=sang;delay_ms(350);
		C6=sang;delay_ms(350);
		C7=sang;delay_ms(350);
		C8=sang;delay_ms(350);
	}
}
int init(){
	P0=P2=P1=0xFF;
}
int sangduoilen(unsigned char lan){
	unsigned char i;
	for(i=0;i<lan;i++){
		P0=P2=0x00;
		P1=0xFF;
		H0 = sang;
		delay_ms(350);
		H1 = sang;
		delay_ms(350);
		H2 = sang;
		delay_ms(350);
	}	
}
int sangtrenxuong(unsigned char lan){
	unsigned char i;
	for(i=0;i<lan;i++){
		P0=P2=0x00;
		P1=0xFF;
		H2 = sang;
		delay_ms(350);
		H1 = sang;
		delay_ms(350);
		H0 = sang;
		delay_ms(350);
	}	
}
int blink(unsigned char lan){
	unsigned char i;
	P0=P2=0x00;
	for(i=0;i<lan;i++){
		P1=0x00;
		delay_ms(20);
		P1=0xFF;
		delay_ms(20);
	}
	return 0;
}