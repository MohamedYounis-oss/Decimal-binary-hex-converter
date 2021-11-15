/*
 * converter.h
 *
 * Created: 11/15/2021 2:42:06 AM
 *  Author: younis
 */ 


#ifndef CONVERTER_H_
#define CONVERTER_H_

#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"
#include "KeyPad.h"
#include "LCD.h"


typedef enum{
	
	DONE,
	BACK,
	
}function_state_type;


typedef enum{
	
	
	DECIMAL='1',
	Binary,
	HEX
	
}number_systems_type;



function_state_type GetAndDisplayNum(u8 line, u8 cell, u8* num);
function_state_type GetAndDisplayHex(u8 line, u8 cell, u8* num);
function_state_type GetAndDisplayBinary(u8 line, u8 cell, u8* num);
function_state_type convertBinaryToDecimal();
function_state_type convertBinaryToHex();
function_state_type convertHexToBinary();
function_state_type convertHexToDecimal();
function_state_type convertDecimalToHex();
function_state_type convertDecimalToBinary();
function_state_type converTo(number_systems_type from);
number_systems_type convertFrom(void );
void welcomeMessage();
	
	
	




#endif /* CONVERTER_H_ */