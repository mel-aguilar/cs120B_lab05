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


int main (void) {

  DDRA = 0x00; PORTA = 0xFF;
  DDRC = 0xFF; PORTC = 0x00;

  enum states {INIT, WAIT, INCREMENT, DECREMENT, RESET, DEPRESS, DEPRESS2} state;
	state = INIT;
	unsigned char begin = 0x00;
	begin = 7;
	unsigned char A0 = 0x00;
	unsigned char A1 = 0x00;
  
  while (1) {
		A0 = ~PINA & 0x01;
		A1 = ~PINA & 0x02;
		switch(state){
			case INIT:
			state = WAIT;
			break;
			case WAIT:
			if(A1 && A0){
				state = RESET;
			}
			else if(A1){
				state = DEPRESS2;
			}
			else if(A0){
				state = DEPRESS;
			}
			else{
				state = WAIT;
			}
			break;
			case INCREMENT:
			state = WAIT;
			break;
			case DEPRESS:
			if(A1){
				state = RESET;
			}
			else if (!A0) {
				state = INCREMENT;
			}
			else {
				state = DEPRESS;
			}
			break;
			case DECREMENT:
			state = WAIT;
			break;
			case DEPRESS2:
			if(A0){
				state = RESET;
			}
			else if (!A1) {
				state = DECREMENT;
			}
			else {
				state = DEPRESS2;
			}
			break;
			case RESET:
			if((!A0) && (!A1)){
				state = WAIT;
			}
			else{
				state = RESET;
			}
			break;
		}
		switch(state){
			case INIT:
			begin = 7;
			break;
			case WAIT:
			break;
			case DEPRESS:
			break;
			case RESET:
			begin = 0;
			break;
			case DEPRESS2:
			break;
			case INCREMENT:
			if(begin < 9){
				begin += 1;
			}
			break;
			case DECREMENT:
			if(begin > 0){
				begin -= 1;
			}
			break;
		}
		PORTC = begin;
	}
	return 1;
}
