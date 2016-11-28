/*
 * PWMAudio.c
 *
 * Created: 27/11/2016 12:16:16 PM
 *  Author: Chris
 */ 

 /*
  ATmega32 @ 8MHz
  Plays an 8bit/8000 sample PCM audio on OC1A output
*/

#include "PWMAudio.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/sfr_defs.h>
#define SAMPLE_RATE 8000;

volatile uint16_t sample;
int sampleRepeatCount;
int pcm_length;

CircularBuffer *_sampleBuffer;
uint8_t _readSample;

/* initialise the PWM */
void initPwmAudio( CircularBuffer *sampleBuffer )
{
	_sampleBuffer = sampleBuffer;

    DDRB = _BV(PB1); // Set up PORTB.1 (aka OC1A) pin as output

	/* Set-up Timer 1 (PWM) */
    TCCR1A =         // Timer/Counter 1, Control Register A (See section 20.14.1 in data-sheet)
		_BV(COM1A1)  // Set the external OC1A pin (PortB.1) to 0, upon matching counter with OCR1A
	  | _BV(WGM10);  // Fast PWM, 8bit (1st bit of Waveform Generation Mode option)

    TCCR1B =		// Timer/Counter 1, Control Register B (See section 20.14.1 in data-sheet)
		_BV(WGM12)  // Fast PWM, 8bit (2nd bit of Waveform Generation Mode option)
	  | _BV(CS10);  // Set a Clock Scale of 1 (count at the full 8MHz)
   
    OCR1A = 0; /* Set initial count state to 0 */
   
    /* Setup Timer 0 () */
    TCCR0A |= _BV(CS00); //
    TCNT0=0;
    TIMSK0|=_BV(TOIE0);

    sampleRepeatCount = 4;

    sei(); //Enable interrupts
}

ISR(TIMER0_OVF_vect)
{
	sampleRepeatCount--;
	if (sampleRepeatCount == 0)
	{
		sampleRepeatCount = 4;
		bool success = circularBuffer_readByte(_sampleBuffer, &_readSample);
		OCR1A = success ? _readSample : 0;
		if(sample>pcm_length)sample=0;
	}
}
