#include <stdio.h>

#define NUM_DIGITS 1000
#define STRIKE_NUM 13

int main()
{
    char number[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

    int mainCursor, subCursor;
    long int maxProduct;
    long int currentProduct;

    maxProduct = 1, currentProduct=1;
    for (mainCursor=0; mainCursor < NUM_DIGITS - (STRIKE_NUM - 1); mainCursor++)
    {
        /* ciclo che guarda tutti i numeri fino all'ultimo numero da cui si può avere una sequenza lunga STRIKE_NUM
         * Il motivo del " - 1" si capisce con un esempio, in cui STRIKE_NUM = 2.
         *  -> ...580480521 se facessi - STRIKE_NUM il main cursor si fermerebbe non quando punta all'1 finale, ma
         *                  a 2 posiizoni prima (5). Tuttavia può essere ancora creata un ultima sequenza lunga 2
         *                  (fatta da 2 e 1)
         */

        currentProduct = number[mainCursor] - '0';
        if ( currentProduct != 0 )
        {
            for (subCursor = 0; subCursor < STRIKE_NUM - 1; subCursor++)
            {
                /* qui il " - 1" è dovuto al fatto che il primo elemento l'ho già contanto prima */

                currentProduct *= number[mainCursor + subCursor] - '0';
            }

            if ( currentProduct > maxProduct )
            {
                printf("%ld | %ld\n", maxProduct, currentProduct);
                maxProduct = currentProduct;
            }
            currentProduct = 1;
        }
    }

    printf("The maximum product is: %ld\n", maxProduct);
}