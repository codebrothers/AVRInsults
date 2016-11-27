
#include <stdio.h>
#include <avr/pgmspace.h>
#include <talkie.h>

#include "IO.h"
#include "PWMAudio.h"

void readToken(char target[], int index);

int main (void)
{
	initPwmAudio();

	initStdInOutUart();

	char** strings;
	int stringIndex = 0;
	strings[0] = "%root%";
	const char tokenDelimeter='%';
	int searchOffset = 0;

	while(1)
	{	
		// Retrieve a token string from program space and print it
		/*

		char c = strings[stringIndex][searchOffset];
		do 
		{
			if(c==tokenDelimeter)
			{
				int tokenStartOffset = searchOffset;
				
				do // Get token name
				{
					++searchOffset;
					c = strings[stringIndex][searchOffset];
				}
				while(c!=tokenDelimeter)

				int tokenEndOffset = searchOffset;

				int tokenLength = tokenEndOffset - tokenStartOffset;
				
				char *token = str

				// Get token replacement
				char *tokenReplacement = copyReplacementForToken(  )
				

				// Realloc next string to accomodate token replacement
				
				// Copy in token replacement
				
				
			}
			
			++searchOffset;
		}
		while ( c != 0x00 ); // Reached end of string without token replacement
		
		char aToken[100];
		readToken(aToken,2);
		printf("%s\n", aToken);
		*/
	}
}

void readToken(char target[], int index)
{
	//strcpy_P(target, (PGM_P)pgm_read_word(&(tokenNames[index])));
}
