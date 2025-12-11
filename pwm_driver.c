#include<LPC21xx.H>

void PWM_command(unsigned char s)
{	
		switch(s)
		{
		case('F'):
			PWMMR4=1750;//60% duty cycle
			PWMMR6=1750;//60% duty cycle
			PWMLER=0x00000050;//relatch the value
			break;

		case('B'):
			PWMMR4=0;//0% Duty cycle
			PWMMR6=0;//0% Duty cycle
			PWMLER=0x00000050;//relatch the value
			break;

		case('I'):
			PWMMR4=2250;//95% Duty Cycle
			PWMMR6=2250;//95% Duty cycle
			PWMLER=0x00000050;//relatch the value
			break;

		case('L'):
			PWMMR4=0;//0% Duty Cycle
			PWMMR6=1750;//60% Duty cycle
			PWMLER=0x00000050;//relatch the value
			break;

		case('R'):
			PWMMR4=1750;//60% Duty Cycle
			PWMMR6=0;//0% Duty cycle
			PWMLER=0x00000050;//relatch the value
			break;

		case('S'):
			PWMMR4=0;//0% Duty Cycle
			PWMMR6=0;//0% Duty cycle
			PWMLER=0x00000050;//relatch the value
			break;
		}	

}

