
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

	UCSR0B = (1 << RXEN0)  | (1 << TXEN0);  // Turn on the transmission and reception circuitry
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01); // Use 8-bit character sizes

	UBRR0H = (BAUD_PRESCALE >> 8);
	UBRR0L =  BAUD_PRESCALE;

	while(1)
	{
		printf("You idiot\n"); // Starting simple: the first insult, issued repeatedly.
	}
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
