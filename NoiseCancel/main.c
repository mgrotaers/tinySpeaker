#include <avr/io.h>
#include <util/delay.h>

int main ()
{
	/*Setup Clock*/
	cli();
  CLKPR = 0x80; //B10000000;
	CLKPR = 0x00; //B00000000;

	/*Setup Inputs and Outputs*/
	DDRB = 0x10; //B00010000;

	/*DDRB &= _BV(DDB2); ADC1 Input*/
	/*DDRB |= _BV(DDB4); PB4 PWM Output*/
  /*For noise cancelling can use the following options:
      - Use DDB4 as PWM Output with speaker wired in reverse.
      - Use DDB3 as PWM Output, as OCR1B is inverted, with speaker wired normally.
      - This program is currently set up for DDB4.*/

	/*Setup PWM*/
	PLLCSR = 0x06; //B00000110; /*_BV(PCKE) | _BV(PLLE);*/
	GTCCR = 0x50; //B01010000; /*_BV(PWM1B) | _BV(COM1B0);*/
	TCCR1 = 0x01; //B00000001; /*_BV(CS10);*/

	/*Setup ADC*/
	ADMUX = 0x01; //B00000001; /*_BV(MUX0)*/
	ADCSRA = 0xe4; //B11100100; /*_BV(ADEN) | _BV(ADSC) | _BV(ADATE) | _BV(ADPS2)*/

	/*Setup initial conditions*/

	while (1)
	{
		/*Collect ADC value and convert from 1024 to 256.*/
		int16_t outSound = ADC;
		outSound = outSound/2 * 256/1024 - 2;

		/*Create sound function*/
		OCR1B = outSound;

	}
	return 0;

}
