/*
 * PhraseData_PgmSpace.h
 *
 * Created: 15/12/2016 8:20:36 PM
 *  Author: Chris
 */ 

#ifndef PHRASEDATA_PGMSPACE_H_
#define PHRASEDATA_PGMSPACE_H_

#include <avr/pgmspace.h>
#include "TokenPhrases.h"

#define SIZEOF_PHRASES(P) (uint8_t)sizeof(P)/sizeof(PROGMEM char*)

const char phrases_phrase_01[] PROGMEM = "Hello %derog%, how are you?";
const char phrases_phrase_02[] PROGMEM = "%derog%! LOL";

const char* const phrases_phrase[] PROGMEM =
{
	phrases_phrase_01,
	phrases_phrase_02
};

const char phrases_derog_01[] PROGMEM = "stupid";
const char phrases_derog_02[] PROGMEM = "nincompoop";

const char * const phrases_derog[] PROGMEM =
{
	phrases_derog_01,
	phrases_derog_02
};

const char tokenPhraseList_token_01[] PROGMEM = "phrase";
const char tokenPhraseList_token_02[] PROGMEM = "derog";

static const TokenPhrases const tokenPhrasesList[] PROGMEM =
{ 
	{ tokenPhraseList_token_01, SIZEOF_PHRASES(phrases_phrase), phrases_phrase }//,
	//{ tokenPhraseList_token_02, SIZEOF_PHRASES(phrases_derog),  phrases_derog  }
};

#endif /* PHRASEDATA_PGMSPACE_H_ */