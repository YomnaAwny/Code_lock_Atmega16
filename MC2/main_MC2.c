/*
 * main.c
 *
 *  Created on: Dec 5, 2023
 *      Author: Yomna Awny
 */

#include "uart.h"
#include "adc.h"
#include "external_eeprom.h"
#include "micro_config.h"

#define Buzzer PD5
#define Green PD4
#define Red PD3
#define MTIN1 PD6
#define MTIN2 PD7



int main(void){
char comm;
char passw,passw2;
uint32 temp;

DDRD=0xFF;
PORTD=0;

UART_init();
ADC_init();
EEPROM_init();

EEPROM_writeByte(0x0311, 12);
_delay_ms(10);
EEPROM_writeByte(0x0322, 34);
_delay_ms(10);
EEPROM_readByte(0x0311, &passw);
_delay_ms(10);
EEPROM_readByte(0x0322, &passw2);
_delay_ms(10);

SREG |= (1<<7);


while(1){

	Over:

	 UART_sendByte(passw);
		_delay_ms(10);
		UART_sendByte(passw2);
		_delay_ms(10);

      for(char i=0;i<=8;i++){
	temp= ADC_readChannel(0);
	temp = ((uint32)g_adcResult*150*5)/(1023*1.5);
	UART_sendByte(temp);
	  _delay_ms(50);}

    comm=UART_recieveByte();
       _delay_ms(10);

if(comm==5){

 comm=UART_recieveByte();
_delay_ms(10);

 if(comm==1){
 	PORTD|=(1<<Green);
 	comm=UART_recieveByte();
          _delay_ms(10);
 	if(comm==2){
 		PORTD|=(1<<MTIN1);
 		_delay_ms(2000);
 		PORTD&=~(1<<MTIN1)&~(1<<Green);
 	}
 	else if(comm==3){
 		PORTD|=(1<<MTIN2);
 		_delay_ms(2000);
 		PORTD&=~(1<<MTIN2)&~(1<<Green);
 	}}

     else if(comm==0){
    	 PORTD|=(1<<Red)|(1<<Buzzer);
    	 	_delay_ms(2000);
    	 	PORTD&=~(1<<Red)&~(1<<Buzzer);}
}



else if(comm==4)
{


	passw=UART_recieveByte();
		    	_delay_ms(10);
	passw2=UART_recieveByte();
		    	_delay_ms(10);

	EEPROM_writeByte(0x0400, passw);
		_delay_ms(10);
	EEPROM_writeByte(0x0410, passw2);
		_delay_ms(10);

	PORTD|=(1<<Green);
	comm=UART_recieveByte();
         _delay_ms(10);
	if(comm==2){
		PORTD|=(1<<MTIN1);
		_delay_ms(2000);
		PORTD&=~(1<<MTIN1)&~(1<<Green);
	}
	else if(comm==3){
		PORTD|=(1<<MTIN2);
		_delay_ms(2000);
		PORTD&=~(1<<MTIN2)&~(1<<Green);
	}}

    else if(comm==0){
   	 PORTD|=(1<<Red)|(1<<Buzzer);
   	 	_delay_ms(2000);
   	 	PORTD&=~(1<<Red)&~(1<<Buzzer);}

}
}
