#include <stdio.h>

#define CAPIENZA 10
#define TERMINATORE '#'

typedef struct 
{
    int n;
    char lista[CAPIENZA];
}TipoL;

void Stampa(TipoL Lista);
char Minimo(TipoL Lista, char soglia);
void EseguiInput (TipoL* Lista);
void Ordina( TipoL* Lista );

int main()
{
    TipoL Lista;
    Lista.n = 0;

    printf("Pronto per iniziare? (puoi inserire al massimo %d caratteri) ", CAPIENZA);
    scanf("%*c");

    EseguiInput(&Lista);

    printf("\nEcco la lista dei caratteri inseriti\n");
    Stampa(Lista);

    if (Lista.n >= 1)
    {
        printf("\nIl carattere più vicino all'inizio dell'alfabeto è: %c\n", Minimo(Lista, '\0'));

        Ordina(&Lista);

        printf("\nQuesta è la lista ordinata\n");
        Stampa(Lista);
    }

}

void EseguiInput ( TipoL* Lista)
{
    char inputUtente;

    int terminato;
    int doppione;

    int cursoreLista;

    terminato = 0;
    do 
    {
        printf("%d] ", Lista -> n + 1);
        scanf("\n%c", &inputUtente);

        if ( inputUtente == TERMINATORE ) terminato = 1;
        else if (inputUtente >= 'a' && inputUtente <= 'z')
        {
            doppione = 0;
            for (cursoreLista = 0; cursoreLista < Lista -> n && doppione == 0; cursoreLista++)
            {
                if ( Lista -> lista[cursoreLista] == inputUtente) doppione = 1;
            }

            if ( doppione == 0)
            {
                Lista -> lista[Lista -> n] = inputUtente;
                Lista -> n++;
            }
        }
        else printf("[WARNING] Il carattere inserito non è valido ed è stato ignorato\n");

    } while ( terminato == 0 && Lista -> n < CAPIENZA );

}

void Stampa( TipoL Lista )
{
    int cursoreLista;

    for (cursoreLista = 0; cursoreLista < Lista.n; cursoreLista++)
    {
        printf("%c ", Lista.lista[cursoreLista]);
    }
    printf("\n");

}

char Minimo( TipoL Lista , char soglia)
{
    int cursoreLista;
    int minimo;

    minimo = TERMINATORE;
    for (cursoreLista = 1; cursoreLista < Lista.n; cursoreLista++)
        if (Lista.lista[cursoreLista] > soglia)
        {
            if ( minimo == TERMINATORE) minimo = Lista.lista[cursoreLista];
            else if ( minimo > Lista.lista[cursoreLista]) minimo = Lista.lista[cursoreLista];

        }

    return minimo;
}

void Ordina( TipoL* Lista )
{
    int temp;
    int minimo;
    int cursorePrinc;
    int cursoreSec;

    minimo = '\0';
    for (cursorePrinc = 0; cursorePrinc < Lista -> n - 1; cursorePrinc++)
    /* il - 1 è dovuto al fatto che quando mi mancherà da ordinare
     * l'ultimo elemento, esso sarà per forza il più grande, quindi
     * sarà già al posto giusto */
    {
        minimo = Minimo(*Lista, minimo);
        for (cursoreSec = cursorePrinc; cursoreSec < Lista -> n &&
        Lista -> lista[cursoreSec] != minimo; cursoreSec++);

        temp = Lista -> lista[cursorePrinc];
        Lista -> lista[cursorePrinc] = Lista -> lista[cursoreSec];
        Lista -> lista[cursoreSec] = temp;
    }
}
