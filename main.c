/* 
 * File:   main.c
 * Author: Admin
 *
 * Created on 12 October 2014, 01:49
 */

//	Include files
//==========================================================================
#include <htc.h>
#include "system.h"
#include "lcd.h"
#include "Keypad.h"


//   Configuration setting
//==========================================================================

__CONFIG(   FOSC_INTRC_NOCLKOUT &   // Internal oscillator, No clock out
            WDTE_OFF &              // Disable Watchdog Timer.
            PWRTE_ON &              // Enable Power Up Timer.
            BOREN_OFF &             // Disable Brown Out Reset.
            MCLRE_OFF &             // MCLR function is disabled
            LVP_OFF);               // Disable Low Voltage Programming.

//	Function prototypes
//==========================================================================


//	Global variables
//==========================================================================
unsigned char Key = 0;


//	Interrupt Service Routines
//==========================================================================
void interrupt ISR(void)
{
    // Add this code in the ISR if Keypad_begin(WITH_ISR) is called
    if (RBIF)
    {
        Key = Keypad_ISR();
    }
    
}
//	Main function
//==========================================================================
void main(void)
{
    // Internal Oscillator Configuration for initial run
    OSCCON = 0x01;
    // Specify Clock Source as INTERNAL/EXTERNAL  - Frequency will be set using _XTAL_FREQ
    Osc_Setup(INTERNAL);
    // System_setup Disables all Analog Pins by default. Configure it in Analog function call
    System_Setup();
    // Setup the LCD with number of columns and rows:
    LCD_begin();

    // Setup the Keypad WITH_ISR or WITHOUT_ISR
    // You should add this code in the ISR if Keypad_begin(WITH_ISR) is called
//    if (RBIF)
//    {
//        Key = Keypad_ISR();
//    }
    Keypad_begin(WITH_ISR);
    
    LCD_print(1, 1, "WWW.DIGXTECH.COM");    // LCD display (Please refer lcd.c for detail)
    LCD_print(2, 1, "Key pressed:    ");

    Set_LCD(L_CMD, DISPLAY_CONTROL | DISP_ON | CURS_ON| BLINK);
    LCD_setCursor(2,14);

    //loop forever
    while(1)
    {
        // Uncomment the below line if you want to use Keypad WITHOUT_ISR
//        Key = Keypad_waitForKey();    // Waits until a key is pressed
        // Uncomment this instead of above function if you don't want to wait
//        Key = Keypad_getKey();    // It gets the Key or return 0
        
        if(Key)                     // Key is automatically updated in the ISR if Enabled
        {
            LCD_setCursor(2,14);    // Set the Cursor location
            LCD_putchar(Key);       // Print Key on LCD
            Key = 0;                // Reset the Key value
        }
    }
}