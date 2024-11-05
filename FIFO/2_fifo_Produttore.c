#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define numeri 5
#define numeriRandom 99
int main()
{
    int nums[numeri];
    printf("FILE PRODUTTORE : %d numeri casuali randomici\n", numeri);
    for (int i = 0; i < numeri; i++)
    {
        nums[i] = rand() % (numeriRandom + 1);
        printf("é stato generato un numero nell'array\n");
    }
    int fd = open("sum", O_WONLY);
    if (fd == -1)
    {
        printf("errore apertura FIFO\n");
        exit(-1);
    }
    printf("Il PRODUTTORE sta scrivendo i numeri nella FIFO\n");
    write(fd, nums, sizeof(nums));
    close(fd);
    return 0;
}