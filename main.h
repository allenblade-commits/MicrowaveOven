/* 
 * File:   main.h
 * Author: Allen
 *
 * Created on 6 October, 2023, 7:31 PM
 *
 * Description: Header file for the microwave oven control system.
 *              It includes function declarations, macros, and required
 *              header files.
 */

#ifndef MAIN_H
#define MAIN_H

#include <xc.h>  // Include standard header for PIC microcontrollers
#include "clcd.h"  // Include header for character LCD module
#include "matrix_keypad.h"  // Include header for matrix keypad
#include "timers.h"  // Include header for timer functions

// State definitions for operation modes
#define POWER_ON_SCREEN                0x01  // Power-on screen state
#define MENU_DISPLAY_SCREEN            0x02  // Menu display screen state
#define MICRO_MODE                     0x03  // Microwave mode
#define GRILL_MODE                     0x04  // Grill mode
#define CONVECTION_MODE                0x05  // Convection mode
#define START_MODE                     0x06  // Start mode
#define TIME_DISPLAY                   0x07  // Displaying time
#define START                          0x08  // Start operation
#define PAUSE                          0x09  // Pause operation
#define STOP                           0x0A  // Stop operation

// Reset flags for different operations
#define RESET_NOTHING                  0x0F  // No reset required
#define MODE_RESET                     0x10  // Reset mode settings
#define RESET_TEMP                     0x11  // Reset temperature settings

// Pin definitions for peripheral control
#define FAN                            RC2   // Fan control pin
#define FAN_DDR                        TRISC2  // Fan pin direction register
#define BUZZER                         RC1   // Buzzer control pin
#define BUZZER_DDR                     TRISC1  // Buzzer pin direction register
#define DOOR                           RB3   // Door sensor pin
#define DOOR_DDR                       TRISB3  // Door sensor pin direction register

// Constants for ON/OFF states
#define ON                             1  // Device ON state
#define OFF                            0  // Device OFF state

// Function declarations
void power_on_screen(void);  // Display power-on screen
void menu_display_screen(void);  // Display main menu options
void clear_screen(void);  // Clear CLCD screen
void set_time(unsigned char key, int reset_flag);  // Set cooking time
void time_display_screen(void);  // Display remaining time and options
void set_temp(unsigned char key, int reset_flag);  // Set cooking temperature

#endif /* MAIN_H */
