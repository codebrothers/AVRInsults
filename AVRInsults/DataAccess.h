
#include <stdint.h>
#include <stddef.h>

#ifndef DATAACCESS_H_
#define DATAACCESS_H_

#define EXT_MEM_PGMSPACE  0
#define EXT_MEM_SPIEEPROM 1

#define EXT_MEM EXT_MEM_PGMSPACE

typedef uint16_t ADDRESS_E;


// External memory access functions:  These are intended as a level of indirection for AVRInsults
// The could be backed by pgm_space functions to read local data on the AVR, or by appropriate functions to read from an external SPI EEPROM.

void memcpy_E( ADDRESS_E src, char* dst, size_t size ); // Copy an arbitrary number of bytes from the (external) source to the (local) destination
ADDRESS_E ext_read_address( ADDRESS_E address ); // Read an external address from another external address.
char ext_read_byte( ADDRESS_E address ); // Read a single byte at the external address.

#endif /* DATAACCESS_H_ */