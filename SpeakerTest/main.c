#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

const float PI=3.141593;
const int delayTime = 1000;

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

	/*Setup PWM*/
	PLLCSR = 0x06; //B00000110; /*_BV(PCKE) | _BV(PLLE);*/
	GTCCR = 0x50; //B01010000; /*_BV(PWM1B) | _BV(COM1B0);*/
	TCCR1 = 0x01; //B00000001; /*_BV(CS10);*/

	/*Setup ADC*/
	ADMUX = 0x01; //B00000001; /*_BV(MUX0)*/
	ADCSRA = 0xe4; //B11100100; /*_BV(ADEN) | _BV(ADSC) | _BV(ADATE) | _BV(ADPS2)*/

	/*Setup initial conditions*/
	int fTick = 0;
	int f = 440;
	int t = 0;

	while (1)
	{
		/*Collect ADC value and convert from 1024 to 256.*/
		int16_t a = ADC;
		a = a/2 * 256/1024 - 2;

		/*Create sound function*/
		//get frequency
		if (t > delayTime){
			switch (fTick){
				case 0:
					f = 440;
					fTick++;
					break;
				case 1:
					f = 880;
					fTick++;
					break;
				case 2:
					f = 1760;
					fTick = 0;
					break;
			}
			t=0;
		}

		//get new time
		int16_t outVal = (int16_t)(a*sin(2*PI*f*t/1000) + 127);

		OCR1B = outVal;

		t++;
		_delay_ms(1);

	}
	return 0;

}
