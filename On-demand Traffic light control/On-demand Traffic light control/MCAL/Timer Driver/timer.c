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

void TIMER_stop(void){	TCCR0 =0x00;}void TIMER_clearoverflowflag(void){	TIFR |=(1<<0);	}void TIMER_5_sec_delay(void){		int number_of_overflow = 20;	overflow_counter=0;	TIMER_init();	TIMER_start();	while(overflow_counter<number_of_overflow)	{		while ((TIFR &(1<<0))==0);		TIMER_clearoverflowflag();		overflow_counter++;	}	TIMER_stop();}void TIMER_1_sec_delay(void)
{
	int number_of_overflow = 4;	int overflow_counter=0;	TIMER_init();	TIMER_start();	while(overflow_counter<number_of_overflow)	{		while ((TIFR &(1<<0))==0);		TIMER_clearoverflowflag();		overflow_counter++;	}	TIMER_stop();	
}
