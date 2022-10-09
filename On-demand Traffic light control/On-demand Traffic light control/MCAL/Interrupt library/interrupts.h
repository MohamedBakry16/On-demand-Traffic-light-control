#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../UTILITIES/register.h"


//interrupt vectors

//external interrupt request 0
#define EXT_INT_0 __vector_1

//external interrupt request 1
#define EXT_INT_1 __vector_2

//external interrupt request 2
#define EXT_INT_2 __vector_3


//#define TIME_0 __vector_11 ..............




//set global interrupt
#define sci()  __asm__ __volatile__ ("sei" ::: "memory");//clear global interrupt#define cli()  __asm__ __volatile__ ("cli" ::: "memory");



//ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)
#endif