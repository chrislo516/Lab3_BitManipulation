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
    DDRB = 0x00; PORTB = 0xFF;     
    DDRC = 0xFF; PORTC = 0x00;    
    unsigned char oneCnt = 0x00; 
    unsigned char oneCnt1 = 0x00; 
    unsigned char temp_input = 0x00;
    unsigned char numA = 0x00;
    unsigned char numB = 0x00;
    unsigned char iter;
    /* Insert your solution below */
    while (1) {
	numA = PINA;
	numB = PINB;
	oneCnt = 0x00;
	oneCnt1 = 0x00;
	temp_input = 0x00;
	if(numA&0x01){
	   oneCnt = oneCnt + 0x01;}
	for(iter = 0x01 ; iter < 0x08 ; iter = iter + 0x01){
	  temp_input = ((numA>>iter)&(0x01));
	  if(temp_input == 0x01){
	    oneCnt = oneCnt + 0x01;
	  }
	}
	temp_input = 0x00;
	if(numB&0x01){
	  oneCnt1 = oneCnt1 + 0x01;}
	for(iter = 0x01 ; iter < 0x08 ; iter = iter + 0x01){
          temp_input =((numB>>iter)&(0x01));
          if(temp_input==0x01){
            oneCnt1 = oneCnt1 + 0x01;
          }
        }
      PORTC = oneCnt+oneCnt1;
    }
   return 1;
}
