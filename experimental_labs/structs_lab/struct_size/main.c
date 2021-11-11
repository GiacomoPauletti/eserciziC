#include <stdio.h>

/* 
 * Lo scopo di questo codice è quello di verificare le dimensioni di una struttura che
 * contiene elementi per un totale di 6 bytes.
 * 
 * Il risultato è che la dimensione è 8 bytes, perchè i 2 caratteri vengono "allineati" 
 * all'intero, cioè visto che occupano solo metà di una word (che è fatta di 4 bytes) allora i
 * restanti 2 bytes vengono inclusi anche essi, per avere una word completa.
 * Questo perchè il processore non legge 1 byte alla volta, nemmeno 1 bit alla volta, ma un 
 * insieme di bytes, appunto 4 bytes, 1 parola.
 * 
 * Questo codice invia lo stesso output su processori a 32 bit e 64 bit ma per 2 ragioni diverse:
 * 	- a 32 bit si vanno a formare 2 parole da 4 bytes
 * 	- a 64 bit si va a formare 1 sola parola da 8 bytes.
 * Il risultato complessivo rimane 8
 *
 * In teoria si dovrebbe vedere che le 2 CPU funzionano in modo diverso se creaiamo una 2 struttura con un
 * campo in più, char d. La struttura avrà dimensioni:
 * 	- 12 bytes (3 words) su una CPU a 32 bit 
 *	- 16 bytes (2 words) su una CPU a 64 bit
 * Per qualche ragione questo non accade.
 */

struct Example
{
	char a;
	char b;
	int c;
};

struct Example2
{
	char a;
	char b;
	int c;
	char d;
};

int main()
{
	printf("%lu\n", sizeof(struct Example));
	printf("%lu\n", sizeof(struct Example2));
}
