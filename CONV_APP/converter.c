/*
 * converter.c
 *
 * Created: 11/15/2021 2:41:45 AM
 *  Author: younis
 */ 

#include "converter.h"

function_state_type GetAndDisplayNum(u8 line, u8 cell, u8* num)
{
	*num = 0;
	u8 key = KEYPAD_NOKEY, digitCounter = 0;
	

	LCD_GoTo(line, cell);
	
	
	while(key != '=')
	{
		
		key = KEYPAD_GetKey();
		
		if (key == 'b'){
			return BACK;
		}
		
		if (key >='0' && key <='9')
		{
			*num = *num*10+(key-'0');
			digitCounter++;
			LCD_WriteChar(key);
			
		}
		else if (key == 'x' && digitCounter>0)
		{
			LCD_GoToClear(0, (digitCounter-1)+cell, 1);
			digitCounter--;
			LCD_GoTo(line, cell+digitCounter);
			*num = *num/10;
			
		}
		
	}
	
	return DONE;
	
	
	
}



function_state_type GetAndDisplayHex(u8 line, u8 cell, u8* num)
{
	*num = 0;
	u8 key = KEYPAD_NOKEY;
	

	LCD_GoTo(line, cell);
	
	
	while(key != '=')
	{
		
		key = KEYPAD_GetKey();
		
		if (key == 'b'){
			return BACK;
		}
		
		if (key >='0' && key<='9')
		{
			*num = *num*16+(key-'0');
			LCD_WriteChar(key);
			
		}
		
		else if (key == 'A')
		{
			
			*num = *num*16 + 10;
			LCD_WriteChar(key);
			
			
		}
		else if (key == 'B')
		{
			*num = *num*16 + 11;
			LCD_WriteChar(key);
			
		}
		else if (key == 'E')
		{
			*num = *num*16 + 14;
			LCD_WriteChar(key);
			
		}
		else if (key == 'x')
		{
			*num = *num*16 + 15;
			LCD_WriteChar('F');
			
		}
	}
	
	return DONE;
	
	
	
}



function_state_type GetAndDisplayBinary(u8 line, u8 cell, u8* num)
{
	*num = 0;
	u8 key = KEYPAD_NOKEY, digitCounter = 0;


	LCD_GoTo(line, cell);
	
	
	while(key != '=')
	{
		
		key = KEYPAD_GetKey();
		
		if (key == 'b'){
			return BACK;
		}
		
		if (key == '1' || key=='0')
		{
			*num = *num*2+(key-'0');
			LCD_WriteChar(key);
			digitCounter++;
			
			
		}
		else if (key == 'x' && digitCounter>0)
		{
			LCD_GoToClear(0, (digitCounter-1)+cell, 1);
			digitCounter--;
			LCD_GoTo(line, cell+digitCounter);
			*num = *num/2;
			
		}
		
		
		
	}
	

	
	return DONE;
}


function_state_type convertBinaryToDecimal()
{
	
	u8 key= KEYPAD_NOKEY;
	u8 num;

	function_state_type state;
	
	LCD_GoToWriteString(0, 0, "Binary :");
	LCD_GoToWriteString(1, 0, "Decimal:");
	
	
	
	state = GetAndDisplayBinary(0, 8, &num);
	
	if (state == BACK){
		return BACK;
	}
	
	LCD_GoTo(1, 8);
	LCD_WriteNum(num);
	
	
	while(key != 'b')
	{
		key = KEYPAD_GetKey();
	}
	
	return BACK;
	
}


function_state_type convertBinaryToHex()
{
	
	u8 key= KEYPAD_NOKEY;
	u8 num;

	function_state_type state;
	
	LCD_GoToWriteString(0, 0, "Binary :");
	LCD_GoToWriteString(1, 0, "Hex    :");
	
	
	
	state = GetAndDisplayBinary(0, 8, &num);
	
	if (state == BACK){
		return BACK;
	}
	
	LCD_GoTo(1, 8);
	LCD_WriteHex(num);
	
	
	while(key != 'b')
	{
		key = KEYPAD_GetKey();
	}
	
	return BACK;
	
}


function_state_type convertHexToBinary()
{
	
	u8 key= KEYPAD_NOKEY;
	u8 num;

	function_state_type state;
	
	LCD_GoToWriteString(0, 0, "Hex    :");
	LCD_GoToWriteString(1, 0, "Binary :");
	
	
	
	state = GetAndDisplayHex(0, 8, &num);
	
	if (state == BACK){
		return BACK;
	}
	
	LCD_GoTo(1, 8);
	LCD_WriteBinary(num);
	
	
	while(key != 'b')
	{
		key = KEYPAD_GetKey();
	}
	
	return BACK;
	
}


function_state_type convertHexToDecimal()
{
	
	u8 key= KEYPAD_NOKEY;
	u8 Number;
	function_state_type state;
	
	LCD_GoToWriteString(0, 0, "Hex    :");
	LCD_GoToWriteString(1, 0, "Decimal:");
	
	state = GetAndDisplayHex(0, 8, &Number);
	
	if (state == BACK){
		return BACK;
	}
	
	LCD_GoTo(1, 8);
	LCD_WriteNum(Number);
	
	
	while(key != 'b')
	{
		key = KEYPAD_GetKey();
	}
	
	return BACK;
	
}


function_state_type convertDecimalToHex()
{
	u8 key= KEYPAD_NOKEY;
	u8 decimalNumber;
	function_state_type state;
	
	LCD_GoToWriteString(0, 0, "Decimal:");
	LCD_GoToWriteString(1, 0, "Hex    :");
	
	state = GetAndDisplayNum(0, 8, &decimalNumber);
	
	if (state == BACK){
		return BACK;
	}
	
	LCD_GoTo(1, 8);
	LCD_WriteHex(decimalNumber);
	
	
	
	while(key != 'b')
	{
		key = KEYPAD_GetKey();
	}
	
	return BACK;
	
	
	
}


function_state_type convertDecimalToBinary()
{
	u8 key= KEYPAD_NOKEY;
	u8 decimalNumber;
	function_state_type state;
	
	LCD_GoToWriteString(0, 0, "Decimal:");
	LCD_GoToWriteString(1, 0, "Binary :");
	
	state = GetAndDisplayNum(0, 8, &decimalNumber);
	
	if (state == BACK){
		return BACK;
	}
	
	LCD_GoTo(1, 8);
	LCD_WriteBinary(decimalNumber);
	
	
	while(key != 'b')
	{
		key = KEYPAD_GetKey();
	}
	
	return BACK;
	
	
	
}


function_state_type converTo(number_systems_type from)
{
	
	number_systems_type to;
	function_state_type state;
	
	switch(from)
	{
		case DECIMAL:
		
		conver_D_to:
		
		
		LCD_GoToWriteString(0, 0, "Convert D to:");
		LCD_GoToWriteString(1, 0, "1->B, 2->H");
		
		to = KEYPAD_GetKey();
		
		if (to == 'b')
		{
			return BACK;
		}
		
		if (to != KEYPAD_NOKEY)
		{
			LCD_GoTo(0, 13);
			LCD_WriteChar(to);
			_delay_ms(300);
		}
		
		if (to == '1'){
			to = Binary;
			} else if (to == '2'){
			to = HEX;
		}
		
		if (to != Binary && to != HEX)
		{
			LCD_GoToClear(0, 13, 1);
			goto conver_D_to;
		}
		
		LCD_clear();
		
		if (to == Binary)
		{
			state = convertDecimalToBinary();
			if (state == BACK){
				LCD_clear();
				goto conver_D_to;
			}
		}
		else if (to == HEX)
		{
			state = convertDecimalToHex();
			if (state == BACK){
				LCD_clear();
				goto conver_D_to;
			}
		}
		break;
		
		case HEX:
		
		conver_H_to:
		
		LCD_GoToWriteString(0, 0, "Convert H to:");
		LCD_GoToWriteString(1, 0, "1->D, 2->B");
		
		to = KEYPAD_GetKey();
		
		if (to == 'b')
		{
			return BACK;
		}
		
		if (to != KEYPAD_NOKEY)
		{
			LCD_GoTo(0, 13);
			LCD_WriteChar(to);
			_delay_ms(300);
		}
		
		
		if (to != DECIMAL && to != Binary)
		{
			LCD_GoToClear(0, 13, 1);
			goto conver_H_to;
		}
		
		LCD_clear();
		
		if (to == DECIMAL)
		{
			state = convertHexToDecimal();
			if (state == BACK){
				LCD_clear();
				goto conver_H_to;
			}
		}
		else if (to == Binary)
		{
			state = convertHexToBinary();
			if (state == BACK){
				LCD_clear();
				goto conver_H_to;
			}
		}
		break;
		
		
		case Binary:
		
		conver_B_to:
		
		LCD_GoToWriteString(0, 0, "Convert B to:");
		LCD_GoToWriteString(1, 0, "1->D, 2->H");
		
		to = KEYPAD_GetKey();
		
		if (to == 'b')
		{
			return BACK;
		}
		
		if (to != KEYPAD_NOKEY)
		{
			LCD_GoTo(0, 13);
			LCD_WriteChar(to);
			_delay_ms(300);
		}
		
		
		if (to == '2'){
			to = HEX;
		}
		
		
		if (to != DECIMAL && to != HEX)
		{
			LCD_GoToClear(0, 13, 1);
			goto conver_B_to;
		}
		
		LCD_clear();
		
		if (to == DECIMAL)
		{
			state = convertBinaryToDecimal();
			if (state == BACK){
				LCD_clear();
				goto conver_B_to;
			}
		}
		else if (to == HEX)
		{
			state = convertBinaryToHex();
			if (state == BACK){
				LCD_clear();
				goto conver_B_to;
			}
		}
		
		break;
	}
	
}


number_systems_type convertFrom(void )
{
	
	number_systems_type choice;
	
	display_TakeInput:
	
	
	LCD_GoToWriteString(0, 0, "Convert from: ");
	LCD_GoToWriteString(1, 0, "1->D, 2->B, 3->H");
	
	choice = KEYPAD_GetKey();
	
	if (choice != KEYPAD_NOKEY)
	{
		LCD_GoTo(0, 14);
		LCD_WriteChar(choice);
		_delay_ms(300);
	}
	
	if (choice != DECIMAL && choice != Binary && choice != HEX)
	{
		LCD_GoToClear(0, 14, 1);
		goto display_TakeInput;
	}
	
	LCD_clear();
	return choice;
	
}


void welcomeMessage(){
	
	LCD_GoToWriteString(0, 0, "Welcome!");
	LCD_GoToWriteString(1, 0, "A Converter");
	_delay_ms(1500);
	LCD_GoToClear(1, 3, 9);
	LCD_GoToWriteString(1, 0, "Made by Younis");
	_delay_ms(1500);
	
}