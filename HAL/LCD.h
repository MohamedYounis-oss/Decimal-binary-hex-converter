#ifndef LCD_H_
#define LCD_H_

#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"
#include "DIO_Interface.h"


#define  _4_BIT 1
#define  _8_BIT 2



/***********************************************pin Config*******************************/

#define LCD_MODE _4_BIT

#define LCD_PORT PA	// if 8 bit in order

#define LCD_RS   PINA1
#define LCD_EN   PINA2 

#define LCD_D4 PINA3
#define LCD_D5 PINA4
#define LCD_D6 PINA5
#define LCD_D7 PINA6

/************************************************************************************/


void LCD_Init();

void LCD_WriteChar(u8 ch);

void LCD_WriteString(u8* str);

void LCD_WriteNum(u8 num);

void LCD_WriteNum_4digits(u16 num);

void LCD_clear(void);

void LCD_WriteBinary(u16 num);

void LCD_GoTo(u8 line, u8 cell);

void LCD_GoToClear(u8 line, u8 cell, u8 numOfCells);

void LCD_GoToWriteString(u8 line, u8 cell, u8* str);

	 

#endif /* LCD_H_ */