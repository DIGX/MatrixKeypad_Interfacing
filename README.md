Matrix Keypad Library for PIC16F887
================================================================================
 * Usages examples
 * ----------------------------------------------------------------------------
 * Keypad_begin(WITH_ISR)           - Initialise the Keypad with Keypad Interrupt Enabled(WITH_ISR or WITHOUT_ISR)
 * Key = Keypad_waitForKey()        - Wait until a Key is pressed(It blocks the execution)
 * Key = Keypad_getKey()            - Get the Key if pressed(Non-blocking)
 * Stat = Keypad_getKeyState(2,3)   - Get status of Key positioned at ROW 2 and COL 3(PRESSED or RELEASED)
 *
 * Key = Keypad_ISR()               - ISR for Keypad to call from MAIN Interrupt routine

 
 This code is written utilizing the "Interrupt on Pin Change" feature of PORTB
 in PICmicro devices when working with Keypad INTERRUPT Enabled. Keep the
 COLUMN connections to PORTB4-7 to maintain compatibility with all PICmicro series.

 The circuit:
 * Keypad Row 1 pin any available port define as KP_ROW1 in Keypad.h
 * Keypad Row 2 pin any available port define as KP_ROW2 in Keypad.h
 * Keypad Row 3 pin any available port define as KP_ROW3 in Keypad.h
 * Keypad Row 4 pin any available port define as KP_ROW4 in Keypad.h
 * Keypad Column 1 pin connected to PORTB4 define as KP_COL1 in Keypad.h
 * Keypad Column 2 pin connected to PORTB5 define as KP_COL2 in Keypad.h
 * Keypad Column 3 pin connected to PORTB6 define as KP_COL3 in Keypad.h
 * Keypad Column 4 pin connected to PORTB7 define as KP_COL4 in Keypad.h
 * 4 x 10K resistor: Pullup Resistors need to be connected between Keypad Column pins and VCC.(Only needed if Keypad Column pins connected to ports other than PORTB)
 
 Direction Controls defined in Keypad.h
 eg:-
 * #define KP_ROW1_dir TRISB0
 * #define KP_ROW2_dir TRISB1
 * #define KP_ROW3_dir TRISB2
 * #define KP_ROW4_dir TRISB3
 * #define KP_COL1_dir TRISB4
 * #define KP_COL2_dir TRISB5
 * #define KP_COL3_dir TRISB6
 * #define KP_COL4_dir TRISB7
 
