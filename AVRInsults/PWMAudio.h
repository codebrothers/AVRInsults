/*
 * PWMAudio.h
 *
 * Created: 27/11/2016 12:16:06 PM
 *  Author: Chris
 */ 

 #include "CircularBuffer.h"

#ifndef PWMAUDIO_H_
#define PWMAUDIO_H_

/* Initializes the AVR hardware for PWM Audio output and starts polling the provided circular buffer for sample data. */
void initPwmAudio( CircularBuffer* sampleBuffer );

// TODO: Add ability to start and stop the sample data polling, to save power when no sample data is being provided.

#endif /* PWMAUDIO_H_ */