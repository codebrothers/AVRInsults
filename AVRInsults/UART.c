
#include "UART.h"
#include <util/setbaud.h>
#include <stdio.h>
#include <avr/io.h>

// Private headers

void uart_putchar(char c, FILE *stream);
char uart_getchar(FILE *stream);


// Implementation

void initStdInOutUart()
{
	FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
	FILE uart_input  = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);

	stdout = &uart_output;
	stdin  = &uart_input;

	UCSR0B = (1 << RXEN0)  | (1 << TXEN0);  // Turn on the transmission and reception circuitry
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01); // Use 8-bit character sizes

	UBRR0H = (BAUD_PRESCALE >> 8);
	UBRR0L =  BAUD_PRESCALE;
}

void uart_putchar(char c, FILE *stream)
{
	while ((UCSR0A & (1 << UDRE0)) == 0) {};
	UDR0 = c;
}

char uart_getchar(FILE *stream)
{
	while ((UCSR0A & (1 << RXC0)) == 0) {};
	return UDR0;
}
