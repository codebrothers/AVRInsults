/*
 * Range.h
 *
 * Created: 16/12/2016 2:47:09 PM
 *  Author: Chris
 */ 
 
 #include <stdbool.h>

#ifndef RANGE_H_
#define RANGE_H_

typedef struct Range { int start; int length; } Range;

extern Range notFoundRange;

bool range_isEqual( Range a, Range b);
bool range_isNotFound( Range range );

#endif /* RANGE_H_ */