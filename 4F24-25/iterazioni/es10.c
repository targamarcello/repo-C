#include <stdio.h>
int main(int argc, char *argv[]){

    int N, somma=0;
    
    printf("Inserisci N\n");
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        somma= somma+i;
    }
    printf("La somma dei primi N è: %d", somma);
    return 0;
}
