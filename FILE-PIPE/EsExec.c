#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
    printf("Sono il processo di base e il mio PID è %d \n", getpid());
    execl("./FileExec.exe","ciao","buongiorno", NULL);
    return 0;
}