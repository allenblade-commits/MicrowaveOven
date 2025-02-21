/* 
 * File:   clcd.h
 * Description: Header file for interfacing a Character LCD (CLCD) 
 *              with a PIC microcontroller in 4-bit mode.
 */

#ifndef CLCD_H
#define CLCD_H

/* Define the system clock frequency for delay calculations */
#define _XTAL_FREQ                  20000000  // 20 MHz crystal frequency

/* CLCD Data and Control Port Definitions */
#define CLCD_DATA_PORT_DDR          TRISD     // Configure PORTD as data port (Direction Register)
#define CLCD_RS_DDR                 TRISE2    // Register Select (RS) pin direction
#define CLCD_EN_DDR                 TRISE1    // Enable (EN) pin direction

#define CLCD_DATA_PORT              PORTD     // Data port where LCD is connected
#define CLCD_RS                     RE2       // Register Select (RS) pin
#define CLCD_EN                     RE1       // Enable (EN) pin

/* CLCD Modes */
#define INST_MODE                   0         // Instruction mode (RS = 0)
#define DATA_MODE                   1         // Data mode (RS = 1)

/* Pin states */
#define HI                          1         // High signal
#define LOW                         0         // Low signal

/* LCD Line Addresses (For 16x2 or 20x4 Displays) */
#define LINE1(x)                    (0x80 + x)  // First line, 'x' column
#define LINE2(x)                    (0xC0 + x)  // Second line, 'x' column
#define LINE3(x)                    (0x90 + x)  // Third line (for 20x4 LCD)
#define LINE4(x)                    (0xD0 + x)  // Fourth line (for 20x4 LCD)

/* LCD Command Definitions */
#define EIGHT_BIT_MODE              0x33  // Initialize in 8-bit mode (required by LCD startup sequence)
#define FOUR_BIT_MODE               0x02  // Switch to 4-bit mode
#define TWO_LINES_5x8_4_BIT_MODE    0x28  // 2-line mode, 5x8 character font, 4-bit data length
#define CLEAR_DISP_SCREEN           0x01  // Clear the LCD display
#define DISP_ON_AND_CURSOR_OFF      0x0C  // Turn on display, but cursor off
#define BAR                         0xFF  // Full block character (for bar graphs, progress bars)

/* Function Prototypes */
void init_clcd(void);                                    // Initialize the LCD
void clcd_putch(const char data, unsigned char addr);    // Display a single character at a specified position
void clcd_print(const char *str, unsigned char addr);    // Display a string from a specified position
void clcd_write(unsigned char byte, unsigned char mode); // Write command/data to LCD

#endif	/* CLCD_H */
