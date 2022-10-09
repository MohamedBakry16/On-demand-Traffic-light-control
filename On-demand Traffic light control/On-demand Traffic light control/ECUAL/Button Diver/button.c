#include "button.h"

void BUTTON_init(uint8_t ButtonPort,uint8_t ButtonPin) //input device
{
	DIO_int(ButtonPort,ButtonPin,IN);
	
}


void BUTTON_read(uint8_t ButtonPort,uint8_t ButtonPin,uint8_t *value)
{
	DIO_read(ButtonPort,ButtonPin,*value);
	
}
