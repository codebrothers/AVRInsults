/*
 * TokenPhrases.h
 *
 * Created: 16/12/2016 1:56:38 PM
 *  Author: Chris
 */ 

#ifndef TOKENPHRASES_H_
#define TOKENPHRASES_H_

#include <stdint.h>
#include <avr/pgmspace.h>

 typedef struct TokenPhrases
 {
	 const PGM_P   token;
	 const uint8_t phraseCount;
	 const PGM_P*  phrases;
 }
 TokenPhrases;

 char*   tokenPhrases_copyToken        ( TokenPhrases tokenPhrases );
 uint8_t tokenPhrases_getPhraseCount   ( TokenPhrases tokenPhrases );
 char*   tokenPhrases_copyPhraseAtIndex( TokenPhrases tokenPhrases, uint8_t phraseIndex );

#endif /* TOKENPHRASES_H_ */