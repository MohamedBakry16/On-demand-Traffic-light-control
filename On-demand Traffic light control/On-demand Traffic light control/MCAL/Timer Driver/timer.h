#ifndef TIMER_H_
#define TIMER_H_

#include "../../UTILITIES/register.h"

int overflow_counter;

void TIMER_init(void);   //set configuration
void TIMER_start(void);  //void TIMER_start(uint64_t ticks);
void TIMER_stop(void);
void TIMER_5_sec_delay(void);
void TIMER_1_sec_delay(void);



#endif