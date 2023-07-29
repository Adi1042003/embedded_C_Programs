//1.  a program to generate 50 % duty cycle , 1 KHz , wave and use it to run the buzzer.

#include"lpc214x.h"

void PLL_init(void);
void PWM_init(void);

int main()
{
	PLL_init();
	PWM_init();
	IO0DIR=0x00;
	while(1)
	{
			PWMMR5=30000; //connect Buzzer to P0.21
			PWMLER=(1<<5);	
	}

}

void PLL_init()
{
	PLL0CON=0x01;
	PLL0CFG=0x24;
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	while((PLL0STAT & (1<<10))==0);
	PLL0CON=0x03;
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	VPBDIV=0x01;
}
void PWM_init()
{
	  PINSEL1=0x0400;
	  PWMMR0=60000;
	  PWMTCR=0x09;
	  PWMMCR=0x02;
	  PWMPR=0;
	  PWMPCR=(1<<13);
}
