#include <stdio.h>

/* stringa periodica
 *
 * esempi: eccoilperiodoperiodo
 * 	   eccoilperiodoperiodoperi
 * 	   
 * non esempi: eccoilperiodoperi
 * 	       eccoilperiodociaoperiodo
 */

int trovaPeriodo(char array[])
{
	int lunghezza;

	int cursorePrincipale;
	int cursorePeriodo;

	int offset;
	int periodoCorretto;
	int periodoMax, periodoCur;
	
	int periodoTrovato;

	/* calcolo della lunghezza della stringa */
	lunghezza = 0;
	while ( array[lunghezza] != '\0' )
		lunghezza++;

	printf("La lunghezza è: %d\n", lunghezza);
	periodoMax = periodoCur = 0;
	cursorePrincipale = lunghezza - 2;
	periodoTrovato = 0;
	while ( cursorePrincipale >= lunghezza / 2 && periodoTrovato == 0 )
	{
		cursorePeriodo = lunghezza - 1;
		while ( cursorePeriodo > cursorePrincipale && periodoTrovato == 0)
		{
			periodoCur = cursorePeriodo - cursorePrincipale;
			printf("cursorePeriodo %d e cursorePrincipale %d\n", cursorePeriodo, cursorePrincipale);

			if ( array[cursorePeriodo] == array[cursorePrincipale] )
			{
				printf("2 caratteri uguali trovati (%c) con periodo %d\n", array[cursorePrincipale], periodoCur);
				periodoCorretto = 1;
				offset = 1; 
				while ( offset < periodoCur && periodoCorretto == 1)
				{
					printf("%d | %d\n", cursorePeriodo - offset, cursorePrincipale - offset);
					if ( array[cursorePeriodo - offset] != array[cursorePrincipale - offset] )
						periodoCorretto = 0;

					offset++;
				}

				if ( periodoCorretto == 1)
				{
					printf("Periodo corretto!!\n");
					periodoMax = periodoCur;
					periodoTrovato = 1;
				}
			}
			cursorePeriodo--;

		}

		if ( periodoCorretto == 1 && cursorePeriodo + periodoMax >= lunghezza )
		{
			cursorePeriodo++; // per via del cursorePeriodo-- di prima
			offset = 1;

			while ( offset <= periodoMax && cursorePeriodo + offset < lunghezza && periodoCorretto == 1 )
			{
				printf("Guardando all'index: %d\n", cursorePeriodo + offset);
				if ( array[cursorePeriodo + offset] != array[cursorePrincipale + offset] )
				{
					periodoCorretto = 0;
					periodoTrovato = 0;
				}
			}
			offset++;
		}

		if ( periodoCorretto == 1 )
		{
			printf("La sequenza periodica è: ");

			for ( offset = 1; offset <= periodoMax; offset++ )
			{
				printf("%c", array[cursorePrincipale + offset]);
			}

			printf("\n");

			return periodoMax;
		}

		cursorePrincipale--;
	}

	
	return 0;
}

int main()
{

	trovaPeriodo("quipartepartepar");

	return 0;
}

