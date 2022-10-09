#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/DIO.h"

void LED_init(uint8_t LedPort,uint8_t LedPin);
void LED_on(uint8_t LedPort,uint8_t LedPin);
void LED_off(uint8_t LedPort,uint8_t LedPin);
void LED_toggle(uint8_t LedPort,uint8_t LedPin);
void LED_blink(uint8_t LedPort,uint8_t LedPin);
void LED_blink_2_leds(uint8_t LedPort1,uint8_t LedPin1,uint8_t LedPort2,uint8_t LedPin2);

#endif