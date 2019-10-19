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
    DDRA = 0x00; PORTA = 0xFF; //input 
    //DDRB = 0x00; PORTB = 0xFF; //input
    DDRC = 0xFF; PORTC = 0x00; //output

    unsigned char input = 0x00;
    unsigned char led = 0x00;

    while(1) {
      input = PINA;

      if(input == 0x01 || input == 0x02) {
        led = 0x60;
      }
      else if(input == 0x03 || input == 0x04) {
        led = 0x70;
      }
      else if(input == 0x05 || input == 0x06) {
        led = 0x38;
      }
      else if(input == 0x07 || input == 0x08 || input == 0x09) {
        led = 0x3C;
      }
      else if(input == 0x0A || input == 0x0B || input == 0x0C) {
        led = 0x3E;
      }
      else if(input == 0x0D || input == 0x0E || input == 0x0F) {
        led = 0x3F;
      }
      PORTC = led;
    }
    return 1;
 }

