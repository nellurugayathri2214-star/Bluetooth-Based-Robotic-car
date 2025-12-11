#include"lcdheader.h"
#include"delay.c"

void LCD_init(void)
{
	IODIR0|=LCD_D|RS|E;//p0.2 to p0.7 as output pin
	LCD_command(0x01);//clear lcd command
	LCD_command(0x02);//return to home space
	LCD_command(0x0c);//display on
	LCD_command(0x28);//4 bit interfacing wid 2 lines
	LCD_command(0x80);
}

void LCD_command(unsigned char cmd)
{
	IOCLR0=LCD_D;//clear p0.4 to p0.7
	IOSET0=(cmd&0xf0);//passing command in 4 bits	
	IOCLR0=RS;//enable command register
	IOSET0=E;//latch the data
	delay_millisecond(2);//2 ms delay
	IOCLR0=E;//to relatch the nxt cycle

	IOCLR0=LCD_D;//clear p0.4 to p0.7
	IOSET0=(cmd&0x0f)<<4;//passing command in 8 bits
	IOCLR0=RS;//enable command register
	IOSET0=E;//latch the data
	delay_millisecond(2);//2 ms delay
	IOCLR0=E;//to relatch the nxt cycle
}


void LCD_str(char*s)
{  
while(*s)
	LCD_data(*s++);
}  

void LCD_data(unsigned char d)
{
	IOCLR0=LCD_D;//clear p0.4 to p0.7
	IOSET0=(d&0xf0);//passing data in 4 bits
	IOSET0=RS;//enable data register
	IOSET0=E;//latch the data on the data bits
	delay_millisecond(2);//2 ms delay
	IOCLR0=E;//to relatch the nxt cycle

	IOCLR0=LCD_D;//clear p0.4 to p0.7
	IOSET0=(d&0x0f)<<4;//passing data in 4 bits 
	IOSET0=RS;//enable data register
	IOSET0=E;//latch the data on the data bits
	delay_millisecond(2);//2 ms delay
	IOCLR0=E;//to relatch the nxt cycle

}
