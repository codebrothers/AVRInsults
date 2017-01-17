/*
 * Strings.c
 *
 * Created: 15/12/2016 3:06:18 PM
 *  Author: Chris
 */ 

#include "Strings.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void strings_rangeCopy( char* src, Range srcRange, char* dest, int destOffset )
{
	memcpy( (dest + (destOffset*sizeof(char))), (src + (srcRange.start * sizeof(char))), srcRange.length );
}

 char* strings_copyRange( Range range, char* string )
 {
	char *copiedRange = calloc( range.length + 1, sizeof(char) );
	int srcIndex = range.start;
	int dstIndex = 0;

	while( dstIndex < range.length )
	{
		copiedRange[dstIndex] = string[srcIndex];
		++srcIndex;
		++dstIndex;
	}

	copiedRange[range.length] = '\0';
	return copiedRange;
 }

 Range strings_getRangeBetweenFirstDelimeterPair( char* string, char delimeter )
 {
	 char c;
	 int searchIndex = 0, startIndex, endIndex;

	 if( string[searchIndex] == '\0' ) return notFoundRange;
	 
	 while( (c = string[searchIndex]) != delimeter && (c != '\0') ) ++searchIndex;
	 startIndex = searchIndex;
	 do
	 {
		++searchIndex;
	 }
	 while( (c = string[searchIndex]) != delimeter && (c != '\0') );
	 endIndex = searchIndex;
	 Range range;
	 range.start  = startIndex + 1;
	 range.length = (endIndex - startIndex) - 1;
	 return range;
 }
