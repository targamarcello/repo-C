#include <stdio.h>

int main(int agrc,char*argv[]){
    
    int N;
    printf("Inserisci N\n");
    scanf("%d",&N);
    for(int i=-N; i<N;i++){
        printf("%d\n",i);
    }
    return 0;
}
