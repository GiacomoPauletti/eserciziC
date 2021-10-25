#include <stdio.h>
#define PI 3.14159

int main(){
    float raggio;

    printf("Inserisci il raggio: ");
    scanf("%f", &raggio);

    while(raggio > 0){
        printf("Circonferenza: %.4f\n", 2 * PI * raggio);
        printf("Cerchio: %.4f\n", PI * raggio * raggio);

        printf("Inserisci il raggio: ");
        scanf("%f", &raggio);
    }

    return 0;
}