#include "timer.h"

void TIMER_init(void)
{
	TCCR0 =0x00; //select normal mode
	TCNT0 =12;  //set timer initial value
	
}



void TIMER_start(void) //put prescaler, 1024 prescaler
{
	
	TCCR0 |=(1<<0);
	TCCR0 |=(1<<2);
	
}


{
	int number_of_overflow = 4;
}