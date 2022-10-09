#include "led.h"

void LED_init(uint8_t LedPort,uint8_t LedPin)  //output device
{
	DIO_int(LedPort,LedPin,OUT);
}



void LED_on(uint8_t LedPort,uint8_t LedPin)  //write high
{
	DIO_write(LedPort,LedPin,HIGH);
}


void LED_off(uint8_t LedPort,uint8_t LedPin)  //write low
{
	
	DIO_write(LedPort,LedPin,LOW);
}


void LED_toggle(uint8_t LedPort,uint8_t LedPin) //toggle
{
	uint8_t value;
	DIO_read(LedPort,LedPin,&value);
	if(value==0)
	{
		LED_on(LedPort,LedPin);
	}
	else if (value==1)
	{
		LED_off(LedPort,LedPin);
	}
}




void LED_blink(uint8_t LedPort,uint8_t LedPin) //led blink
{
	LED_on(LedPort,LedPin);
	TIMER_1_sec_delay();
	LED_off(LedPort,LedPin);
	TIMER_1_sec_delay();
	LED_on(LedPort,LedPin);
	TIMER_1_sec_delay();
	LED_off(LedPort,LedPin);
	TIMER_1_sec_delay();
	LED_on(LedPort,LedPin);
	TIMER_1_sec_delay();
	
}


void LED_blink_2_leds(uint8_t LedPort1,uint8_t LedPin1,uint8_t LedPort2,uint8_t LedPin2) //2 leds blink
{
	LED_on(LedPort1,LedPin1);
	LED_on(LedPort2,LedPin2);
	TIMER_1_sec_delay();
	LED_off(LedPort1,LedPin1);
	LED_off(LedPort2,LedPin2);
	TIMER_1_sec_delay();
	LED_on(LedPort1,LedPin1);
	LED_on(LedPort2,LedPin2);
	TIMER_1_sec_delay();
	LED_off(LedPort1,LedPin1);
	LED_off(LedPort2,LedPin2);
	TIMER_1_sec_delay();
	LED_on(LedPort1,LedPin1);
	LED_on(LedPort2,LedPin2);
	TIMER_1_sec_delay();
	
}








