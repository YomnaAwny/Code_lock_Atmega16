# Code Locker using Atmega16

This repository contains a code locker project developed as part of an embedded systems course, using two Atmega16 microcontrollers.

## Technologies Used
### Hardware
- Microcontrollers: 2 x Atmega16
- Devices: LCD, Keypad, Green LED, Red LED
- Actuators: DC Motor

### Software
- Development Environment: Eclipse
- Programming Language: C
- Simulation Program: Proteus

## How It Works
  In the very beginning, the user is given an option to enter a new code or the previous code. I programmed the second Atmega16 to fetch the six-digit code from the EEPROM. It sends it to the first Atmega16 to compare it with the code the user enters on the Keypad, which is shown on the LCD. 

  If the user enters the code correctly, the first MC will send a signal to the second MC, making the green LED glow and showing the user the option between open or close on the LCD. If the user chooses open, the first MC would send a signal to the second MC that will make the motor turn in the direction of opening and vice versa with close.

  If the user enters the password wrong 3 times, the first MC will be shown "wrong" and send a signal to the second MC making the red LED turn on and activating the buzzer.
