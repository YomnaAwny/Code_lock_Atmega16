/*
 * main.c
 *
 *  Created on: Dec 1, 2023
 *      Author: Yomna Awny
 */

#include "keypad.h"
#include "LCD.h"
#include "uart.h"


int main(void)
{
 uint8 key, count=0, j,t,flag=0;
 uint8 temp;
 uint8 passh,passl,pass[2];

 SREG |= (1<<7);

UART_init();
LCD_init();

    while(1)
    {
    	passh=UART_recieveByte();
    	    	_delay_ms(10);
    	 passl=UART_recieveByte();
    	    	_delay_ms(10);

    if(flag==0)	 {
    	LCD_clearScreen();
    	LCD_displayStringRowColumn(0,0,"1- Change Pw");
    	LCD_displayStringRowColumn(1,0, "2- Enter Pw");
    	flag=1;


    		temp=UART_recieveByte();
    	    	_delay_ms(50);
    	    temp=UART_recieveByte();
    	    	_delay_ms(50);
    	    temp=UART_recieveByte();
    	    	_delay_ms(50);

    	    	LCD_goToRowColumn(0,13);
    	    	LCD_intgerToString(temp);
    	    	LCD_goToRowColumn(0,15);
    	    	LCD_displayCharacter('C');

    }

    else{key=2;}

      key = KeyPad_getPressedKey();

if(key==1){


	LCD_clearScreen();
	LCD_displayString("New Pw:");
	LCD_goToRowColumn(0,13);
	LCD_intgerToString(temp);
	LCD_goToRowColumn(0,15);
	LCD_displayCharacter('C');
	LCD_goToRowColumn(1,0);



	for(char i =0; i<4;i++){
    		if(i==0||i==1)
    	           j=0;
    		else
    		   j=1;
    			 key = KeyPad_getPressedKey();
    			 if(i==0||i==2)
    			  pass[j]+= key*(10);
    			 else
    			 pass[j]+=key;
    			LCD_intgerToString(key);
    	_delay_ms(250);}


                passh=pass[0];
                passl=pass[1];



for(t=0;t<3;t++){

	pass[1]=0;
	pass[0]=0;

	LCD_clearScreen();
			LCD_displayString("Confirm Pw:");
			LCD_goToRowColumn(0,13);
			LCD_intgerToString(temp);
			LCD_goToRowColumn(0,15);
			LCD_displayCharacter('C');
			LCD_goToRowColumn(1,0);

for(char i =0; i<4;i++){
    	if(i==0||i==1)
    	     j=0;
    	else
    	      j=1;
      key = KeyPad_getPressedKey();
    	if(i==0||i==2)
    	      pass[j]+= key*(10);
    	 else
    	      pass[j]+=key;
    	LCD_intgerToString(key);
    	   _delay_ms(250);}

    if(pass[0]==passh&&pass[1]==passl)
          {count=4;
          t=3;}
    else
      count=1;
          }




  if(count==4){
	  UART_sendByte(4);
	    _delay_ms(10);

	UART_sendByte(pass[0]);
	_delay_ms(10);
	UART_sendByte(pass[1]);
	_delay_ms(10);

           count=0;
  LCD_clearScreen();
  LCD_displayString("1-OP/2-CL");
  LCD_goToRowColumn(0,13);
  	LCD_intgerToString(temp);
  	LCD_goToRowColumn(0,15);
  	LCD_displayCharacter('C');

  if(KeyPad_getPressedKey()==1){
  	    LCD_clearScreen();
  	    LCD_displayString("OPENED");
  	    LCD_goToRowColumn(0,13);
  	    LCD_intgerToString(temp);
  	    LCD_goToRowColumn(0,15);
  	    LCD_displayCharacter('C');
  	     UART_sendByte(2);
  	    _delay_ms(2000);
  	     }

  else if(KeyPad_getPressedKey()==2){
              LCD_clearScreen();
      	    LCD_displayString("CLOSED");
      	    LCD_goToRowColumn(0,13);
      	    LCD_intgerToString(temp);
      	    LCD_goToRowColumn(0,15);
      	    LCD_displayCharacter('C');
            UART_sendByte(3);
      	    _delay_ms(2000);}}

  else if(count!=4 && t==3){
 	         UART_sendByte(0);
 	           _delay_ms(10);
 	              count=0;
 	                t=0;
 	              LCD_clearScreen();
 	              LCD_displayString("WRONG");
 	      	    LCD_goToRowColumn(0,13);
 	      	    LCD_intgerToString(temp);
 	      	    LCD_goToRowColumn(0,15);
 	      	    LCD_displayCharacter('C');
 	      	    _delay_ms(2000);}

}

else if(key==2) {
	UART_sendByte(5);
	    _delay_ms(10);


	    for(t=0;t<3;t++){

	    	pass[1]=0;
	    	pass[0]=0;


	    LCD_clearScreen();
	    	LCD_displayString("Enter Pw:");
	    	LCD_goToRowColumn(0,13);
	    	LCD_intgerToString(temp);
	    	LCD_goToRowColumn(0,15);
	    	LCD_displayCharacter('C');
	    	LCD_goToRowColumn(1,0);

	for(char i =0; i<4;i++){
	    	if(i==0||i==1)
	    	     j=0;
	    	else
	    	      j=1;
	      key = KeyPad_getPressedKey();
	    	if(i==0||i==2)
	    	      pass[j]+= key*(10);
	    	 else
	    	      pass[j]+=key;
	    	LCD_intgerToString(key);
	    	   _delay_ms(250);}

		if(pass[0]==passh&&pass[1]==passl)
		          {count=4;
		          t=3;}
		    else
		      count=1;
		          }

	  if(count==4){
	UART_sendByte(1);
	_delay_ms(10);
	   count=0;
	    t=0;
	  LCD_clearScreen();
	  LCD_displayString("1-OP/2-CL");
	  LCD_goToRowColumn(0,13);
	  	LCD_intgerToString(temp);
	  	LCD_goToRowColumn(0,15);
	  	LCD_displayCharacter('C');
	  if(KeyPad_getPressedKey()==1){
	  	    LCD_clearScreen();
	  	    LCD_displayString("OPENED");
	  	    LCD_goToRowColumn(0,13);
	  	    LCD_intgerToString(temp);
	  	    LCD_goToRowColumn(0,15);
	  	    LCD_displayCharacter('C');
	  	UART_sendByte(2);
	  	_delay_ms(2000);}
	  else if(KeyPad_getPressedKey()==2){
	              LCD_clearScreen();
	      	    LCD_displayString("CLOSED");
	      	    LCD_goToRowColumn(0,13);
	      	    LCD_intgerToString(temp);
	      	    LCD_goToRowColumn(0,15);
	      	    LCD_displayCharacter('C');
	             UART_sendByte(3);
	      	    _delay_ms(2000);}}
	  else if(count!=4 && t==3){

	         UART_sendByte(0);
	           _delay_ms(10);
	              count=0;
	                t=0;
	              LCD_clearScreen();
	              LCD_displayString("WRONG");
	      	    LCD_goToRowColumn(0,13);
	      	    LCD_intgerToString(temp);
	      	    LCD_goToRowColumn(0,15);
	      	    LCD_displayCharacter('C');
	      	    _delay_ms(2000);}
	}

	    }


	}

