/*
 * Calculator.cpp
 *
 * Created: 2018-12-07 14:28:18
 * Author : Szymon
 */ 

#include <avr/io.h>
#include <program.h>
#include <mtype.h>
#include <array.h>
#include <text.h>
#include <sheet.h>
#include <states.h>
#include <WindowsInterface.h>

int main(void)
{
	DDRF |= (1<<PINF7);
	PORTF |= (1<<PINF7);
	
	DDRB |=(1<<PINB6);
	
	TCCR1A = (1<<COM1B1)|(1<<COM1B0)|(1<<WGM11);
	TCCR1B = (1<<WGM13)|(1<<CS12)|(1<<CS10);
	TCNT1 = 0;
	ICR1 = 90;
	OCR1B = 70;
	
	Program program;
	
	program.Run();

	while(1){};
		
		
};


