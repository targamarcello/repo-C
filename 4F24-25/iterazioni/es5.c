#include <stdio.h>

int main(int argc, char*argv[]){
    
    int N1, N2;
    
    
    do{
        printf("Inserisci N1\n");
        scanf("%d", &N1);
        printf("Inserisci N2\n");
        scanf("%d",&N2);
        if(N1<N2){
            printf("ERRORE INSERIMENTO DEI VALORI!!!\n");
        }
    }while(N2<N1);
    
    
    for(int i=N1+1;i<N2; i++){
        printf("%d",i);
    }
    
    
    return 0;
}