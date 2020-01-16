/*	Author: Macbook
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
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0X00;
    DDRC = 0xFF; PORTC = 0x00;    
    unsigned char upB = 0x00; 
    unsigned char lowC = 0x00;
  
    /* Insert your solution below */
    while (1) {
	upB = (PINA&0xF0)>>4;
	lowC = (PINA&0x0F)<<4;
	PORTB = upB;
	PORTC = lowC;
    }
   return 1;
}
