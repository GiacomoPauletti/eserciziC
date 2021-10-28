#include <stdio.h>

/* Siccome quando utilizziamo un array stiamo utilizzando un puntatore al primo elemento dell'array,
 * lo scopo del codice è quello di capire in che posizione della memoria è archiviato tal puntatore
 *
 * RISPOSTA:
 * L'output del codice mostra come l'indirizzo stampato dalle due printf sia il medesimo.
 * Si può quindi affermare che non viene salvato da nessuna parte nella memoria il puntatore, oppure
 * il puntatore è proprio il primo elemento dell'array
 */

int main(){
	int array[3] = {1, 2, 3};

	printf("Posizione dell'array nella memoria: %p\n", array);
	printf("Posizione del puntatore all'array nella memoria: %p\n", &array);
}
