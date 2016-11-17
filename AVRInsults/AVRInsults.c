
#include "IO.h"
#include "InsultData.h"
#include <stdio.h>
#include <avr/pgmspace.h>

void readToken(char target[], int index);

int main (void)
{
	initStdInOutUart();

	while(1)
	{	
		// Retrieve a token string from program space and print it
		
		char aToken[100];
		readToken(aToken,2);
		printf("%s\n", aToken);
	}
}

void readToken(char target[], int index)
{
	strcpy_P(target, (PGM_P)pgm_read_word(&(tokenNames[index])));
}
