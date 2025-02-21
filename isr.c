#include <xc.h>   // Include compiler-specific header file
#include "main.h" // Include main project header file

// External variables for tracking time (declared in another source file)
extern unsigned char sec, min;

/* 
 * Interrupt Service Routine (ISR)
 * Handles Timer2 Interrupt for a countdown timer
 */
void __interrupt() isr(void)
{
    static unsigned int count = 0;  // Static variable to maintain count across ISR calls
    
    // Check if Timer2 interrupt flag is set
    if (TMR2IF == 1)
    {    
        // Increment count; 1250 interrupts correspond to 1 second
        if (++count == 1250) // Assuming Timer2 overflows at 0.8ms interval
        {
            count = 0; // Reset count every second
            
            // Countdown logic
            if (sec > 0)
            {
                sec--; // Decrease seconds
            }
            else if ((sec == 0) && (min > 0))
            {
                min--; // Decrease minutes when seconds reach 0
                sec = 59; // Reset seconds to 59
            }
        }
        
        // Clear Timer2 interrupt flag to acknowledge interrupt
        TMR2IF = 0;
    }
}
