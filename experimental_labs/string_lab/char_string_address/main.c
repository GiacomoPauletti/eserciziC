#include <stdio.h>

int main(){
    int contatore;

    /*****STAMPARE A VIDEO GLI INDIRIZZI DELLE STRINGHE CARATTERE*****/
    /* qui stampo gli indirizzi delle stringhe composte solo da un
     * carattere per capire se hanno qualche relazione tra di loro
     * e da cosa dipendono
     */
    printf("ADDRESS OF \"a\" : %p \n", "a");
    printf("ADDRESS OF \"b\" : %p \n", "b");
    printf("ADDRESS OF \"c\" : %p \n", "c");
    printf("ADDRESS OF \"d\" : %p \n", "d");
    printf("ADDRESS OF \"e\" : %p \n", "e");
    printf("ADDRESS OF \"f\" : %p \n", "f");


    /*********STAMPARE A VIDEO LE DIFFERENZE DEGLI INDIRIZZI*********/
    /* Qui stampo le differenze degli indirizzi prima stampati a video
     * Notare che tutti gli indirizzi si trovano precisamente a 24 bytes
     * di distanza dal precedente indirizzo
     */
    printf("ADDRESS OF \"b\" - \"a\" (subtraction): %lu\n", "b"- "a");
    printf("ADDRESS OF \"b\" - \"b\" (subtraction): %lu\n", "c"- "b");
    printf("ADDRESS OF \"d\" - \"c\" (subtraction): %lu\n", "d"- "c");
    printf("ADDRESS OF \"e\" - \"d\" (subtraction): %lu\n", "e"- "d");
    printf("ADDRESS OF \"f\" - \"e\" (subtraction): %lu\n", "f"- "e");


    /*********STAMPARE A VIDEO PIU' INDIRIZZI ALLA VOLTA*********/
    /*Gli indirizzi sono uguali a quelli che vengono stampati dalla
     * prima sezione SE ANCHE ESSA VIENE ESEGUITA.
     * Se invece la prima sezione NON viene eseguita allora gli indirizzi
     * qui stampati sono diversi e sono: 
     *      "a" : 0x7fda348d9010 | "b" : 0x7fda348d900e | 
     *      "c" : 0x7fda348d900c | "d" : 0x7fda348d900a     
     *      "e" : 0x7fda348d9008 | "f" : 0x7fda348d9065
     */
    /*printf("ADDRESS OF \"a\" : %p \n \"b\" : %p \n \"c\" : %p \n \"d\" : %p \n \"e\" : %p \n \"f\" : %p \n\n", 
        "a", "b", "c", "d", "e", "f");*/


    /*********STAMPARE A VIDEO PIU' DIFFERENZE ALLA VOLTA*********/
    /*I risultati sono bizzarri, se non si usa il resto del codice:
     * "b" - "a" : 18446744073709551614 
     * "c" - "b" : 18446744073709551614 
     * "d" - "c" : 18446744073709551614
     * "e" - "d" : 18446744073709551614 
     * "f" - "e" : 94 
     * 
     * Facendo i calcoli ad occhio tuttavia si vede come la differenza
     * tra gli indirizzi, apparte l'ultimo, sia di 2 bytes 
     */ 
    /*printf("ADDRESS OF \"b\" - \"a\" : %lu \n \"c\" - \"b\" : %lu \n \"d\" - \"c\" : %lu \n \"e\" - \"d\" : %lu \n \"f\" - \"e\" : %lu \n\n", 
        "b" - "a", "c" - "b", "d" - "c", "e" - "d", "f" - "e");*/


    }