#include "application.h"

int color=0;

void APP_start(void)
{
	//interrupts setup
	sci() //or set bit 7 in status register
	MCUCR |=(1<<0) | (1<<1); //chose sensing control
	GICR |=(1<<6);  //enable external interrupt INT0
	
	
	
	
	//One push button
	BUTTON_init(PORT_D,2);
	
	
	//Three LEDs for cars - Green, Yellow, and Red
	LED_init(PORT_A,0); //green
	LED_init(PORT_A,1); //yellow
	LED_init(PORT_A,2); //red
	
	
	//Three LEDs for pedestrians - Green, Yellow, and Red
	LED_init(PORT_B,0); //green
	LED_init(PORT_B,1); //yellow
	LED_init(PORT_B,2); //red
	
	
	
	while(1)
	{
		
		
		//normal mode
		LED_on(PORT_A,0); //green
		LED_on(PORT_B,2); //red
		color=0;
		TIMER_5_sec_delay();
		LED_off(PORT_A,0);
		LED_off(PORT_B,2); //red
		
		
		LED_on(PORT_B,2);
		LED_blink(PORT_A,1); //yellow
		color=1;
		LED_off(PORT_A,1);
		LED_off(PORT_B,2);
		
		
		LED_on(PORT_A,2);//red
		LED_on(PORT_B,0);
		color=2;
		TIMER_5_sec_delay();
		LED_off(PORT_A,2);
		LED_off(PORT_B,0);
		
		
		
		LED_on(PORT_B,2);
		LED_blink(PORT_A,1); //yellow
		color=1;
		LED_off(PORT_A,1);
		LED_off(PORT_B,2);
		
	}
	
}



ISR(EXT_INT_0)
 {
	 switch(color)
	 {
		 case green:
		 LED_off(PORT_A,0); //green
		 LED_on(PORT_B,2); //pedestrian's Red
		 LED_blink_2_leds(PORT_A,1,PORT_B,1); //car's, pedestrian's yellow
		 LED_off(PORT_B,2); //pedestrian's Red
		 LED_off(PORT_A,1); //car's yellow
		 LED_off(PORT_B,1); //pedestrian's yellow
		 ///////////////////////////////////////////////////////
		 LED_on(PORT_A,2); // cars' Red
		 LED_on(PORT_B,0); //pedestrian's Green
		 TIMER_5_sec_delay();
		 LED_off(PORT_A,2); // cars' Red
		 //////////////////////////////////////////////////////
		 LED_blink_2_leds(PORT_A,1,PORT_B,1); //car's, pedestrian's yellow
		 LED_off(PORT_A,1); //car's yellow
		 LED_off(PORT_B,1); //pedestrian's yellow
		 ////////////////////////////////////////////////////
		 LED_off(PORT_B,0); //pedestrian's Green
		 LED_on(PORT_B,2); //pedestrian's Red
		 LED_on(PORT_A,0); // cars' green
		 TIMER_1_sec_delay();
		 LED_off(PORT_B,2); //pedestrian's Red
		 LED_off(PORT_A,0); // cars' green
		 TIMER_start(); //to start timer again 
		 overflow_counter=20; //to prevent delay when return to normal mode
		 break;
		 
		 
		 case yellow:
		 LED_off(PORT_A,1); //yellow
		 LED_off(PORT_A,0); //green
		 LED_on(PORT_B,2); //pedestrian's Red
		 LED_blink_2_leds(PORT_A,1,PORT_B,1); //car's, pedestrian's yellow
		 LED_off(PORT_B,2); //pedestrian's Red
		 LED_off(PORT_A,1); //car's yellow
		 LED_off(PORT_B,1); //pedestrian's yellow
		 ///////////////////////////////////////////////////////
		 LED_on(PORT_A,2); // cars' Red
		 LED_on(PORT_B,0); //pedestrian's Green
		 TIMER_5_sec_delay();
		 LED_off(PORT_A,2); // cars' Red
		 //////////////////////////////////////////////////////
		 LED_blink_2_leds(PORT_A,1,PORT_B,1); //car's, pedestrian's yellow
		 LED_off(PORT_A,1); //car's yellow
		 LED_off(PORT_B,1); //pedestrian's yellow
		 ////////////////////////////////////////////////////
		 LED_off(PORT_B,0); //pedestrian's Green
		 LED_on(PORT_B,2); //pedestrian's Red
		 LED_on(PORT_A,0); // cars' green
		 TIMER_1_sec_delay();
		 TIMER_start();
	     overflow_counter=20; //to prevent delay when return to normal mode
		 break;
		 
		 
		 case red:
		 LED_on(PORT_B,0); //pedestrian's Green
		 LED_on(PORT_A,2); // cars' Red
		 TIMER_5_sec_delay();
		 LED_off(PORT_B,0); //pedestrian's Green
		 LED_off(PORT_A,2); // cars' Red
		 TIMER_start();
		 overflow_counter=20; //to prevent delay when return to normal mode
		 break;
	   
		  
	  }
 	
 }






