#ifndef DIO_H_
#define DIO_H_



#include "../../UTILITIES/register.h"


#define PORT_A  'A'
#define PORT_B  'B'
#define PORT_C  'C'
#define PORT_D  'D'


//Direction defines
#define IN 0
#define OUT 1


//Values defines
#define LOW 0
#define HIGH 1



void DIO_int(uint8_t PortNumber,uint8_t PinNumber,uint8_t direction);
void DIO_write(uint8_t PortNumber,uint8_t PinNumber,uint8_t value);
void DIO_toggle(uint8_t PortNumber,uint8_t PinNumber);
void DIO_read(uint8_t PortNumber,uint8_t PinNumber,uint8_t *value);


#endif