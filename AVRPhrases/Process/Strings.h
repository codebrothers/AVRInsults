/*
 * Strings.h
 *
 * Created: 15/12/2016 3:06:51 PM
 *  Author: Chris
 */ 


#ifndef STRINGS_H_
#define STRINGS_H_

#include "Range.h"

void strings_rangeCopy( char* src, Range srcRange, char* dest, int destOffset );
Range strings_getRangeBetweenFirstDelimeterPair( char* string, char delimeter );
char* strings_copyRange( Range range, char* string );

#endif /* STRINGS_H_ */