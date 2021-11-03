#include <stdio.h>

#define DIM_PAROLA 35
#define DIM_DIZIONARIO 5
/* a dire il vero dizionario contiene 100.000 elementi, ma per semplicita 
 * di creazione del codice per ora ce ne sono soltanto 5 */



int EsisteParola(char* parola, char dizionario[][DIM_PAROLA]);
/* funzione che ritorna 1 se la parola è presente nel dizionario, 
 * altrimenti ritorna 0 */

int DistanzaParole(char* parola1, char* parola2);
/* funzione che ritorna la distanza tra parola.
 * N.B: la distanza tra parole è la somma tra le distanze nell'alfabeto 
 * delle lettere con lo stesso index nelle due parole.
 * Se una parola ha più lettere dell'altra, allora per ogni lettera in più
 * si aggiunge 26 alla distanza tra parole */

char* SuggerimentoParola(char* parola, char dizionario[][DIM_PAROLA]);
/* funzione che ritorna la parola che si trova nel dizionario passato 
 * con la minore distanza dalla parola passata */

int main()
{
    char dizionario[DIM_DIZIONARIO][DIM_PAROLA];
    int cursoreDizionario;
    int cursoreParola;

    char* parolaNuova;
    int esisteParola;

    for (cursoreDizionario = 0; cursoreDizionario < DIM_DIZIONARIO; cursoreDizionario++)
    {
        printf("Inserisci la parola %d su %d [max %d lettere] -> ", cursoreDizionario + 1, DIM_DIZIONARIO, DIM_PAROLA - 1);

        scanf("%s", dizionario[cursoreDizionario]);

    }

    parolaNuova = "casa";

    esisteParola = EsisteParola(parolaNuova, dizionario);
    if (esisteParola) printf("La parola esiste nel dizionario\n");
    else
    {
        printf("La parola non esiste nel dizionario\n");
        printf("SUGGERIMENTO: forse intendevi %s\n", SuggerimentoParola(parolaNuova, dizionario));
    }

    printf("\nLa distanza tra %s e %s è di %d \n", dizionario[1], dizionario[2], DistanzaParole(dizionario[1], dizionario[2]));
}

int EsisteParola(char* parola, char dizionario[][DIM_PAROLA])
{
    int cursoreParola;
    int cursoreDizionario;

    int trovata;
    
    trovata = 0;
    for (cursoreDizionario = 0; cursoreDizionario < DIM_DIZIONARIO && trovata == 0; cursoreDizionario++)
    {
        cursoreParola = 0;
        while (dizionario[cursoreDizionario][cursoreParola] != '\0' 
        && parola[cursoreParola] != '\0'
        && parola[cursoreParola] == dizionario[cursoreDizionario][cursoreParola])
        {
            cursoreParola++;
        }

        if (parola[cursoreParola] == '\0' && dizionario[cursoreDizionario][cursoreParola] == '\0') trovata = 1;

    }

    return trovata;
}

int DistanzaParole(char *parola1, char *parola2)
{

    int cursoreParola;
    int sommaDistanze;

    sommaDistanze = 0;
    cursoreParola = 0;
    for (cursoreParola = 0; parola1[cursoreParola] != '\0' && parola2[cursoreParola] != '\0'; cursoreParola++)
    {
        if (parola1[cursoreParola] > parola2[cursoreParola]) sommaDistanze += (int) parola1[cursoreParola] - parola2[cursoreParola];
        else sommaDistanze += (int) parola2[cursoreParola] - parola1[cursoreParola];
    }

    while (parola1[cursoreParola] != '\0')
    {
        sommaDistanze += 26;
        cursoreParola++;
    }

    while (parola2[cursoreParola] != '\0')
    {
        sommaDistanze += 26;
        cursoreParola++;
    }

    return sommaDistanze;
}

char* SuggerimentoParola(char* parola, char dizionario[][DIM_PAROLA])
{
    int cursoreDizionario;
    int distanzaMinima;
    int distanzaCorrente;
    char* parolaPiuVicina;

    distanzaMinima = DistanzaParole(parola, dizionario[0]);
    parolaPiuVicina = dizionario[0];
    for (cursoreDizionario = 1; cursoreDizionario < DIM_DIZIONARIO; cursoreDizionario++)
    {
        distanzaCorrente = DistanzaParole(parola, dizionario[cursoreDizionario]);
        if (distanzaMinima > distanzaCorrente)
        {
            distanzaMinima = distanzaCorrente;
            parolaPiuVicina = dizionario[cursoreDizionario];
        }
    }
    return parolaPiuVicina;
}