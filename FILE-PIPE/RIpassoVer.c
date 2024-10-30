#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define BUFFER 1024
int main(int argc, char *argv[])
{
    FILE *org, *dest;
    int n;
    unsigned char buff[BUFFER];
    org= fopen(argv[0], "r");
    if(org==NULL)
    {
        printf("\nerrore apertura file");
        exit(1);
    }
    dest= fopen(argv[1],"w");
    if(dest==NULL)
    {
        printf("\nErrore apertura file");
        exit(1);
    }
    while(!feof(org))
    {
        n=fread(buff,1,BUFFER,org);
        if(n>0)
        {
            fwrite(buff,1,n,dest);
        }
    }
    fclose(org);
    fclose(dest);
    return 0;
}