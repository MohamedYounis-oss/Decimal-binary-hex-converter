
#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"
#include "DIO_Interface.h"

/********************************************pin config*******************************/

#define KEYPAD_FIRST_OUTPUT PINB4
#define KEYPAD_FIRST_INPUT PIND2

#define KEYPAD_COLs 4
#define KEYPAD_ROWs 4
#define KEYPAD_NOKEY 'N'




static KeysArray[KEYPAD_ROWs][KEYPAD_COLs] = {	{'1', '2', '3', 'A'},
												{'4', '5', '6', 'B'},
												{'7', '8', '9', 'E'},
												{'b', '0', '=', 'x'}
												};

/*************************************************************************************/

u8 KEYPAD_GetKey(void);


#endif /* KEYPAD_H_ */