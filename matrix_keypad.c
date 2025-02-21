#include <xc.h>
#include "matrix_keypad.h"

/*
 * Function: init_matrix_keypad
 * ----------------------------
 * Initializes the matrix keypad by setting the row and column pins correctly.
 * Configures pull-up resistors for column inputs and ensures rows are set high initially.
 */
void init_matrix_keypad(void)
{
    // Setting the Columns as Inputs (RB2 - RB0)
    MATRIX_KEYPAD_COLUMN_PORT_DDR |= 0x07; // Set lower 3 bits of PORTB as inputs
   
    // Setting the Rows as Outputs (RD3 - RD0)
    MATRIX_KEYPAD_ROW_PORT_DDR &= 0xF0; // Clear lower 4 bits of PORTD to set as outputs
    
    // Enabling PORTB Pullups
    nRBPU = 0;
    
    // Making all the Rows HIGH initially
    ROW1 = HI;
    ROW2 = HI;
    ROW3 = HI;
    ROW4 = HI;
}

/*
 * Function: scan_keypad
 * ----------------------
 * Scans the matrix keypad by pulling each row low and checking column states.
 * Returns the key value if pressed, otherwise returns ALL_RELEASED.
 */
static unsigned char scan_keypad(void)
{
    int i;
    
    // Scan Row 1
    ROW1 = LOW;
    ROW2 = HI;
    ROW3 = HI;
    ROW4 = HI;   
    
    for (i = 100; i--; ); // Delay for stabilization
    
    if (COL1 == LOW) return 1;
    if (COL2 == LOW) return 2;
    if (COL3 == LOW) return 3;
    
    // Scan Row 2
    ROW1 = HI;
    ROW2 = LOW;
    ROW3 = HI;
    ROW4 = HI;   
    
    for (i = 100; i > 0; i--);
    
    if (COL1 == LOW) return 4;
    if (COL2 == LOW) return 5;
    if (COL3 == LOW) return 6;
    
    // Scan Row 3
    ROW1 = HI;
    ROW2 = HI;
    ROW3 = LOW;
    ROW4 = HI;   

    for (i = 100; i > 0; i--);
    
    if (COL1 == LOW) return 7;
    if (COL2 == LOW) return 8;
    if (COL3 == LOW) return 9;
    
    // Scan Row 4
    ROW1 = HI;
    ROW2 = HI;
    ROW3 = HI;
    ROW4 = LOW;   

    for (i = 100; i > 0; i--);
    
    if (COL1 == LOW) return '*';
    if (COL2 == LOW) return 0;
    if (COL3 == LOW) return '#';
    
    return ALL_RELEASED;
}

/*
 * Function: read_matrix_keypad
 * ----------------------------
 * Reads the matrix keypad based on the given mode (LEVEL or STATE).
 * LEVEL mode returns the current key state.
 * STATE mode returns key press only once per press cycle.
 */
unsigned char read_matrix_keypad(unsigned char mode) // LEVEL STATE 
{
    static unsigned char once = 1;
    unsigned char key;
    
    key = scan_keypad(); // Scan the keypad for a key press
    
    if (mode == LEVEL)
    {
        return key; // Return key state directly
    }
    else // STATE mode: Detects only state change
    {
        if ((key != ALL_RELEASED) && once)
        {
            once = 0;
            return key; // Return key only once per press
        }
        else if (key == ALL_RELEASED)
        {
            once = 1; // Reset flag when key is released
        }
    }
    
    return ALL_RELEASED;
}
