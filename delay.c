#include<LPC21XX.H>
typedef unsigned int u32;
void delay_second(u32);
void delay_millisecond(u32);
void delay_microsecond(u32);

void delay_second(u32 sec)
{
T0PR=15000000-1;
T0TCR=0x01;
while(T0TC<sec);
T0TCR=0x03;
T0TCR=0x00;
}
void delay_millisecond(u32 sec)
{
T0PR=15000-1;
T0TCR=0x01;
while(T0TC<sec);
T0TCR=0x03;
T0TCR=0x00;
}
void delay_microsecond(u32 sec)
{
T0PR=15-1;
T0TCR=0x01;
while(T0TC<sec);
T0TCR=0x03;
T0TCR=0x00;
}
