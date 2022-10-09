#include "dio.h"

void DIO_int(uint8_t PortNumber,uint8_t PinNumber,uint8_t direction)
{
	switch(PortNumber)
	{
		
		case PORT_A:
		if(direction==IN)
		{
			DDRA &= ~(1<<PinNumber);  //input
		}
		else if (direction==OUT)
		{
			DDRA |=(1<<PinNumber);    //output
		}
		else
		{
			//error handling
		}
		break;
		
		
		
		case PORT_B:
		if(direction==IN)
		{
			DDRB &= ~(1<<PinNumber);
		}
		else if (direction==OUT)
		{
			DDRB |=(1<<PinNumber);
		}
		else
		{
			//error handling
		}
		break;
		
		
		case PORT_C:
		if(direction==IN)
		{
			DDRC &= ~(1<<PinNumber);
		}
		else if (direction==OUT)
		{
			DDRC |=(1<<PinNumber);
		}
		else
		{
			//error handling
		}
		break;
		
		
		
		case PORT_D:
		if(direction==IN)
		{
			DDRD &= ~(1<<PinNumber);
		}
		else if (direction==OUT)
		{
			DDRD |=(1<<PinNumber);
		}
		else
		{
			//error handling
		}
		break;
		
	}
	
}








void DIO_write(uint8_t PortNumber,uint8_t PinNumber,uint8_t value)
{
	switch(PortNumber)
	{
		
		case PORT_A:
		if(value==LOW)
		{
			PORTA &= ~(1<<PinNumber);  //write 0
		}
		else if (value==HIGH)
		{
			PORTA |=(1<<PinNumber);   //write 1
		}
		else
		{
			//error handling
		}
		break;
		
		
		
		
		case PORT_B:
		if(value==LOW)
		{
			PORTB &= ~(1<<PinNumber);  //write 0
		}
		else if (value==HIGH)
		{
			PORTB |=(1<<PinNumber);    //write 1
		}
		else
		{
			//error handling
		}
		break;
		
		
		
		case PORT_C:
		if(value==LOW)
		{
			PORTC &= ~(1<<PinNumber);  //write 0
		}
		else if (value==HIGH)
		{
			PORTC |=(1<<PinNumber);    //write 1
		}
		else
		{
			//error handling
		}
		break;
		
		
		
		case PORT_D:
		if(value==LOW)
		{
			PORTD &= ~(1<<PinNumber);  //write 0
		}
		else if (value==HIGH)
		{
			PORTD |=(1<<PinNumber);    //write 1
		}
		else
		{
			//error handling
		}
		break;
		
		
	}
	
}





void DIO_read(uint8_t PortNumber,uint8_t PinNumber,uint8_t *value)
{
	switch (PortNumber)
	{
		case PORT_A:
		*value=(PINA &(1<<PinNumber))>>PinNumber;   //get state ->read bit  0 or 1
		break;
		
		case PORT_B:
		*value=(PINB &(1<<PinNumber))>>PinNumber;   //get state ->read bit  0 or 1
		break;
		
		case PORT_C:
		*value=(PINC &(1<<PinNumber))>>PinNumber;   //get state ->read bit  0 or 1
		break;
		
		case PORT_D:
		*value=(PIND &(1<<PinNumber))>>PinNumber;   //get state ->read bit  0 or 1
		break;
		
		
		default:
		//error handling
		break;
	}
}