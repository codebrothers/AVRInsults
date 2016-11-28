/*
 * CircularBuffer.h
 *
 * Created: 28/11/2016 10:15:48 PM
 *  Author: Chris
 */ 


#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#include <stdint.h>
#include <stdbool.h>

 typedef struct CircularBuffer
 {
	 uint8_t* bytes;
	 uint16_t size;
	 uint16_t writeOffset;
	 uint16_t readOffset;
	 bool isFull;
 }
 CircularBuffer;

 CircularBuffer* circularBuffer_create( uint16_t byteCount );

 bool circularBuffer_writeByte( CircularBuffer *buffer, uint8_t byte );

 bool circularBuffer_hasBytes( CircularBuffer *buffer );

 bool circularBuffer_readByte( CircularBuffer *buffer, uint8_t *byteOut );

 void circularBuffer_destroy( CircularBuffer *buffer );



#endif /* CIRCULARBUFFER_H_ */