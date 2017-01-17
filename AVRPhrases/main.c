
#include <stdio.h>
#include <math.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <stdbool.h>
#include <string.h>

#include "sam.h"
#include "render.h"
#include "IO/UART.h"
#include "IO/PWMAudio.h"
#include "Process/CircularBuffer.h"

CircularBuffer* outputSampleBuffer;

void sampleBufferOutputFunction( unsigned char sample );

//ISR (BADISR_vect)
//{
//}

int main (void)
{
#if false
	int resetReason = MCUSR;
	MCUSR = 0;
	wdt_disable();
#endif

	// Setup audio output
	{
		outputSampleBuffer = circularBuffer_create(64);
		pwmAudio_init( outputSampleBuffer );
		samOutputFunction = &sampleBufferOutputFunction;
	}

	// Set example speech
	{
		char* phonemes = "AY5 AEM EY TAO4LXKIHNX KAX4MPYUX4TAH. GOW4 AH/HEH3D PAHNK.MEYK MAY8 DEY.\x9b\0";
		SetInput(phonemes);
	}

	while(true)
	{
		SAMMain();
	}
}

void sampleBufferOutputFunction( unsigned char sample )
{
	while( circularBuffer_isFull( outputSampleBuffer ) );
	circularBuffer_writeByte( outputSampleBuffer, sample );
}