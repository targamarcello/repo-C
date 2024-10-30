#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    printf("Sono il processo dell'exec e il mio PID è %d\n",getpid());
    printf("Gli argomenti inviati sono: %s e %s \n",argv[0],argv[1]);
    return 0;
}