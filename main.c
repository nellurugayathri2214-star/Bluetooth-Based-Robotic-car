/*bluetooth based robotic car*/
#include<LPC21XX.H>
#include"uart0header.h"
#include"lcdheader.h"


#define M1IN2 1<<16
#define	M2IN2 1<<17
#define led 1<<18
#define buz 1<<19

int main()
{
unsigned char command;

/*Config GPIO*/
IODIR1|=M1IN2|M2IN2|led|(buz);//p1.16 to p1.21 as O/P pins

/*Project Title*/
LCD_init();
LCD_title();
delay_millisecond(1000);


/*Bluetooth Commands*/
UART0_config();

/*PWM config*/
PINSEL0|=0x000A0000;//p0.8 & p0.9 as PWM4 & PWM6

PWMMR0=2500-1;//set count for period register 
PWMMR4=0;//set duty cycle for PWM4
PWMMR6=0;//set duty cycle for PWM6
PWMMCR=0x00000003;//PWMTC=0;if TC count reaches period value
PWMPCR=0x00005000;//O/P PWM 4 & 6 Enabled
PWMTCR=0x00000009;//counter and PWM mode Enabled
PWMLER=0x00000050;//latch the duty cycle value for PWM 4 & 6

	/*********************/


while(1)
{
	IOSET1|=buz;
	command=UART0_RX();
	switch(command)
	{
		case ('f'):
					PWM_command('F');
					IOCLR1=M1IN2|M2IN2;
					LCD_command(0x01);//clearing LCD display
					LCD_command(0x80);
					LCD_str("F->Forward");
					UART0_TXstr("Moving Forward\n");
					break;
		case ('i'):
					PWM_command('I');
					IOCLR1=M1IN2|M2IN2;
					LCD_command(0x01);//clearing LCD display
					LCD_command(0x80);
					LCD_str("I->speed>>");
					UART0_TXstr("Forward Speed Increased\n");
					break;

		case ('b'):
					PWM_command('B');
					IOSET1=M1IN2|M2IN2;
					LCD_command(0x01);//clearing LCD display
					LCD_command(0x80);
					LCD_str("B->Backward");
					UART0_TXstr("Moving Backward\n");
					break;

		case ('l'):
					PWM_command('L');
					IOCLR1=M2IN2;
					IOSET1=M1IN2;
					LCD_command(0x01);//clearing LCD display
					LCD_command(0x80);
					LCD_str("L->Turning Left");
					UART0_TXstr("Turning Left\n");
					break;

		case ('r'):
					PWM_command('R');
					IOCLR1=M1IN2;
					IOSET1=M2IN2;
					LCD_command(0x01);//clearing LCD display
					LCD_command(0x80);
					LCD_str("R->Turning Right");
					UART0_TXstr("Turning Right\n");
					break;

		case ('s'):
					PWM_command('S');
					IOCLR1=M1IN2|M2IN2;
					LCD_command(0x01);//clearing LCD display
					LCD_command(0x80);
					LCD_str("S->Stop");
					UART0_TXstr("Stop\n");
					break;

		case ('u'):
					IOCLR1=(led);//on the led
					LCD_command(0xc0);
					LCD_str("U->Light On");
					UART0_TXstr("Light On\n");
					break;

		case ('v'):
					IOSET1=(led);//off the led
					LCD_command(0x01);//clearing LCD display
					UART0_TXstr("Light Off\n");
					break;

		case ('W'):
					IOCLR1=(buz);//on the buzzer
					LCD_command(0xc0);
					LCD_str("->Sound Horn");
					UART0_TXstr("Horn On\n");
					break;

		case ('w'):
					IOSET1=(buz);//OFF the buzzer
					LCD_command(0x01);
					UART0_TXstr("Horn Off\n");
					break;
		}//end of switch
	}//end of while
}//end of main
