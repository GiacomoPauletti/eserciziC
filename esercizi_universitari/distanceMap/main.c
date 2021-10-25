
#include <stdio.h>
#include <stdlib.h>

#define ALTEZZA_MAPPA 13
#define LARGHEZZA_MAPPA 13
/* altezza larghezza della mappa */

#define MAX_POSIZIONI_SPECIALI 15
/* lunghezza dell'array contenuta nella struttura di tipo "Posizioni".
 * Specifica il numero massimo di posizioni speciali (come mete o ostacoli)
 * che ci possono essere nell'array */

#define MAX_OSTACOLI 10
#define MIN_OSTACOLI 0
/* numero massimo e minimo di ostacoli che l'utente può scegliere */

#define MAX_METE 4
#define MIN_METE 1
/* numero massimo e minimo di mete che l'utente può scegliere */

#define SIMBOLO_OSTACOLI 100
/* simbolo che viene inserito nella mappa a rappresentare l'ostacolo.
 * N.B: il simbolo deve essere NUMERICO altrimenti il programma rischia di non funzionare
 * N.B: il simbolo deve essere maggiore di SIMBOLO_METE perchè il programma funzioni 
 * correttamente*/

#define SIMBOLO_METE 0
/* simbolo che viene inserito nella mappa a rappresentare le posizioni da raggiungere, cioè
 * le mete.
 * N.B: il simbolo deve essere NUMERICO altrimenti il programma rischia di non funzionare */

#define SIMBOLO_VUOTO -1
/* simbolo che viene inserito nella mappa a rappresentare le posizioni non riempite o
 * irraggiungibili.
 * N.B: il simbolo deve essere NUMERICO altrimenti il programma rischia di non funzionare 
 * N.B: il simbolo deve essere minore di SIMBOLO_METE perchè il programma funzioni 
 * correttamente*/

#define MAX_PASSI 30
/* numero massimo di passi che possono essere eseguiti prima di raggiungere la meta.
 * Se la meta è più distante, non si raggiungerà la meta.
 * Serve per creare la lista sequenziale contenente i passi */

#define PASSO_SU 'n'       //'↑' 
#define PASSO_DX 'e'
#define PASSO_GIU 's'
#define PASSO_SX 'w'
/* simboli che rappresentano le indicazioni di percorso contenute in Percorso */

typedef struct {
    int x;
    int y;
}Coordinate2D;
/* contiene le coordinate X-Y di una posizione sulla mappa */

typedef struct {
    int numeroPosizioni; 
    Coordinate2D coordinate[MAX_OSTACOLI];
}Posizioni;
/* lista sequenziale usata per contenere le coordinate di ostacoli e di mete inserite 
 * dall'utente */

typedef struct {
    Coordinate2D partenza;
    Coordinate2D arrivo;
    int numeroPassi;
    char passi[MAX_PASSI];
}Percorso;
/* struttura che contiene i dettagli sul percorso. In particolare contiene la lista
 * di passi che sono necessari per compiere il percorso minimo per andare da
 * 'partenza' ad 'arrivo' */

void stampaMappa(int mappa[ALTEZZA_MAPPA][LARGHEZZA_MAPPA]);
/* sottoprogramma che stampa a video la mappa */

void inputPosizioniSpeciali(int mappa[ALTEZZA_MAPPA][LARGHEZZA_MAPPA], 
                            Posizioni posizioni, 
                            int simboloDaInserire,
                            int quantitaMinima, int quantitaMassima);
/* sottoprogramma che riceve in input dall'utente le coordinate di un particolare simbolo 
 * da inserire nella mappa.
 * L'input segue regole specifiche:
 *  -le coordinate devono essere valide (dentro la mappa)
 *  -le coordinate devono seguire il format (x,y) dove x e y sono numeri interi
 *  -l'utente deve inserire almeno 'quantitaMinima' di elementi e alpiù 'quantitaMassima' di elementi
*/

void calcolaPercorsoMinimo(int mappa[ALTEZZA_MAPPA][LARGHEZZA_MAPPA], Coordinate2D partenza);

int main(){
    int mappa[ALTEZZA_MAPPA][LARGHEZZA_MAPPA];
    /* mappa quadrata in cui ogni elemento rappresenta una tappa / un punto del percorso */

    int cursoreY, cursoreX;
    /* variabili che servono per scorrere attraverso la mappa per popolarla o stamparla a 
    video */
    
    Posizioni ostacoli; 
    /* lista sequenziale usata per salvare le coordinate degli ostacoli inserite
     * dall'utente */
    ostacoli.numeroPosizioni = 0;
    
    Posizioni mete; 
    /* lista sequenziale usata per salvare le coordinate delle mete inserite
     * dall'utente */
    mete.numeroPosizioni = 0;

    int modificatoFlag; 
    /* flag che serve per controllare se la mappa delle distanze è stata aggiornata, cioè
     * se sono stati aggiunti elementi più distanti dalla meta rispetto a quelli di prima. */

    int distanzaMassimaParziale;
    /* variabile che indica la distanza massima durante l'aggiornamento della mappa delle
     * distanze. Se un elemento ha questa distanza, si aggiornano i suoi vicini (se sono -1) */

    Coordinate2D partenza;
    /* coordinate del punto di partenza del percorso verso una delle mete (quella più vicina) */


    /*------------------------------------SETUP DELLA MAPPA-------------------------------------*/
    /*ogni posizione della mappa viene impostata a SIMBOLO_VUOTO*/
    for (cursoreY = 0; cursoreY < ALTEZZA_MAPPA; cursoreY++)
        for (cursoreX = 0; cursoreX < LARGHEZZA_MAPPA; cursoreX++)
            mappa[cursoreY][cursoreX] = SIMBOLO_VUOTO;

    /*output grafico della mappa all'utente*/
    printf("Premi invio per iniziare");
    scanf("%*c");
    stampaMappa(mappa);

    /*selezione degli ostacoli da parte dell'utente*/
    printf("\n\n");
    printf("---------------------SELEZIONE DEGLI OSTACOLI---------------------\n");
    printf("Inserisci le coordinate degli ostacoli\n");
    printf("[FORMAT] Il format di input è (x,y) dove x e y sono numeri\n");
    printf("Il numero massimo di ostacoli è:%d \n", MAX_OSTACOLI);
    printf("Se non vuoi inserire più ostacoli, inserisci (-1,-1) \n\n");

    inputPosizioniSpeciali(mappa, ostacoli, SIMBOLO_OSTACOLI ,MIN_OSTACOLI, MAX_OSTACOLI);

    printf("\n\n");
    printf("---------------------SELEZIONE DEGLI METE---------------------\n");
    printf("Inserisci le coordinate degli mete\n");
    printf("[FORMAT] Il format di input è (x,y) dove x e y sono numeri\n");
    printf("Il numero massimo di mete è:%d \n", MAX_METE);
    printf("Se non vuoi inserire più mete, inserisci (-1,-1) \n\n");

    inputPosizioniSpeciali(mappa, mete, SIMBOLO_METE, MIN_METE, MAX_METE);



    /*output grafico della mappa aggiornata all'utente*/
    stampaMappa(mappa);
    printf("\n\nPremi invio per continuare ");
    scanf("%*c%*c");


    /*------------------------------CREAZIONE MAPPA DELLE DISTANZE------------------------------*/
    distanzaMassimaParziale = 0;
    /* Se non sono avvenute modifiche (modificatoFlag = 0) allora la mappa è completa,
     * altrimenti si reitera */
    do{
        /* si guarda elemento per elemento alla ricerca degli elementi con la distanza 
         * maggiore dalla meta fino ad ora */
        modificatoFlag = 0;
        for (cursoreY = 0; cursoreY < ALTEZZA_MAPPA; cursoreY++){
            for (cursoreX = 0; cursoreX < LARGHEZZA_MAPPA; cursoreX++){

                /*soltanto se l'elemento è fra i più distanti dalla meta allora avrà 
                 * potenzialmente dei vicini ancora da "riempire" */
                if (mappa[cursoreY][cursoreX] == distanzaMassimaParziale){
                    if (cursoreX - 1 >= 0 && mappa[cursoreY][cursoreX - 1] == -1)
                        mappa[cursoreY][cursoreX - 1] = distanzaMassimaParziale + 1;
                        modificatoFlag = 1;
                    if (cursoreX + 1 < LARGHEZZA_MAPPA && mappa[cursoreY][cursoreX + 1] == -1)
                        mappa[cursoreY][cursoreX + 1] = distanzaMassimaParziale + 1;
                        modificatoFlag = 1;
                    if (cursoreY - 1 >= 0 && mappa[cursoreY - 1][cursoreX] == -1)
                        mappa[cursoreY - 1][cursoreX] = distanzaMassimaParziale + 1;
                        modificatoFlag = 1;
                    if (cursoreY + 1 < ALTEZZA_MAPPA && mappa[cursoreY + 1][cursoreX] == -1)
                        mappa[cursoreY + 1][cursoreX] = distanzaMassimaParziale + 1;
                        modificatoFlag = 1;
                }

            }
        }
        /* ora tutti gli elementi con distanzaMassimaParziale hanno aggiornato i vicini*/
        distanzaMassimaParziale++;
    }while (modificatoFlag == 1);

    stampaMappa(mappa);

    /*------------------------------CALCOLO PERCORSO PIU' BREVE------------------------------*/

    do{
        printf("\n\nDa che punto vuoi partire?\n");
        printf("[FORMAT] Il format di input è (x,y) dove x e y sono numeri\n");
        scanf("\n(%d,%d)", &(partenza.x), &(partenza.y));
    }while( ( partenza.x < 0 || partenza.x > LARGHEZZA_MAPPA ) || ( partenza.y < 0 || partenza.y > ALTEZZA_MAPPA ) );

    calcolaPercorsoMinimo(mappa, partenza);

}


void stampaMappa(int mappa[ALTEZZA_MAPPA][LARGHEZZA_MAPPA])
{
    system("clear");
    printf("\n----------------------------------------MAPPA ATTUALE----------------------------------------\n");
    int cursoreX, cursoreY;

    /*output grafico della mappa all'utente*/
    printf("  ");
    for (cursoreX = 0; cursoreX < LARGHEZZA_MAPPA; cursoreX++)
        printf("%6dx",cursoreX);
    printf("\n");

    for (cursoreY = 0; cursoreY < ALTEZZA_MAPPA; cursoreY++)
    {
        printf("%2dy",cursoreY);

        for (cursoreX = 0; cursoreX < LARGHEZZA_MAPPA; cursoreX++)
            printf("%6d ", mappa[cursoreY][cursoreX]);
        printf("\n");
    } 



}


void inputPosizioniSpeciali(int mappa[ALTEZZA_MAPPA][LARGHEZZA_MAPPA], 
                            Posizioni posizioni,
                            int simboloDaInserire, 
                            int quantitaMinima, int quantitaMassima)
    {
    int numeroScelte;
    /* variabile che conta quante posizioni (ostacoli o mete) ha inserito l'utente per 
     * vedere se supera la soglia minima definita da MIN_OSTACOLI e MIN_METE */

    Coordinate2D posizioneScelta;
    /* variabile che contiene l'input dell'utente quando inserisce gli ostacoli o le mete */

    int posizioneValidaFlag;
    /* flag su cui verranno salvati gli output delle espressioni di verifica delle 
     * condizioni delle posizioni inserite dall'utente. Se una posizione è fuori dal range
     * della mappa allora posizioneValidaFlag avrà valore 0, altrimenti 1 */

    Coordinate2D posizioneNulla = {-1, -1};
    /* posizone non valida che l'utente può inserire per terminare la fase di input */

    numeroScelte = 0; 
    printf("n°1: ");
    scanf("\n(%d,%d)", &(posizioneScelta.x), &(posizioneScelta.y));
    
    /* loop che arriva fino a MAX_OSTACOLI - 2 (cioè MAX_OSTACOLI - 1 iterazioni anzichè 
     * MAX_OSTACOLI) perchè è già avvenuta una scanf, quindi si fa una volta in meno il ciclo */
    /* la posizioneNulla fa uscire dal ciclo solo se si è superata la soglia di MIN_OSTACOLI*/
    while (  (numeroScelte < quantitaMassima - 1) &&
            ((posizioneScelta.x != posizioneNulla.x || posizioneScelta.y != posizioneNulla.y) 
            || numeroScelte < quantitaMinima))
    {
         
        posizioneValidaFlag = ( ( posizioneScelta.x >= 0 && posizioneScelta.x < LARGHEZZA_MAPPA )
                            && ( posizioneScelta.y >= 0 && posizioneScelta.y < ALTEZZA_MAPPA ) );
        if ( posizioneValidaFlag == 1)
        {
            posizioni.coordinate[posizioni.numeroPosizioni].x = posizioneScelta.x;
            posizioni.coordinate[posizioni.numeroPosizioni].y = posizioneScelta.y;

            mappa[posizioneScelta.y][posizioneScelta.x] = simboloDaInserire;

            posizioni.numeroPosizioni++;
            numeroScelte++;
        }else
            printf("Posizione scelta invalida, è fuori dal range massimo!\n");

        /* essendo i tipi Coordinate2D (contenuti in ostacoli.coordinate) degli array, non
         * si può assegnare direttamente ad essi un altra variabile di tipo Coordinate2D ma si
         * deve assegnare elemento per elemento */

        printf("n°%d: ", numeroScelte + 1);
        scanf("%*c(%d,%d)", &(posizioneScelta.x), &(posizioneScelta.y));
    }

    posizioneValidaFlag = ( ( posizioneScelta.x >= 0 && posizioneScelta.x < LARGHEZZA_MAPPA )
                        && ( posizioneScelta.y >= 0 && posizioneScelta.y < ALTEZZA_MAPPA ) );
    if ( (posizioneScelta.x != posizioneNulla.x && posizioneScelta.y != posizioneNulla.y)  
        && posizioneValidaFlag == 1)
    {
        posizioni.coordinate[posizioni.numeroPosizioni].x = posizioneScelta.x;
        posizioni.coordinate[posizioni.numeroPosizioni].y = posizioneScelta.y;

        mappa[posizioneScelta.y][posizioneScelta.x] = simboloDaInserire;

        posizioni.numeroPosizioni++;
        /* numeroScelte++ omesso perchè non era più significante per il codice */
    }

}

void calcolaPercorsoMinimo(int mappa[ALTEZZA_MAPPA][LARGHEZZA_MAPPA], Coordinate2D partenza)
{

    Percorso percorso;

    int distanzaCorrente;
    /* distanza momentanea durante il percorso tra partenza e meta */

    Coordinate2D posizioneCorrente;
    /* posizione corrente nel percorso */

    percorso.partenza.x = partenza.x;
    percorso.partenza.y = partenza.y;

    percorso.numeroPassi = 0;

    distanzaCorrente = mappa[partenza.y][partenza.x];
    posizioneCorrente.x = partenza.x;
    posizioneCorrente.y = partenza.y;

    while ( distanzaCorrente != 0  && percorso.numeroPassi < MAX_PASSI ){
        if ( ( posizioneCorrente.x - 1 >= 0 ) && ( mappa[posizioneCorrente.y][posizioneCorrente.x - 1]  < distanzaCorrente) )
        {
            percorso.passi[percorso.numeroPassi] = PASSO_SX;
            percorso.numeroPassi++;

            posizioneCorrente.x -= 1;
        }

        else if ( ( posizioneCorrente.x + 1 < LARGHEZZA_MAPPA ) && ( mappa[posizioneCorrente.y][posizioneCorrente.x + 1]  < distanzaCorrente) )
        {
            percorso.passi[percorso.numeroPassi] = PASSO_DX;
            percorso.numeroPassi++;

            posizioneCorrente.x += 1;
        }

        else if ( ( posizioneCorrente.y - 1 >= 0 ) && ( mappa[posizioneCorrente.y - 1][posizioneCorrente.x]  < distanzaCorrente) )
        {
            percorso.passi[percorso.numeroPassi] = PASSO_SU;
            percorso.numeroPassi++;

            posizioneCorrente.y -= 1;
        }

        else if ( ( posizioneCorrente.y + 1 < ALTEZZA_MAPPA ) && ( mappa[posizioneCorrente.y + 1][posizioneCorrente.x]  < distanzaCorrente) )
        {
            percorso.passi[percorso.numeroPassi] = PASSO_GIU;
            percorso.numeroPassi++;

            posizioneCorrente.y += 1;
        }

        distanzaCorrente = mappa[posizioneCorrente.y][posizioneCorrente.x];
    }

    printf("Per arrivare alla meta più vicina devi fare i seguenti passi\n");
    for (int i = 0; i < percorso.numeroPassi; i++){
        printf("\t%d] %c\n", i + 1, percorso.passi[i]);
    }

}


/*MIGLIORAMENTI DA FARE:
 *  -ogni volta che viene inserita una coordinata la mappa viene aggiornata
*/
