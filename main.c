#include <avr/io.h>
#include <util/delay.h>

static void clock_setup(void)
{
	CLKPR = 0x10000000;
	CLKPR = 0x00000000;
}

#define const float PI=3.141593

main (void)
{
	/*Setup Clock*/
	cli;
	clock_setup();
  
	/*Setup Inputs and Outputs*/
	DDRB = 0x00010000;
	/*
	DDRB &= _BV(DDB2); /*ADC1 Input
	DDRB |= _BV(DDB4); /*PB4 PWM Output*/
  
	/*Setup PWM*/
	PLLCSR = 0x00000110; /*_BV(PCKE) | _BV(PLLE);*/
	GTCCR = 0x01010000; /*_BV(PWM1B) | _BV(COM1B0);*/
	TCCR1 = 0x00000001; /*_BV(CS10);*/
	
	/*Setup ADC*/
	ADMUX = 0x00000001; /*_BV(MUX0)*/
	ADCSRA = 0x11100100; /*_BV(ADEN) | _BV(ADSC) | _BV(ADATE) | _BV(ADPS2)*/
	
	while (1)
	{
		/*Collect ADC value and convert from 1024 to 256.*/
		int16_t a = ADC;
		a = a * 256/1024;
		
		/*Create sound function*/
		//get frequency
		
		//get new time
		int16_t outVal = a*sin(2*PI*f*t)
	}
}
