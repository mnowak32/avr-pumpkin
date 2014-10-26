/*
 * main.c
 *
 *  Created on: 25 paź 2014
 *      Author: Jerzyna
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 1000000UL
#define SND_DELAY 4

inline static void setValues(unsigned char i) {
	OCR0A = i;
	OCR1B = (i >> 1) | 0x80;
	_delay_ms(SND_DELAY);
}

void rampUp(unsigned char from, unsigned char to) {
	for (; from <= to; from++) {
		setValues(from);
	}
}

void rampDown(unsigned char from, unsigned char to) {
	for (; from >= to; from--) {
		setValues(from);
	}
}

int main(void) {
	DDRB =
			(1 << DDB0) | //setup PB0 (OC0A) as output
			(1 << DDB3); //setup PB3 (!OC1B) as output

	//setup timer0
	TCCR0A = (0 << COM0A1) | (1 << COM0A0) | //OC0A toggle on compare
			(0 << COM0B1) | (0 << COM0B0) | //OC0B disabled
			(1 << WGM01) | (0 << WGM00); //CTC (clear timer on compare) mode - frequency generation

	TCCR0B = (0 << FOC0A) | (0 << FOC0B) | //compatibility
			(0 << WGM02) | //CTC mode - continued
			(0 << CS02) | (1 << CS01) | (0 << CS00); //system clock, prescaler /8
//			(0 << CS02) | (1 << CS01) | (1 << CS00); //system clock, prescaler /64

	TCCR1 = (0 << CTC1) | (0 << PWM1A) | (0 << COM1A1) | (0 << COM1A0) | (0 << CS13) | (0 << CS12) | (0 << CS11) | (1 << CS10);
	GTCCR = (0 << TSM) | (1 << PWM1B) | (0 << COM1B0) | (1 << COM1B0) | (0 << FOC1A) | (0 << FOC1B) | (0 << PSR1) | (0 << PSR0);

	while (1) {
		unsigned char i;
		for (i = 80; i < 160; i+=16) {
			rampUp(i, i+32);
			rampDown(i+31, i+15);
		}
		for (i = 160; i < 224; i+=8) {
			rampUp(i, i+24);
			rampDown(i+23, i+8);
		}
		for (i = 224; i > 160; i-=8) {
			rampUp(i, i+16);
			rampDown(i+15, i-7);
		}
		for (i = 160; i < 224; i+=8) {
			rampUp(i, i+24);
			rampDown(i+23, i+8);
		}
		for (i = 224; i > 160; i-=8) {
			rampUp(i, i+16);
			rampDown(i+15, i-7);
		}
		for (i = 160; i < 224; i+=8) {
			rampUp(i, i+24);
			rampDown(i+23, i+8);
		}
		for (i = 224; i > 160; i-=8) {
			rampUp(i, i+16);
			rampDown(i+15, i-7);
		}
		for (i = 160; i > 80; i-=16) {
			rampUp(i, i+24);
			rampDown(i+23, i-15);
		}
	}

	return 0;
}
