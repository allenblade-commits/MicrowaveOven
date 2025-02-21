#include <xc.h>  // Include header for PIC microcontroller
#include "clcd.h" // Include the CLCD library

/* 
 * Function to write a byte (command or data) to the LCD 
 * Parameters:
 * - byte: Data/command to send
 * - mode: 1 for Data Mode, 0 for Instruction Mode
 */
void clcd_write(unsigned char byte, unsigned char mode) 
{
    CLCD_RS = (__bit)mode; // Set RS (Register Select): 0 for command, 1 for data

    // Send the higher nibble (upper 4 bits)
    CLCD_DATA_PORT = byte & 0xF0; // Mask lower 4 bits, keep upper 4 bits
    CLCD_EN = HI;  // Enable pulse HIGH
    __delay_us(100); // Short delay for LCD to latch data
    CLCD_EN = LOW; // Enable pulse LOW

    // Send the lower nibble (lower 4 bits)
    CLCD_DATA_PORT = (unsigned char)((byte & 0x0F) << 4); // Shift lower 4 bits to upper position
    CLCD_EN = HI;  // Enable pulse HIGH
    __delay_us(100); // Short delay
    CLCD_EN = LOW; // Enable pulse LOW

    __delay_us(4100); // Delay for LCD to process the command (4.1ms)
}

/* 
 * Function to initialize the CLCD controller 
 */
static void init_display_controller(void)
{
    __delay_ms(30); // Wait for LCD startup time

    // Send initialization sequence in 8-bit mode
    clcd_write(EIGHT_BIT_MODE, INST_MODE);
    __delay_us(4100);
    clcd_write(EIGHT_BIT_MODE, INST_MODE);
    __delay_us(100);
    clcd_write(EIGHT_BIT_MODE, INST_MODE);
    __delay_us(1); 

    // Set LCD to 4-bit mode
    clcd_write(FOUR_BIT_MODE, INST_MODE);
    __delay_us(100);
    
    // Set display mode: 2-line, 5x8 character size
    clcd_write(TWO_LINES_5x8_4_BIT_MODE, INST_MODE);
    __delay_us(100);
    
    // Clear display screen
    clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
    __delay_us(500);
    
    // Display ON, cursor OFF
    clcd_write(DISP_ON_AND_CURSOR_OFF, INST_MODE);
    __delay_us(100);
}

/* 
 * Function to initialize CLCD module 
 */
void init_clcd(void)
{
    /* Set CLCD Data Port as output */
    CLCD_DATA_PORT_DDR = 0x00; // Configure all data port pins as output

    /* Set RS and EN lines as output */
    CLCD_RS_DDR = 0; 
    CLCD_EN_DDR = 0;
    
    init_display_controller(); // Call function to initialize LCD controller
}

/* 
 * Function to write a character to a specific location on LCD
 * Parameters:
 * - data: Character to display
 * - addr: Address on LCD (position)
 */
void clcd_putch(const char data, unsigned char addr)
{
    clcd_write(addr, INST_MODE); // Move cursor to desired position
    clcd_write(data, DATA_MODE); // Write character at that position
}

/* 
 * Function to print a string to LCD from a specific position
 * Parameters:
 * - str: Pointer to string to display
 * - addr: Address on LCD (starting position)
 */
void clcd_print(const char *str, unsigned char addr)
{
    clcd_write(addr, INST_MODE); // Move cursor to desired position

    while (*str != '\0') // Loop through string until null terminator
    {
        clcd_write(*str, DATA_MODE); // Write each character to LCD
        str++; // Move to next character in string
    }
}
