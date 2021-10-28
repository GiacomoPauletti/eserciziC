#include <stdio.h>

int main()
{
    int input;
    int massimo, minimo;

    massimo = 0;
    minimo = 0;
    input = 0;

    printf("Inserisci un numero della sequenza (0 per terminare): ");
    scanf("%d", &input);
    minimo = input;
    while (input > 0)
    {        
        if (input > massimo) massimo = input;
        else if (input < minimo) minimo = input;

        printf("Inserisci un numero della sequenza (0 per terminare): ");
        scanf("%d", &input);
    }


    if (input < 0) printf("WARNING: non dovresti inserire numeri negativi\n");
    
    if (massimo > 0)
    {
        printf("Valore massimo: %d\n", massimo);
        printf("Valore minimo: %d\n", minimo);
    }
    else printf("Nessun numero inserito\n");
}