#include <stdio.h>

/* Il codice ha come obiettivo verificare come agisce il compilatore in caso di un assegnamento ambiguo.
 * In questo caso infatti pongo giorno = gio ma gio può essere sia uno dei valori assumibili da GiornoSettimana
 * sia la variabile precedentemente creata gio 
 *
 * RISULTATO:
 * il risultato è che viene assegnata la variabile gio precedentemente definita
 * In questo caso non da errori perchè essendo gio intera ed essendo che ad ogni valore di enum il compilatore assegna un numero a partire da 0, si ottiene che giorno è come se valesse lun (perchè a lun corrisponde 0)
 */

typedef enum {lun, mar, mer, gio, ven, sab, dom} GiornoSettimana;

int main()
{
	GiornoSettimana giorno;
	int gio = 0;
	giorno = gio;

	if (giorno == 0) printf("A giorno è stata assegnata la variabile gio precedentemente dichiarata\n");
	else if (giorno == 3) printf("A giorno è stato assegnato il valore gio, compreso tra quelli che \
una variabile di tipo Giorno settimana può assumere\n");
	else printf("A giorno è stato assegnato un altro valore\n");

	GiornoSettimana giorno2;
	giorno2 = ven;
	
	if (giorno2 == 4) printf("A giorno2 è stato assegnato 'ven' correttamente\n");
	else printf("A giorno2 non è stato assegnato 'ven' correttamente\n");
}
