#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

    int pid = fork();

    if (pid == 0)
    {
        close(1);
        printf("FIGLIO : %d\n", getpid());
        sleep(60);
        exit(0);
    }
    printf("PADRE : %d\n", pid);

    return 0;
}