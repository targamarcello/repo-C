#include <stdio.h>
int main(int argc, char *argv[]){

    int N1,N2;
    
    do{
        printf("Inserisci N1\n");
        scanf("%d",&N1);
        printf("Inserisci N2\n");
        scanf("%d", &N2);
    }while(N1>N2);
    
    for(int i=N2-1; i>N1; i--){
        printf("%d ",i);
    }
    
    
    return 0;
}
