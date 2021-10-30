#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <curses.h>

#define LARGHEZZA 7
#define ALTEZZA 6

#define SIMBOLO_VUOTO '.'
#define SIMBOLO_DISCO '#'
#define SIMBOLO_GIOCATORE1 'O'
#define SIMBOLO_GIOCATORE2 'X'

#define MAX_LUNGH_GIOCATORE 15
#define COMANDO_SX_1 'd'
#define COMANDO_DX_1 'f'

#define COMANDO_SX_2 'j'
#define COMANDO_DX_2 'k'

#define COMANDO_INSERISCI ' '


typedef struct {
    char nome[MAX_LUNGH_GIOCATORE];
    int lunghezzaNome;

    char comandoSx;
    char comandoDx;

    char simbolo;
}Giocatore;

typedef struct {
    int x;
    int y;
} Posizione;

void stampaMappa(int mappa[ALTEZZA][LARGHEZZA]);
/* funzione che mostra ai giocatori la mappa formattata con con i relativi simboli */


void prendiNome(Giocatore *giocatore);

Posizione turnoGioco(int mappa[ALTEZZA][LARGHEZZA], Giocatore *giocatore);
/* funzione che esegue un turno di gioco */

int controllaVittoria(int mappa[ALTEZZA][LARGHEZZA], Posizione ultimaPosizioneDisco);

int main(){
    int mappa[ALTEZZA][LARGHEZZA];
    /* mappa di gioco */

    int partitaTerminata;

    int cursoreX;
    /* variabile usata per scorrere attraverso gli elementi di una riga */
    int cursoreY;
    /* variabile usata per scorrere attraverso le righe */

    Giocatore giocatore1;
    Giocatore giocatore2;
    Giocatore *giocatoreCorrente;

    char carattereTemporaneo;
    int ultimoElemento;

    Posizione ultimaPosizioneDisco;
    /* mappa di gioco riempita di spazi vuoti (nessun giocatore ha ancora posizionato nulla) */
    for (cursoreY = 0; cursoreY < ALTEZZA; cursoreY++)
        for (cursoreX = 0; cursoreX < LARGHEZZA ; cursoreX++)
            mappa[cursoreY][cursoreX] = SIMBOLO_VUOTO;

    system("cls");
    printf("\n\
========================================================================================================\n");
    printf("\n\
\t\t8888888888  .d88888b.  8888888b.  8888888888P        d8888           d8888  \n \
\t\t888        d88P\" \"Y88b 888   Y88b       d88P        d88888          d8P888  \n \
\t\t888        888     888 888    888      d88P        d88P888         d8P 888  \n \
\t\t8888888    888     888 888   d88P     d88P        d88P 888        d8P  888  \n \
\t\t888        888     888 8888888P\"     d88P        d88P  888       d88   888  \n \
\t\t888        888     888 888 T88b     d88P        d88P   888       8888888888 \n \
\t\t888        Y88b. .d88P 888  T88b   d88P        d8888888888             888  \n \
\t\t888         \"Y88888P\"  888   T88b d8888888888 d88P     888             888  \n \
    \n");

    printf("\
========================================================================================================\n");

    printf("\t\t\t\t\tBenvenuti in FORZA 4!!\n");
    printf("\t\tIn questo gioco l'obiettivo è riuscire a disporre 4 dischi consecutivamente,\
            \t\t\t\tcioè verticalmente, orizzontalmente o diagonalmente\n\n\n");
    printf("\t\t\t\tOra è il momento di scegliere i vostri nomi!\n\n");

    printf("Giocatore 1, inserisci il tuo nome: ");
    prendiNome(&giocatore1);
    giocatore1.comandoSx = COMANDO_SX_1;
    giocatore1.comandoDx = COMANDO_DX_1;

    giocatore1.simbolo = SIMBOLO_GIOCATORE1;
    printf("Giocatore 2, inserisci il tuo nome: ");
    prendiNome(&giocatore2);
    giocatore2.comandoSx = COMANDO_SX_2;
    giocatore2.comandoDx = COMANDO_DX_2;

    giocatore2.simbolo = SIMBOLO_GIOCATORE2;

    system("cls");
    printf("\n\t\t\t\t\t    [RULLO DI TAMBURI]\n");
    printf("\t\t\t\t\tCHE LA SFIDA ABBIA INIZIO\n");
    printf("\t\t\t\t    Premere invio se volete vincere ");
    scanf("%*c");

    giocatoreCorrente = &giocatore1;

    partitaTerminata = 0;
    while ( partitaTerminata == 0 )
    {
        ultimaPosizioneDisco = turnoGioco(mappa, giocatoreCorrente);

        partitaTerminata = controllaVittoria(mappa, ultimaPosizioneDisco);

        if (giocatoreCorrente -> nome == giocatore1.nome)
            giocatoreCorrente = &giocatore2;
        else
            giocatoreCorrente = &giocatore1;
    }

    if (giocatoreCorrente -> nome == giocatore1.nome)
        giocatoreCorrente = &giocatore2;
    else
        giocatoreCorrente = &giocatore1;
    system("cls");
    printf("\n\t\t\t   La partita è finitaaaa. Ha vinto %s\n\n", giocatoreCorrente -> nome);

    stampaMappa(mappa);
}

void stampaMappa(int mappa[ALTEZZA][LARGHEZZA])
{
    int cursoreX;
    /* variabile usata per scorrere attraverso gli elementi di una riga */
    int cursoreY;
    /* variabile usata per scorrere attraverso le righe */


    for (cursoreY = 0; cursoreY < ALTEZZA; cursoreY++){
        printf("\t\t   ");
        for (cursoreX = 0; cursoreX < LARGHEZZA ; cursoreX++)
            printf("\t%c", mappa[cursoreY][cursoreX]);
        printf("\n\n");
    }
    printf("\n");
}


void prendiNome(Giocatore *giocatore){
    int carattereTemp;

    giocatore -> lunghezzaNome = 0;

    carattereTemp = getchar();
    while (giocatore -> lunghezzaNome < MAX_LUNGH_GIOCATORE - 1 && carattereTemp != '\n' ){
        giocatore -> nome[giocatore -> lunghezzaNome] = carattereTemp;
        (giocatore -> lunghezzaNome)++;
        carattereTemp = getchar();
    }

    giocatore -> nome[giocatore -> lunghezzaNome] = '\0';

}

Posizione turnoGioco(int mappa[ALTEZZA][LARGHEZZA], Giocatore *giocatore)
{
    char inputGiocatore;

    Posizione posizioneDisco;

    int cursoreDiscoX;
    /* variabile usata per scorrere fino alla posizione X del disco per stamparlo a video*/


    posizioneDisco.x = LARGHEZZA / 2;
    system("cls");
    printf("\n%s è il tuo turno\n", giocatore -> nome);
    printf("I tuoi comandi sono '%c' per muovere a sx, '%c' per muovere a dx e '%c' per inserire\n",
    giocatore -> comandoSx, giocatore -> comandoDx, COMANDO_INSERISCI);
    printf("Premi invio per incominciare");
    scanf("%*c");

    system("cls");
    printf("\n\n");

    printf("\t\t   ");
    for (cursoreDiscoX = 0; cursoreDiscoX < posizioneDisco.x; cursoreDiscoX++)
        printf("\t");

    printf("\t%c\n", SIMBOLO_DISCO);

    stampaMappa(mappa);

    printf("\n%s, fai la tua mossa -> ", giocatore -> nome);
    //scanf("%c", &inputGiocatore);
    inputGiocatore = getch();
    /* viene chiesto all'utente di muovere il disco finchè non lo inserisce. Se viene inserito il
     * disco tuttavia, ciò avviene veramente soltanto se l'elemento sottostante non è già occupato,
     * altrimenti ritorna a chiedere l'input all'utente */
    while ( ( inputGiocatore != COMANDO_INSERISCI ) || ( mappa[0][posizioneDisco.x] != SIMBOLO_VUOTO ))
    {
        if ( ( inputGiocatore == giocatore -> comandoSx ) && ( posizioneDisco.x > 0 ) )
        {
            posizioneDisco.x--;
        }else if ( ( inputGiocatore == giocatore -> comandoDx ) && ( posizioneDisco.x < LARGHEZZA - 1 ) )
            posizioneDisco.x++;

        system("cls");
        printf("\n\n");
        printf("\t\t   ");
        for (cursoreDiscoX = 0; cursoreDiscoX < posizioneDisco.x; cursoreDiscoX++)
            printf("\t");

        printf("\t%c\n", SIMBOLO_DISCO);

        stampaMappa(mappa);

        printf("\n%s, fai la tua mossa -> ", giocatore -> nome);
        //scanf("%*c%c", &inputGiocatore);
        inputGiocatore = getch();
    }

    /* il disco viene posizionato */
    posizioneDisco.y = 0;
    while ( ( posizioneDisco.y < ALTEZZA - 1 ) && ( mappa[posizioneDisco.y + 1][posizioneDisco.x]  == SIMBOLO_VUOTO ) )
    {
        posizioneDisco.y++;
    }
    mappa[posizioneDisco.y][posizioneDisco.x] = giocatore -> simbolo;



    return  posizioneDisco;
}

int controllaVittoria(int mappa[ALTEZZA][LARGHEZZA], Posizione ultimaPosizioneDisco)
{
    int cursoreX, cursoreY;
    int contatoreSequenza;
    int passoX, passoY;

    int sequenzaCompleta;

    char simboloGiocatore;

    sequenzaCompleta = 0;
    simboloGiocatore = mappa[ultimaPosizioneDisco.y][ultimaPosizioneDisco.x];

    for (cursoreY = -1; cursoreY <= 1; cursoreY++ )
    {
        for (cursoreX = -1; cursoreX <= 1; cursoreX++ )
        {
            passoX = cursoreX;
            passoY = cursoreY;
            if ( ( ultimaPosizioneDisco.x + cursoreX < 0) || ( ultimaPosizioneDisco.x + cursoreX > LARGHEZZA - 1 ) )
                passoX = 0;

            if ( ( ultimaPosizioneDisco.y + cursoreY < 0) || ( ultimaPosizioneDisco.y + cursoreY > ALTEZZA - 1 ) )
                passoY = 0;


            if ( ( passoX != 0 ) || ( passoY != 0 ) )
            {
                contatoreSequenza = 1;
                while ( ( contatoreSequenza < 4 ) &&
                        ( mappa[ultimaPosizioneDisco.y + passoY][ultimaPosizioneDisco.x + passoX] == simboloGiocatore) )
                {
                    passoX += cursoreX;
                    passoY += cursoreY;
                    contatoreSequenza++;
                }
                passoX = -1 * cursoreX;
                passoY = -1 * cursoreY;

                while ( ( contatoreSequenza < 4 ) &&
                        ( mappa[ultimaPosizioneDisco.y + passoY][ultimaPosizioneDisco.x + passoX] == simboloGiocatore) )
                {
                    passoX -= cursoreX;
                    passoY -= cursoreY;
                    contatoreSequenza++;
                }

                if (contatoreSequenza == 4)
                {
                    sequenzaCompleta = 1;
                    return 1;
                }

            }
        }
    }

    return 0;
}
