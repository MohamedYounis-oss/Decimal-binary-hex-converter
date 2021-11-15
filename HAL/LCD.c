#include "LCD.h"



/**************************************** LCD initialization *********************************/

#if LCD_MODE ==_8_BIT

static void LCD_WriteCommand(u8 command)
{
	
	
	DIO_WritePin(LCD_RS, LOW);
	DIO_WritePort(LCD_PORT, command);
	
	// triggering
	DIO_WritePin(LCD_EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN, LOW);
	_delay_ms(1);

	
}


static void LCD_WriteData(u8 data)
{
	
	
	DIO_WritePin(LCD_RS, HIGH);
	DIO_WritePort(LCD_PORT, data);
	
	// triggering
	DIO_WritePin(LCD_EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN, LOW);
	_delay_ms(1);

	
}

void LCD_Init()
{
	
	_delay_ms(50);				 // Wait for more than 30ms after VDD rises to 4.5V, LCD DataSheet
	LCD_WriteCommand(0x38);		// 2line, 5*7
	LCD_WriteCommand(0x0C);		// cursor
	LCD_WriteCommand(0x01);		// clear screen
	_delay_ms(1);				// Wait for more than 1.53ms
	LCD_WriteCommand(0x06);		// increase DDRAM address with no shifting
		
}

#elif LCD_MODE == _4_BIT

static void LCD_WriteCommand(u8 command)
{
	
	DIO_WritePin(LCD_RS, LOW);
	
	
	
	DIO_WritePin(LCD_D7, GET_BIT(command, 7));
	DIO_WritePin(LCD_D6, GET_BIT(command, 6));
	DIO_WritePin(LCD_D5, GET_BIT(command, 5));
	DIO_WritePin(LCD_D4, GET_BIT(command, 4));
	
	
	
	// triggering
	DIO_WritePin(LCD_EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN, LOW);
	_delay_ms(1);
	
	
	
	DIO_WritePin(LCD_D7, GET_BIT(command, 3));
	DIO_WritePin(LCD_D6, GET_BIT(command, 2));
	DIO_WritePin(LCD_D5, GET_BIT(command, 1));
	DIO_WritePin(LCD_D4, GET_BIT(command, 0));
	
	// triggering
	DIO_WritePin(LCD_EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN, LOW);
	_delay_ms(1);

	
}


static void LCD_WriteData(u8 data)
{
	
	
	DIO_WritePin(LCD_RS, HIGH);
	
	
	
	DIO_WritePin(LCD_D7, GET_BIT(data, 7));
	DIO_WritePin(LCD_D6, GET_BIT(data, 6));
	DIO_WritePin(LCD_D5, GET_BIT(data, 5));
	DIO_WritePin(LCD_D4, GET_BIT(data, 4));
	
	
	
	// triggering
	DIO_WritePin(LCD_EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN, LOW);
	_delay_ms(1);
	
	
	
	DIO_WritePin(LCD_D7, GET_BIT(data, 3));
	DIO_WritePin(LCD_D6, GET_BIT(data, 2));
	DIO_WritePin(LCD_D5, GET_BIT(data, 1));
	DIO_WritePin(LCD_D4, GET_BIT(data, 0));
	
	// triggering
	DIO_WritePin(LCD_EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN, LOW);
	_delay_ms(1);

	
}

void LCD_Init()
{
	
	_delay_ms(50);				 // Wait for more than 30ms after VDD rises to 4.5V, LCD DataSheet
	LCD_WriteCommand(0x02);	
	LCD_WriteCommand(0x28);		// 2line, 5*7, 4bit
	LCD_WriteCommand(0x0C);		// cursor
	LCD_WriteCommand(0x01);		// clear screen
	_delay_ms(1);				// Wait for more than 1.53ms
	LCD_WriteCommand(0x06);		// increase DDRAM address with no shifting
	
}

#endif

/****************************************************************************************************/

void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}

void LCD_WriteString(u8* str)
{
	for (u8 i=0; str[i]; i++)	{
		
		LCD_WriteData(str[i]);
		
	}
}

void LCD_WriteNum(u8 num) //2503
{
	u8 str[20];
	u8 rem, i=0;
	s8 j;
	
	if (num == 0)
	{
		LCD_WriteChar('0');
		return; 
	}
	
	if (num < 0){
		num = num*-1;
		LCD_WriteChar('-');
	}
	
	 while(num>0)
	 {
		 rem = num%10;
		 str[i] = rem + '0';
		 num = num/10;
		 i++;
	 }
	 
	 for (j=i-1; j>=0; j--)
	 {
		 LCD_WriteChar(str[j]);
	 }
}


void LCD_WriteNum_4digits(u16 num)
{
	
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}


void LCD_WriteBinary(u16 num)
{
	s8 i,flag=0;
	for (i=15;i>=0;i--)
	{
		if ((num>>i)&1)
		{
			LCD_WriteChar('1');
			flag=1;
		}
		else
		{
			if (flag==1)
			{
				LCD_WriteChar('0');
			}
			
		}
	}

}


u8 read_nibble(u16 num, u8 nibble){
	
	
	u8 i, j, n, result;
	
	if (nibble == 0)
	{
		i = 0;
	}
	else if (nibble == 1){
		i = 4;
	}
	else if (nibble == 2){
		i = 8;
	}
	else if (nibble == 3){
		i = 12;
	}
	
	j = 1;
	result = 0;
	n = 4;
	
	while (n>0){
		
		if ((num>>i) & 1 == 1){
			result = result + j;
		}
		
		j *=2;
		i++;
		n--;
	}
	
	return result;
	
}


void LCD_WriteHex(u16 num)
{
	
	u8 ch;
	u8 flag = 0;
	
	
	

	u8 hex[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
		
	
	
	for (s8 i=3; i>=0; i--)
	{
		ch = read_nibble(num, i);
		
		if (ch == 0 && flag)
		{
			LCD_WriteNum(ch);
			
			
		}
		else if(ch >=1 && ch<=9)
		{
			LCD_WriteNum(ch);
			flag = 1;
			
			
		}
		else if (ch >=10 && ch<=15)
		{
			LCD_WriteChar(hex[ch-10]);
		}
	}
		
}

void LCD_GoTo(u8 line, u8 cell)
{
	
	
	if (line == 0)
	{
		LCD_WriteCommand(0x80 + cell);
		
	}
	else if (line == 1)
	{
		LCD_WriteCommand(0xC0  + cell);
	}
	
	
	
}

void LCD_GoToWriteString(u8 line, u8 cell, u8* str)
{
	LCD_GoTo(line, cell);
	LCD_WriteString(str);
}


void LCD_GoToClear(u8 line, u8 cell, u8 numOfCells)
{
	
	u8 i;
	
	LCD_GoTo(line, cell);
	
	for (i=0; i<numOfCells; i++)
	{
		LCD_WriteChar(' ');
	}
	
}


void LCD_clear(){
	
	LCD_GoToClear(0, 0, 16);
	LCD_GoToClear(1, 0, 16);
		
}