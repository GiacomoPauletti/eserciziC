#include <stdio.h>

#define LENGTH 10000

int sameStart(char text[LENGTH]);

int sameStart(char text[LENGTH])
{
	int index;
	char beginningChar;
	int isFirstChar;	
	/* tells whether the current char might be the first char of the next word */
	

	index = 0;
	while ( index < LENGTH && text[index] != '\0' && ( text[index] < 'a' || text[index] > 'z' ) )
	{
		index++;
	}

	//if there is no valid word, 0 will be returned
	if ( index == LENGTH || text[index] == '\0' ) return 0;

	beginningChar = text[index];
	index++;

	isFirstChar = 0;
	while( index < LENGTH && text[index] != '\0' )
	{
		if ( text[index] < 'a' || text[index] > 'z' )
		{
			isFirstChar = 1;
		}
		else 
		{
			if ( isFirstChar && ( text[index] != beginningChar ) ) return 0;
			isFirstChar = 0;	
			index++;
		}
	}

	return 1;
}



