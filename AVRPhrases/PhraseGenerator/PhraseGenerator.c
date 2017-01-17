/*
 * PhraseGenerator.c
 *
 * Created: 15/12/2016 2:20:12 PM
 *  Author: Chris
 */ 

 #include "PhraseGenerator.h"

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../Process/Strings.h"
#include "PhraseData/PhraseDataAccess.h"

// Implementation

char tokenDelimeter = '%';

char* phraseGenerator_createPhrase()
{
	// Identify range of first token
	char* phrase = "%phrase%";
	int phraseLength = strlen(phrase);

	Range tokenRange;
	
	while( !range_isNotFound( tokenRange = strings_getRangeBetweenFirstDelimeterPair( phrase, tokenDelimeter ) ) )
	{
		char *token = strings_copyRange( tokenRange, phrase );
		char *tokenReplacement = phraseDataAccess_copyRandomTokenReplacement(token);

		if(tokenReplacement == NULL) 
		{
			free(token);
			break;
		}

		int tokenReplacementLength = strlen(tokenReplacement);

		int nextPhraseLength = phraseLength - (tokenRange.length+2) + tokenReplacementLength;
		char *nextPhrase = calloc( nextPhraseLength, sizeof(char) );

		int replacementStart = tokenRange.start - 1;
		int replacementEnd   = replacementStart + tokenReplacementLength;

		for(int i=0; i<nextPhraseLength; ++i )
		{
			char c;
			if( i == (nextPhraseLength - 1) )
			{
				c = '\0';
			}
			if( i < replacementStart )
			{
				c = phrase[i];
			}
			else if( i < replacementEnd )
			{
				c = tokenReplacement[i - replacementStart];
			}
			else
			{
				c = phrase[i - replacementEnd];
			}
			nextPhrase[i] = c;
		}

		free(token);
		free(phrase);

		phrase       = nextPhrase;
		phraseLength = nextPhraseLength;
	}

	return phrase;
}


