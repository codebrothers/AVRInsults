/*
 * Input/Output layer for the AVRInsults device
 *
 * Created: 16/11/2016 9:58:58 PM
 *  Author: Chris
 */ 

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#ifndef UART_H_
#define UART_H_

#ifndef F_CPU
#define F_CPU 8000000UL
#endif /* F_CPU */

#define BAUD 9600
#define BAUD_PRESCALE (((F_CPU / (BAUD * 16UL))) - 1)

void uart_init();	// Maps the C-library standard Input/Output streams to the AVR's UART, currently 'wait' and not interupt-based.

void uart_putchar(char c, FILE *stream);
char uart_getchar(FILE *stream);


#endif /* UART_H_ */

