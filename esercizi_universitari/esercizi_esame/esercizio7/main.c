#include <stdio.h>

//#define DEBUG

int trovaPeriodo(char array[]);

int main()
{
	int periodo;
	periodo = trovaPeriodo("quipartepartepar");
	printf("Il periodo è: %d\n", periodo);
	//periodo = trovaPeriodo("parteeeeeeeee");
	//printf("Il periodo è: %d\n", periodo);

	return 0;
}

int trovaPeriodo(char array[])
{
	int lunghezza;
	int cursorePrimo, cursoreSecondo, cursoreFine;
	int offset;
	int periodo;
	int periodoTrovato;

	lunghezza = 0;
	while ( array[lunghezza] != '\0' )
		lunghezza++;


	cursorePrimo = 0;
	while ( cursorePrimo < lunghezza - 1 )
	{
		periodo = 0;
		cursoreSecondo = cursorePrimo + 1;
		while ( cursoreSecondo < lunghezza )
		{
			periodoTrovato = 0;
			#ifdef DEBUG
			printf("Cursore primo %d | Cursore secondo %d\n", cursorePrimo, cursoreSecondo);
			#endif
			if ( array[cursorePrimo] == array[cursoreSecondo] )
			{
				#ifdef DEBUG
				printf("Carattere comune: %c\n", array[cursorePrimo]);
				#endif
				periodoTrovato = 1;
				periodo = cursoreSecondo - cursorePrimo;
				offset = 1;
				while ( offset < periodo && periodoTrovato == 1 )
				{
					if ( array[cursorePrimo] != array[cursoreSecondo] ) periodoTrovato = 0;
					offset++;
				}

				if ( periodoTrovato == 1 )
				{
					#ifdef DEBUG
					printf("2 ripetizioni trovate\n");
					#endif
					offset = 0;
					cursoreFine = cursoreSecondo + periodo;
					while ( cursoreFine < lunghezza )
					{
						if ( array[cursoreFine] != array[cursorePrimo + offset] ) periodoTrovato = 0;
						cursoreFine++;
						offset++;
						if ( offset == periodo ) offset = 0;
					}
				}
			}
			if ( periodoTrovato == 1 )
			{
				printf("La sequenza periodica è: ");
				offset = 0;
				while ( offset < periodo )
				{
					printf("%c", array[cursorePrimo + offset]);
					offset++;
				}
				printf("\n");
				return periodo;
			}
			cursoreSecondo++;
		}
		cursorePrimo++;
	}

	return 0;
}




