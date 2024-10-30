#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define numeri 5
int main()
{
    int nums[numeri];
    int fd= open("sum", 0_RONLY);
    if(fd==-1)
    {
        printf("errore creazione FIFO\n");
        exit(-1);
    }
    printf("Il Consumatore sta leggendo i numeri dalla FIFO\n");
    read(fd, nums, sizeof(nums));ù
    int sum=0;
    for(int i=0; i<numeri; i++)
    {
        sum +=nums[i];
        printf("Il numero letto è : ",nums[i]);
    }
    printf("La somma dei numeri è : %d", sum);
    close(fd);
    return 0;
}