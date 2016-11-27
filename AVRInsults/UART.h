/*
 * Input/Output layer for the AVRInsults device
 *
 * Created: 16/11/2016 9:58:58 PM
 *  Author: Chris
 */ 

#ifndef IO_H_
#define IO_H_

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#ifndef SAMAVR_H_
#define SAMAVR_H_

#define F_CPU 8000000UL
#define BAUD 38400
#define BAUD_PRESCALE (((F_CPU / (BAUD * 16UL))) - 1)

void initStdInOutUart();	// Maps the C-library standard Input/Output streams to the AVR's UART, currently 'wait' and not interupt-based.

#endif /* SAMAVR_H_ */

