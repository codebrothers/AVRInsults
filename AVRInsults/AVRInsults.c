
#define F_CPU 8000000UL
#define BAUD 38400

#include <util/delay.h>
#include <avr/io.h>
#include <util/setbaud.h>
#include <stdio.h>
#include <stdlib.h>

#define BAUD_PRESCALE (((F_CPU / (BAUD * 16UL))) - 1)

void uart_putchar(char c, FILE *stream);
char uart_getchar(FILE *stream);
void setLED(int on);

int main (void)
{
	char* input = malloc( 256*sizeof(char) );

	FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
	FILE uart_input  = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);

	stdout = &uart_output;
	stdin  = &uart_input;

	UCSR0B = (1 << RXEN0)  | (1 << TXEN0);   // Turn on the transmission and reception circuitry
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01); // Use 8-bit character sizes

	UBRR0H = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
	UBRR0L = BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register

	printf("You idiot");
}

void uart_putchar(char c, FILE *stream)
{
	while ((UCSR0A & (1 << UDRE0)) == 0) {}; // Do nothing until UDR is ready for more data to be written to it
	UDR0 = c; // Echo back the received byte back to the computer
}

char uart_getchar(FILE *stream)
{
	while ((UCSR0A & (1 << RXC0)) == 0) {}; // Do nothing until data have been received and is ready to be read from UDR
	return UDR0; // Fetch the received byte value into the variable "ByteReceived"
}

void setLED(int on)
{
	if(on>0)
	{
		PORTB |= 1 << PORTB0;
	}
	else
	{
		PORTB &= ~( 1 << PORTB0 );
	}
}
