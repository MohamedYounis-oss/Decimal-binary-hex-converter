# Decimal-binary-hex-converter
Decimal, binary, hexadecimal converter, using ATmega32 microcontroller, 16*2 LCD and 4*4 Keypad

This project developed using static design concept, 
Application layer, where you will find two files concerning the converter,
Hardware abstraction layer, where you will find files that contains lcd and keypad drivers,
Microcontroller abstraction layer, where you will find the DIO driver.

The keypad matrix:
consists of 16 button:
- numbers from 0 to 9
- (=) button
- (back) button
- 3 buttons (A), (B), (E)
- And a button that acts as (F) and (delete).

