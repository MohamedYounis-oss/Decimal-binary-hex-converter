#include "SEGMENT.h"
#include "MemMap.h"
#include "Utils.h"
#include "DCMotor.h"
#include "KeyPad.h"
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "converter.h"




int main(void)
{
	
	
	DIO_Init();
	LCD_Init();
	welcomeMessage();
	
	number_systems_type choice;
	function_state_type state;
	
	while(1)
	{
		choice = convertFrom();
		
		state = converTo(choice);
		
		
	}
	
	
	
}

