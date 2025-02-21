/* 
 * File:   matrix_keypad.h
 * Description: Header file for Matrix Keypad interfacing
 */

#ifndef MATRIX_KEYPAD_H
#define	MATRIX_KEYPAD_H

// Define the Data Direction Registers (DDR) for rows and columns
#define MATRIX_KEYPAD_COLUMN_PORT_DDR           TRISB  // Columns are connected to PORTB
#define MATRIX_KEYPAD_ROW_PORT_DDR              TRISD  // Rows are connected to PORTD

// Define Row Pins (Output pins)
#define ROW1                                    RD3
#define ROW2                                    RD2
#define ROW3                                    RD1
#define ROW4                                    RD0

// Define Column Pins (Input pins)
#define COL1                                    RB0
#define COL2                                    RB1
#define COL3                                    RB2

// Define logic levels for readability
#define HI                                      1   // High logic level
#define LOW                                     0   // Low logic level

// Define modes for reading the keypad
#define STATE                                   1   // Detects state changes (press events)
#define LEVEL                                   0   // Detects continuous key press (level-based)

// Define a special value to indicate no key is pressed
#define ALL_RELEASED                            0xFF  // No key is pressed

// Function prototypes
unsigned char read_matrix_keypad(unsigned char mode);  // Reads the pressed key based on mode
void init_matrix_keypad(void);  // Initializes the matrix keypad

#endif	/* MATRIX_KEYPAD_H */
