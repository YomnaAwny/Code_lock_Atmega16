 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * 
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "../../BBigProjectMC2/MC2/common_macros.h"
#include "../../BBigProjectMC2/MC2/micro_config.h"
#include "../../BBigProjectMC2/MC2/std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/


/* LCD HW Pins */
#define RS PC0
#define RW PC1
#define E  PC2
#define LCD_CTRL_PORT PORTC
#define LCD_CTRL_PORT_DIR DDRC

#define LCD_DATA_PORT PORTA
#define LCD_DATA_PORT_DIR DDRA

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80 

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_intgerToString(int data);

#endif /* LCD_H_ */
