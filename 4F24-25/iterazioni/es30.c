/*
Dati due numeri interi positivi N1 e N2, verificare se N1 è il quadrato 
di N2. 
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int N1, N2;
    do
    {
        printf("Inserisci N1\n");
        scanf("%d", &N1);
        printf("Inserisci N2\n");
        scanf("%d", &N2);
    } while (N1 < 0 && N2 < 0);
    if (N1 * 4 == N2)
    {
        printf("N1 è il quarto di N2\n");
        return 0;
    }
    printf("N1 non è il quarto di N2\n");

    return 0;
}
