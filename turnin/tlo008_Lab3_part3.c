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
    DDRC = 0xFF; PORTC = 0x00;    
    unsigned char fuelLevel = 0x00; 
    unsigned char setDriver = 0x00;
  
    /* Insert your solution below */
    while (1) {
	fuelLevel = (PINA&0x0f);
	setDriver = (PINA>>4);
        if(fuelLevel<=0x02){
	  if(setDriver==0x03){
	     PORTC = 0xE0;
	  }else{
	     PORTC = 0x60;}
	}else if(fuelLevel<=0x04){
	  if(setDriver==0x03){     
             PORTC = 0xF0;
	  }else{
 	     PORTC = 0x70;}
	}else if(fuelLevel<=0x06){
	   if(setDriver==0x03){
	     PORTC = 0xB8;
	  }else{
	     PORTC = 0x38;}
	}else if(fuelLevel<=0x09){
	  if(setDriver==0x03){
	     PORTC = 0xBC;
	   }else{
	     PORTC = 0x3C;}
	}else if(fuelLevel<=0x0C){
	   if(setDriver==0x03){
	     PORTC = 0xBE;
	   }else{
	     PORTC = 0x3E;}
	}else{
	   if(setDriver==0x03){
	     PORTC = 0xBF;
	   }else{
	     PORTC = 0x3F;}
	}
    }
   return 1;
}
