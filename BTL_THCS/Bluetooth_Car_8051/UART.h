/* Thu Vien UART
Author: Pham Duc Khanh
DateTime: 27/05/2018
*/
#ifndef __UART_H__
#define __UART_H __

#include <REGX52.H>

void UART_Init(); //Ham khoi tao UART
void UART_TxChar(char);// Ham Truyen 1 byte tu VDK di den HC05
unsigned char UART_RxChar();//Ham giup VDK nhan 1 byte tu HC05
void UART_SendString(char *);//Ham VDK gui 1 chuoi ky tu cho HC05

#endif
