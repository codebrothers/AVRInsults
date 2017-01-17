
#include "UART.h"

#include <util/setbaud.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "../Process/CircularBuffer.h"

#define BUFFER_IN_BYTES  32
#define BUFFER_OUT_BYTES 32

// Private headers

void uart_putchar(char c, FILE *stream);
char uart_getchar(FILE *stream);

CircularBuffer *inBuffer;
CircularBuffer *outBuffer;

bool isTransmitting = false;

// Implementation

void uart_init()
{
	inBuffer  = circularBuffer_create(BUFFER_IN_BYTES);
	outBuffer = circularBuffer_create(BUFFER_OUT_BYTES);

    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

	#if USE_2X
	UCSR0A |= _BV(U2X0);
	#else
	UCSR0A &= ~(_BV(U2X0));
	#endif

	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */
	UCSR0B = _BV(RXEN0 ) | _BV(TXEN0 ); /* Enable RX and TX */
	
	UCSR0B |= _BV(RXCIE0); /* Enable Receive Complete ISR */

	sei();

	FILE uart_output = (FILE)FDEV_SETUP_STREAM( &uart_putchar, NULL, _FDEV_SETUP_WRITE );
	FILE uart_input  = (FILE)FDEV_SETUP_STREAM( NULL, &uart_getchar, _FDEV_SETUP_READ);

	stdout = &uart_output;
	stdin  = &uart_input;
}

ISR(USART_RX_vect)
{
	uint8_t byte = UDR0;
	bool didWrite;
	do 
	{
		didWrite = circularBuffer_writeByte( inBuffer, byte );
	}
	while (!didWrite);
}

ISR(USART_TX_vect) 
{
	uint8_t byte;
	bool isDataPending = circularBuffer_readByte( outBuffer, &byte );
	if( isDataPending ) // There is data waiting to be sent...
	{
		UDR0 = byte; // ...write it to the UART data register (initiating transmission)
	}
	else // We've finished transmitting...
	{
		isTransmitting = false;
		UCSR0B &= ~_BV(TXCIE0); // ...disable the Transmit Complete interrupt.
	}
}

void uart_putchar(char byte, FILE *stream) 
{
	if( isTransmitting ) // We are already transmitting...
	{
		bool didWrite;
		do
		{
			didWrite = circularBuffer_writeByte(outBuffer,byte); //...add this byte to the output buffer.
		}
		while( !didWrite );
	}
	else // This is the first byte we're transmitting...
	{
		isTransmitting = true;
		UCSR0B |= _BV(TXCIE0); // Enable Transmit Complete ISR
		UDR0 = byte;
	}
}

char uart_getchar(FILE *stream)
{
	uint8_t c = NULL;
	bool didRead = circularBuffer_readByte(inBuffer,&c);
	return didRead ? c : '\0';
}
