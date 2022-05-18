#include <avr/io.h>
#include <util/delay.h>

static void clock_setup(void)
{
	CLKPR = 0x10000000;
	CLKPR = 0x00000000;
}

main (void)
{
	/*Setup Clock*/
	cli;
	clock_setup();
  
	/*Setup Inputs and Outputs*/
	DDRB &= _BV(DDB2); /*ADC1 Input*/
	DDRB |= _BV(DDB4); /*PB4 PWM Output*/
  
	/*Setup PWM*/
	PLLCSR = _BV(PCKE) | _BV(PLLE);
	GTCCR = _BV(PWM1B) | _BV(COM1B0);
	TCCR1 = _BV(CS10);
	
	
	
	while (1)
	{
	}
}
