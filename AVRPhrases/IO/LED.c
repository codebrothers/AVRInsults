
#include "LED.h"

#include <avr/sfr_defs.h>
#include <avr/io.h>

void led_set(int on)
{
	if(on>0)
	{
		PORTB |= _BV(PORTB0);
	}
	else
	{
		PORTB &= ~_BV(PORTB0);
	}
}

