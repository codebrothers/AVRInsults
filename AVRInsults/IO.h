/*
 * Input/Output layer for the AVRInsults device
 *
 * Created: 16/11/2016 9:58:58 PM
 *  Author: Chris
 */ 

#ifndef IO_H_
#define IO_H_

#define F_CPU 8000000UL
#define BAUD 38400
#define BAUD_PRESCALE (((F_CPU / (BAUD * 16UL))) - 1)

typedef uint16_t ADDRESS_E;

void setLED(int on);		// Function to set some indicator LED on the device.  Exact use not yet clear :-)
void initStdInOutUart();	// Maps the C-library standard Input/Output streams to the AVR's UART, currently 'wait' and not interupt-based.


// External memory access functions:  These are intended as a level of indirection for AVRInsults
// The could be backed by pgm_space functions to read local data on the AVR, or by appropriate functions to read from an external SPI EEPROM.

void memcpy_E( ADDRESS_E src, char* dst, size_t size ); // Copy an arbitrary number of bytes from the (external) source to the (local) destination
ADDRESS_E ext_read_address( ADDRESS_E address ); // Read an external address from another external address.
char ext_read_byte( ADDRESS_E address ); // Read a single byte at the external address.

#endif /* IO_H_ */

