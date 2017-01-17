/*
 * TokenPhrases.c
 *
 * Created: 16/12/2016 1:56:25 PM
 *  Author: Chris
 */ 

#include "TokenPhrases.h"
#include <avr/pgmspace.h>
#include <stdlib.h>

char* tokenPhrases_copyToken( TokenPhrases tokenPhrases )
{
	PGM_P tokenAddr = (PGM_P)tokenPhrases.token;
	size_t tokenLength = strlen_P( tokenAddr );		// Get address of string
	char* token = calloc( tokenLength, sizeof(char) );
	strcpy_P( token, tokenAddr );
	return token;
}

uint8_t tokenPhrases_getPhraseCount( TokenPhrases tokenPhrases )
{
	return tokenPhrases.phraseCount;
}

char* tokenPhrases_copyPhraseAtIndex( TokenPhrases tokenPhrases, uint8_t phraseIndex )
{
	PGM_P* phrasesAddr  = tokenPhrases.phrases;
	PGM_P  phraseAddr   = pgm_read_word_near( &(phrasesAddr[0]) );
	size_t phraseLength = strlen_P( phraseAddr );		// Get address of string
	char*  phrase = calloc( phraseLength, sizeof(char) );
	phrase = strcpy_P( phrase, phraseAddr );
	return phrase;
}
