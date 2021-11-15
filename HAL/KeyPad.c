#include "KeyPad.h"

u8 KEYPAD_GetKey(void) 
{
	
	u8 r, c, key = KEYPAD_NOKEY;
	
	DIO_WritePin(KEYPAD_FIRST_OUTPUT, HIGH);
	DIO_WritePin(KEYPAD_FIRST_OUTPUT+1, HIGH);
	DIO_WritePin(KEYPAD_FIRST_OUTPUT+2, HIGH);
	DIO_WritePin(KEYPAD_FIRST_OUTPUT+3, HIGH);
	
	//_delay_ms(1000);
	
	for (r=0; r<KEYPAD_ROWs; r++)
	{
		DIO_WritePin(KEYPAD_FIRST_OUTPUT+r, LOW);
		
		for (c=0; c<KEYPAD_COLs; c++)
		{
			if (DIO_ReadPin(KEYPAD_FIRST_INPUT+c) == LOW)
			{
				key = KeysArray[r][c];
				while(DIO_ReadPin(KEYPAD_FIRST_INPUT+c) == LOW);
			}
		}
		
		DIO_WritePin(KEYPAD_FIRST_OUTPUT+r, HIGH);
	}
	
	return key;
	
}




