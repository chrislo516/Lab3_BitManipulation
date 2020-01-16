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
    DDRD = 0x00; PORTD = 0xFF;
    DDRB = 0xFE; PORTB = 0X01;	// Last bit is an input
    
    unsigned short sensor = 0x0000; 
    unsigned char tmp = 0x00;
    unsigned char op = 0x00;
  
    /* Insert your solution below */
    while (1) {
     sensor = (PIND<<1);
     tmp = PINB & 0x01;
     sensor = sensor|tmp;
     if(sensor >= 0x0046){  // 0x0046 = 70
	op = 0x02;
     }else if(((sensor > 0x0005)&&(sensor<0x0046))){
	op = 0x04;
     }else{
	op = 0x00;
     }
    PORTB = op;
   }
   return 1;
}
