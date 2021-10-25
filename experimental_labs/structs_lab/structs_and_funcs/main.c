#include <stdio.h>
#define DIMENSIONE_NOME 10

typedef struct
{
    char nome[DIMENSIONE_NOME];
    void (*metodo)(char nomeCaller[DIMENSIONE_NOME]);

} Classe;

void costruttoreClasse(Classe *A);

void funzione1(char nomeCaller[DIMENSIONE_NOME]);

int main()
{

    Classe A;
    
    costruttoreClasse(&A);

    A.metodo = &funzione1;
    A.metodo(A.nome);
}

void funzione1(char nomeCaller[DIMENSIONE_NOME])
{
    printf("Funzione 1 chiamata da %s\n", nomeCaller);
}

void costruttoreClasse(Classe *A)
{
    int cursore;
    /*variabile usata per selezionare elemento per elemento del campo "nome"
    della classe A*/

    char input;
    /*variabile usata per salvare temporaneamente l'input dell'utente per poi
     * trasferirlo nel campo "nome" della classe A
     */

    printf("\nInserisci il nome della classe lettera per lettera, inserisci # se vuoi terminare: \n");
    printf("MAX LETTERE: %d\n\n", DIMENSIONE_NOME-1);

    printf("-> ");
    scanf("%c", &input);

    /* cursore va fino a DIMENSIONE_NOME - 2 perchè: 
        1) l'ultimo carattere è riservato a \0
        2) non si arriva al penultimo carattere perchè avendo già fatto uno scanf prima del loop
           si deve fare un ciclo in meno (uno scanf in meno).
           La conseguenza di fare un loop in meno è che bisogna aggiungere "manualmente" l'ultimo valore registrato
    */
    

    for ( cursore = 0; cursore < DIMENSIONE_NOME - 2 && input != '#'; cursore++ ){
        A -> nome[cursore] = input;
        printf("-> ");
        scanf("%*c%c", &input);
    }

    if (input != '#'){
        A -> nome[cursore] = input;
        cursore++;
    }

    A -> nome[cursore] = '\0';
}