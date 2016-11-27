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
#include "pcm_sample.h"
#include <avr/interrupt.h>
#include <avr/sfr_defs.h>
#define SAMPLE_RATE 8000;

volatile uint16_t sample;
int sample_count;
int pcm_length;

/* initialise the PWM */
void initPwmAudio(void)
{
    /* use OC1A pin as output */
    DDRB = _BV(PB1);

    /*
    * clear OC1A on compare match
    * set OC1A at BOTTOM, non-inverting mode
    * Fast PWM, 8bit
    */
    TCCR1A = _BV(COM1A1) | _BV(WGM10);
   
    /*
    * Fast PWM, 8bit
    * Pre-scaler: clk/1 = 8MHz
    * PWM frequency = 8MHz / (255 + 1) = 31.25kHz
    */
    TCCR1B = _BV(WGM12) | _BV(CS10);
   
    /* set initial duty cycle to zero */
    OCR1A = 0;
   
    /* Setup Timer0 */
    TCCR0A|=_BV(CS00);
    TCNT0=0;
    TIMSK0|=_BV(TOIE0);
    sample_count = 4;
    sei(); //Enable interrupts
}

void playBuffer( char* buffer )
{
	//TBC
}

ISR(TIMER0_OVF_vect)
{
	sample_count--;
	if (sample_count == 0)
	{
		sample_count = 4;
		OCR1A = pgm_read_byte(&pcm_samples[sample++]);
		if(sample>pcm_length)sample=0;
	}
}
