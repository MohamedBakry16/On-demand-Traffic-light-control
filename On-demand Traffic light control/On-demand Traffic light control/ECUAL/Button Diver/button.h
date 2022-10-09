#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/DIO.h"

void BUTTON_init(uint8_t ButtonPort,uint8_t ButtonPin); //initialization
void BUTTON_read(uint8_t ButtonPort,uint8_t ButtonPin,uint8_t *value); //read button  pointer to return the value without using function return


#endif