/*
 * PhraseDataAccess.c
 *
 * Created: 15/12/2016 8:16:53 PM
 *  Author: Chris
 */ 

 #include <avr/pgmspace.h>
 #include <stdbool.h>
 #include <string.h>
 #include <stdlib.h>

 #include "PhraseDataAccess.h"
 #include "PhraseData_PgmSpace.h"
 #include "TokenPhrases.h"

 // Private headers

 void readTokenPhrases( const TokenPhrases *srcPgmSpacePtr, TokenPhrases *destPtr );


 // Implementation

 char* phraseDataAccess_copyRandomTokenReplacement( char* token )
 {
	TokenPhrases tokenPhrases;
	size_t size = sizeof(tokenPhrasesList) / sizeof(TokenPhrases);
	bool found = false;
	for( int i = 0; i < size; ++i )
	{
		readTokenPhrases( &(tokenPhrasesList[i]), &tokenPhrases );
		char* tokenPhrasesToken = tokenPhrases_copyToken( tokenPhrases );
		if( strcmp( token, tokenPhrasesToken ) == 0 )
		{
			free(tokenPhrasesToken);
			found = true;
			break;
		}
		free(tokenPhrasesToken);
	}

	if(found)
	{
		int max = tokenPhrases_getPhraseCount(tokenPhrases);
		int tokenReplacementIndex = div( rand(), max ).rem;
		char* replacement = tokenPhrases_copyPhraseAtIndex( tokenPhrases, tokenReplacementIndex );
		return replacement;
	}
	else
	{
		return NULL;
	}
 }

  void readTokenPhrases( const TokenPhrases *srcPgmSpacePtr, TokenPhrases *destPtr )
  {
	  size_t size = sizeof(TokenPhrases);
	  memcpy_P(destPtr, srcPgmSpacePtr, size);
  }
