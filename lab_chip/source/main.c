/*	Author: magui051
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;	//configure port A as input, initialize to 11111111 
	DDRB = 0xFF;	PORTB = 0x00; //Configure port B's to 8 pins as outputs, initialize to 00000000
	
	unsigned char led = 0x00;
	unsigned char button = 0x00;
	
	
	
    /* Insert your solution below */
    while (1) {
	//PORTB = 0x0F; //Writes port B's 8 pins with 00001111
	   button = ~PINA & 0x01;
	if (button) {
		led = (led & 0xFC) | 0x01;
	}
	else {
		led = (led & 0xFC) | 0x02;
	}
	PORTB = led;    
    }
}
