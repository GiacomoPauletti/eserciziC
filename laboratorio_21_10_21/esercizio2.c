#include <stdio.h>

int main()
{
    float lato1, lato2, lato3;
    int triangoloCorretto;

    printf("Inserisci la lunghezza del primo lato: ");
    scanf("%f", &lato1);
    printf("Inserisci la lunghezza del secondo lato: ");
    scanf("%f", &lato2);
    printf("Inserisci la lunghezza del terzo lato: ");
    scanf("%f", &lato3);

    triangoloCorretto = 1;
    if ( ( lato1 + lato2 <= lato3 ) || ( lato2 + lato3 <= lato1 ) || (lato3 + lato1 <= lato2 ) )
        triangoloCorretto = 0;

    if (triangoloCorretto == 1)
    {
        if ( ( lato1 == lato2 ) && ( lato2 == lato3 ) )
            printf("Il triangolo è equilatero\n");
        else if ( ( lato1 == lato2 ) || ( lato1 == lato3 ) || ( lato2 == lato3 ))
            printf("Il triangolo è isoscele\n");
        else
            printf("Il triangolo è scaleno\n");
    }
    else
        printf("I lati specificati non possono formare un triangolo\n");

}