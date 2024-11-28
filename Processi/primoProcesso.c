#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char *argv[]){
    
    int p;

    p = fork();
    if(p == 0){
        printf("Sono il turbo figlio con PID: %d, il mio papino ha PID: %d\n", getpid(), getppid());
    }else if(p>0){
        printf("Sono il turbo padre con PID: %d, mio figlio ha PID: %d\n",getpid(),p);
    }else{
        printf("TURBO ERRORE!!!");
        exit(-1);
    }

    
    return 0;
}