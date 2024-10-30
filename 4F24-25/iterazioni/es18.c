
#include <stdio.h>

int main(int argc, char *argv[])
{
    int S1, h, m, s;
    printf("Inserisci i secondi\n");
    scanf("%d", &S1);
    
    m= S1/60;
    h= m/60;
    s= S1%60;
    printf("%dh %dm %ds",h,m,s);
	
	return 0;
}
