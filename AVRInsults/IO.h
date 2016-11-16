/*
 * IO.h
 *
 * Created: 16/11/2016 9:58:58 PM
 *  Author: Chris
 */ 

#ifndef IO_H_
#define IO_H_

#define F_CPU 8000000UL
#define BAUD 38400
#define BAUD_PRESCALE (((F_CPU / (BAUD * 16UL))) - 1)

void setLED(int on);
void initStdInOutUart();

#endif /* IO_H_ */