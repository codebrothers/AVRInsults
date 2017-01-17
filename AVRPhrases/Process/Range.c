/*
 * Range.c
 *
 * Created: 16/12/2016 2:47:20 PM
 *  Author: Chris
 */ 

 #include "Range.h"

 #define NOT_FOUND_RANGE ((Range){-1,-1})

 bool range_isEqual( Range a, Range b)
 {
	 return ( a.start == b.start ) && ( a.length == b.length );
 }

 bool range_isNotFound( Range range )
 {
	 return range_isEqual( range, NOT_FOUND_RANGE );
 }