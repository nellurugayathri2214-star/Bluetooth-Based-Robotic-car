#include<LPC21xx.H>
#include<stdio.h>
#include"uart0header.h"
void UART0_config()
{
	PINSEL0|=0X05;//config p0.1 & p0.2 as TXD & RXD
	U0LCR=0x83;//enable DLAB and config 8N1 frame format
	U0DLL=97;//config the baud rate as 9600
	U0DLM=0;
	U0LCR=0x03;//DLAB disabled
}

void UART0_TX(unsigned char txBytes)
{
	while(((U0LSR>>5)&1)==0);
	U0THR=txBytes;
}

unsigned char UART0_RX()
{
	while(((U0LSR>>0)&1)==0);
	return U0RBR;
}

void UART0_TXstr(unsigned char *s)
{
	while(*s)
		UART0_TX(*s++);
}

void UART0_RXstr(unsigned char*s,int len)
{
	int i=0;
	unsigned char c;
	while(1)
	{	
		while((U0LSR&1)==0);
			c=U0RBR;
			if((c=='\n')||(c<=len-1))
				break;
			s[i++]=c;
	}
	s[i]='\0';	
}

void integer(int n)
{
	char array[10];
	sprintf(array,"%d",n);
	UART0_TXstr(array);
}

void flaotnumber(float f)
{
	char array[10];
	sprintf(array,"%.2f",f);
	UART0_TXstr(array);
}

void LCD_title(void)
{
	LCD_command(0x80);
	LCD_str("*Bluetooth Based");
	LCD_command(0xC0);
	LCD_str("Robotic Car*");
}




