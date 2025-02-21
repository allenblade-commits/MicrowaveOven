#include "main.h"

/*
 * Function: init_timer2
 * ---------------------
 * Initializes Timer2 with a prescaler and preload value.
 * Configures Timer2 for a 1:16 prescaler and a preload value of 250.
 * Enables the Timer2 interrupt but keeps the timer initially OFF.
 */
void init_timer2(void)
{
    /* Setting the Timer2 prescaler to 1:16 */
    T2CKPS0 = 1;  // Bit 0 of prescaler selection
    T2CKPS1 = 1;  // Bit 1 of prescaler selection

    /* Loading the Preload register with 250 */
    PR2 = 250;  // Timer2 counts from 0 to 250 before resetting

    /* Enabling the Timer2 interrupt */
    TMR2IE = 1;  // Enables Timer2 overflow interrupt

    /* Turning OFF Timer2 initially */
    TMR2ON = OFF;  // Timer2 remains off until explicitly started
}
