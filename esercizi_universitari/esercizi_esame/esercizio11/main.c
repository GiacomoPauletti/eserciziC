#include <stdio.h>

#define L 15

typedef int Piano[L][L];

void stampaPiano(Piano piano);

void svuotaPiano(Piano piano);

void attraversaCelle(Piano piano, float m);

int main()
{
	Piano piano;

	svuotaPiano(piano);
	stampaPiano(piano);
	printf("\n\n");
	attraversaCelle(piano, 1.5);
	stampaPiano(piano);

	return 0;
}

void attraversaCelle(Piano piano, float m)
{
	int currX;
	int prevY, roundedCurrY;
	float currY;
	int cursorY;

	prevY = 0;
	for ( currX = 0; currX < L && prevY < L; currX++ )
	{
		currY = m * (float) (currX + 1);

		roundedCurrY = (int) currY;

		for ( cursorY = prevY; cursorY < roundedCurrY; cursorY++)
		{
			//printf("(x,y): (%d , %d)\n", currX, cursorY);	
		   	piano[cursorY][currX] = 1;	
		}

		/*if ( currY - (float) roundedCurrY > 0.0 )
		{
			printf("Fixing\n");
			printf("(x,y): (%d , %d)\n", currX, roundedCurrY);	
			printf("End of fix\n");
			piano[currX][roundedCurrY] = 1;
		}*/
		
		prevY = roundedCurrY;
	}

}

void svuotaPiano(Piano piano)
{
	int cursorX, cursorY;
	for ( cursorY = 0; cursorY < L; cursorY++ )
		for ( cursorX = 0; cursorX < L; cursorX++ )
			piano[cursorY][cursorX] = 0;
}

void stampaPiano(Piano piano)
{
	int cursorX, cursorY;
	for ( cursorY = L - 1; cursorY >= 0; cursorY-- )
	{
		printf("\t");
		for ( cursorX = 0; cursorX < L; cursorX++ )
		{
			printf("%d\t", piano[cursorY][cursorX]);
		}
		printf("\n");

	}
	printf("\n");
}
