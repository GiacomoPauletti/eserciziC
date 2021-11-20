#include <stdio.h>
#include <stdlib.h>

/*Questo codice ha come scopo investigare i seguenti aspetti:
    1)come vengono salvati i dati (in questo caso gli interi perchè so 
      riconoscere la loro forma binaria) su un file attraverso fwrite?
    2)come bisogna eseguire fread perchè ciò che è stato salvato sul file
      venga successivamente ricaricato su una variabile?
    3)fread muove il puntatore _IO_read_ptr? Oppure bisogna usare fseek?
    4)si può memorizzare una funzione in un file?
    
    Le risposte vengono date vicino alle rispettive sezioni di codice.
*/

#define WRITE_VAR 0
/* macro vuota che viene definita per attivare la parte di lettura e disattivare
 * quella di scrittura per la prima parte, ovvero quella con le variabili*/

#define WRITE_FOO 0

void foo();
/* funzione creata per testare successivamente se è possibile salvare una funzione in un file */

typedef void (*fooType)();

int main()
{
    int i,j;

    fooType readFoo;
    
    #if WRITE_VAR
    FILE* f = fopen("file.txt", "w");
    if ( f != NULL )
    {
        for (i = 0; i < 10; i++)
        {
            fwrite(&i, sizeof(int), 1,  f);
        }

    }
    /*1)come vengono salvati i dati (in questo caso gli interi perchè so 
     *  riconoscere la loro forma binaria) su un file attraverso fwrite?
     *
     * viene aperto un file e vengono salvati i numeri da 0 a 9. Essi vengono scritti
     * consecutivamente nella forma big endian (almeno così li stampa xxd).
     * Eseguendo il comando "xxd -b file.txt" si ottiene il seguente risultato:
     *   00000000: 00000000 00000000 00000000 00000000 00000001 00000000  ......
     *   00000006: 00000000 00000000 00000010 00000000 00000000 00000000  ......
     *   0000000c: 00000011 00000000 00000000 00000000 00000100 00000000  ......
     *   00000012: 00000000 00000000 00000101 00000000 00000000 00000000  ......
     *   00000018: 00000110 00000000 00000000 00000000 00000111 00000000  ......
     *   0000001e: 00000000 00000000 00001000 00000000 00000000 00000000  ......
     *   00000024: 00001001 00000000 00000000 00000000                    ....
     * 
     */

    #else
    FILE* f = fopen("file.txt", "r");
    fread(&i, sizeof(int), 1, f);
    fread(&j, sizeof(int), 1, f);
    printf("i value is: %d\n", i);
    printf("j value is: %d\n", j);

    /*2)come bisogna eseguire fread perchè ciò che è stato salvato sul file
     * venga successivamente ricaricato su una variabile?
     *
     * L'output del seguente codice è:
     *      i value is: 0
     *      j value is: 1
     * 
     * Da ciò si deduce che la sintassi usata è perfettamente funzionante
     * 
     * 3)fread muove il puntatore _IO_read_ptr? Oppure bisogna usare fseek?
     * 
     * fread muove automaticamente il puntatore _IO_read_ptr (quello di lettura)
     * quindi non è richiesto l'intervento di lseek 
     */

    #endif
    

    /* 4)si può memorizzare una funzione in un file?
     *
     * Sembra che si riesca a salvare su un file la funzione ma viene leggermente 
     * modificata per qualche motivo, lo si nota anche ispezionando il codice 
     * assembly con gdb (se si prova a scrivere direttamente su foo)
     * Non ne capisco il motivo ma non ho intenzione di spenderci altro tempo per 
     * ora
     */
    #if WRITE_FOO
    FILE* fooFile = fopen("fooFile.txt", "w");
    fwrite(foo, 22, 1, fooFile);

    #else
    FILE* fooFile = fopen("fooFile.txt", "r");
    //fread(foo, 22, 1, fooFile);
    fread(readFoo, 22, 1, fooFile);
    readFoo();

    

    #endif
}
    

void foo()
{
    printf("in foo\n");
}

