/*
 * UART_C_file.c
 */
#include"UART.h"
void UART_Init() // khoi tao UART   
{  											  
	TMOD |= 0x20;//chon su dung timer1	che do 8 bit tu nap lai
	TH1 = 0xFD;	//khoi tao gia tri ban dau cho thanh ghi TH1 toc do baund 9600
	SCON = 0x50;//chon che do lam viec cua UART	 
	TR1 = 1; //khoi chay timer 1
}
void UART_TxChar(char Data)// truyen du lieu tu VDK di
{
	SBUF = Data;	 //gan du lieu vao thanh ghi SBUF
	while (TI==0);	 //cho qua trinh truyen du lieu hoan tat
	TI = 0;//xoa bit TI de tiep tuc qua trinh truyen tiep theo
}
unsigned char UART_RxChar()	// nhan du lieu ve VDK
{
	unsigned char dat;  //
	while (RI==0); //doi qua trinh nhan du lieu ket thuc
	RI = 0;		   //xoa bit RI de cho qua trinh nhan tiep theo
	dat = SBUF;	// gan cai gia tri nhan dc dang dc luu trong thanh ghi SBUF vao bien dat
	return(dat);// tra ve bien dat
}
void UART_SendString(char *str)	 //VDK truyen 1 gui 1 chuoi ky tu di
{  
     int i;
     for(i=0;str[i]!=0;i++)	//chay het chieu dai chuoi ky tu
		{
         UART_TxChar(str[i]);
    }
}