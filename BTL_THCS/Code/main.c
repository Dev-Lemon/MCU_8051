#include <REGX52.H>	  
#include"UART.h" // thu vien UART
#include"Car.h"	//	thu vien dieu khien xe
unsigned char Data = 0;
unsigned int T, Ton, Toff;
unsigned char Ton_h_reload, Ton_l_reload, Toff_h_reload, Toff_l_reload; 
/*Cac ham bam xung*/
void PWM_Init(unsigned int ck);	/*ham khoi tao bam xung voi chu ky ck*/
void PWM_Start();/*ham khoi chay timer0*/
void PWM_Stop();/*ham dung timer0*/
void PWM_Set_Duty(unsigned char duty);/*ham set toc do quay cua dong co la duty(xung bam voi do rong)*/
int main(){
	UART_Init(); //Khoi tao UART
	PWM_Init(1085);//khoi tao che do bam xung voi chu ky 1085us(1,085ms)
	tatloa();			    
	tatdent();
	tatdens();
	while(1){
		Data = UART_RxChar();//nhan du lieu tu HC05 va gan vao bien Data
		switch (Data){//kiem tra bien Data xem no nhan dc ky tu gi va thuc hien lenh tuong ung
			case 'F':
				tien();
				break;
			case 'B':
				lui();
			   	break;
			case 'L':
				trai();
				break;
			case 'R':
			     	phai();
				break;
			case 'W':
				batdent();
				break;
			case 'w':
				tatdent();
				break;
			case 'U':
				batdens();
				break;
			case 'u':
				tatdens();
				break;
			case 'V':
				batloa();
				break;
			case 'v':
				tatloa();
				break;
			case '0':
				PWM_Set_Duty(0);
				PWM_Start();
				break;
			case '1':
				PWM_Set_Duty(10);
				PWM_Start();
				break;
			case '2':
				PWM_Set_Duty(20);
				PWM_Start();
				break;
			case '3':
				PWM_Set_Duty(30);
				PWM_Start();
				break;
			case '4':
				PWM_Set_Duty(40);
				PWM_Start();
				break;
			case '5':
				PWM_Set_Duty(50);
				PWM_Start();
				break;
			case '6':
				PWM_Set_Duty(60);
				PWM_Start();
				break;
			case '7':
				PWM_Set_Duty(70);
				PWM_Start();
				break;
			case '8':
				PWM_Set_Duty(80);
				PWM_Start();
				break;
			case '9':
				PWM_Set_Duty(90);
				PWM_Start();
				break;
			case 'q':
				PWM_Set_Duty(100);
				PWM_Start();
				break;
			case 'D':
				dung();
				PWM_Stop();
				tatdent();
				tatdens();
				break;
			case 'S':
				dung();
				break;
			case 'X':
				tien();
				break;
			case 'x':
				dung();
				break;
		}
	}
	return 0;
}
void PWM_Init(unsigned int ck){	//ham khoi tao timer 0
	speed1 = speed2 = 0;//cai dat 2 chan toc do ve muc 0	
	TMOD &= 0xF0;		// Xoa di cac bit chon mode cua Timer0
	TMOD |= 0x01;		// Timer0 hoat dong o mode 1	  
	
	ET0 = 1;			// Cho phep ngat Timer0
	EA = 1;				// Cho phep ngat toan cuc
	
	T  = ck;			 //T = chu ky
	Ton = T/2;			// Duty Cycle = 50%
	Toff = T - Ton;	   //set ban dau cho xung vuong 50%
	/*Tinh toan san cac gia tri can nap lai ban dau cho TH) vaf TL0*/
		/*2 gia tri nap TH0 TL0  neu chan speed1 va speed2 dang o muc 1*/
	Ton_h_reload = (65536-Ton)>>8;
	Ton_l_reload = (65536-Ton)&0x00FF;
		/*2 gia tri nap TH0 TL0  neu chan speed1 va speed2 dang o muc 0*/
	Toff_h_reload = (65536-Toff)>>8;
	Toff_l_reload = (65536-Toff)&0x00FF;
	
	TH0 = Ton_h_reload;	//nap gia tri cho thanh ghi TH0
	TL0 = Ton_l_reload;	// nap gia tri cho thanh ghi TL0
}
void PWM_Start(){
	TR0 = 1;			// Timer0 bat dau dem
}

void PWM_Stop(){
 	TR0 = 0;			// Timer0 ngung dem
}

void PWM_Set_Duty(unsigned char duty){
	if(duty == 0){
		speed1 = speed2 = 0; //cho chan chinh toc do ve muc 0
		ET0 = 0;//cam ngat timer
	}
	else if(duty == 100){
			speed1 = speed2 = 1; //chân chinh toc do cho = 1
			ET0 = 0; //cam ngat timer0
			}
		else{
			Ton = ((unsigned long)T)*duty/100;//tinh toan Ton
			Toff = T - Ton;//tinh toan  Toff
			/*	Tinh toan lai 2 bien nap cho TH0 va TL0 neu chan speed1 dang o muc 1*/
		   	Ton_h_reload = (65536-Ton)>>8;
			Ton_l_reload = (65536-Ton)&0x00FF;
			/*	Tinh toan lai 2 bien nap cho TH0 va TL0 neu chan speed1 dang o muc 0*/
			Toff_h_reload = (65536-Toff)>>8;
			Toff_l_reload = (65536-Toff)&0x00FF;

			ET0 = 1;
		}
}
void Timer0Overflow() interrupt 1{
	speed1 = ~speed1;
	speed2 = ~speed2;
	if(speed1==0)  // neu dang la muc 1
	{
	 	TH0 = Toff_h_reload; //nap 2 gia tri nay
		TL0 = Toff_l_reload;
	}
	else  //neu dang o muc 0 nap 2 gia tri nay
	{
	 	TH0 = Ton_h_reload;
		TL0 = Ton_l_reload;
	}
}