/*
 * LED blink with interupts.c
 *
 * Created: 6/8/2023 1:29:14 AM
 * Author : Asus
 */ 

#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <avr/io.h>

volatile int toggle = 0;
int main(void)
{
	EICRA |= 0B00001100;//rising edge
	EIMSK |= 0B00000010;//Enable External Interrupt 1
	sei(); //Enabling  the global Interrupt
	
    /* Set Data Direction */
	DDRB  = 0B11111110; //Pin 0 as input,reset as output
	//DDRD &= 0B11110111; //pin 3 as input
    while (1) 
    {
    }
}


/*Timer1 Compare Interrupt A ISR*/
ISR (INT1_vect)
{
	PORTB |= 0B00100000;//Set PORTB pin 5 to 1
	if (toggle)
	{
		PORTB |= 0B00100000;//set PORTB pin 5 to 1
	}
	else
	{
		PORTB &= 0B11011111;//set PORTB pin 5 to 0
	}
	toggle = 1-toggle;
}