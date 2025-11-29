/*Scrivere il codice in C di un’applicazione socket CLIENT–SERVER in cui il server riceve in input una stringa e,
dopo eventuali controlli, rispedisce al client due stringhe: la versione completamente in maiuscolo e
la versione completamente in minuscolo della stringa ricevuta.*/
// CLIENT
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 50
#define SERVERPORT 1313

int main(int argc, char **argv)
{
    struct sockaddr_in servizio;
    char str1[DIM],str2[DIM];
    int socketfd;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    printf("Inserisci la stringa\n");
    scanf("%s", str1);

    write(socketfd, str1, sizeof(str1));
    read(socketfd,str1,sizeof(str1));
    read(socketfd,str2,sizeof(str2));

    printf("Risultato: \n");
    printf("%s\n%s",str1,str2);
    close(socketfd);
    return 0;
}
/*Scrivere il codice in C di un’applicazione socket CLIENT–SERVER in cui il server riceve in input una stringa e, 
dopo eventuali controlli, rispedisce al client due stringhe: la versione completamente in maiuscolo e la versione completamente in minuscolo della stringa ricevuta.*/
//CLIENT
#include <stdio.h>
#include <stdlib.h> 
#include <sys/socket.h>
#include <sys/types.h> 
#include <netinet/in.h>
#include <string.h>  
#include <errno.h>  
#include <ctype.h>     
#include <unistd.h>   

#define DIM 50
#define SERVERPORT 1313

int main(int argc,char** argv)
{   
    struct sockaddr_in servizio;
    char str1[DIM],strMaiuscola[DIM],strMinuscola[DIM];     
    int socketfd;
    
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY); 
    servizio.sin_port=htons(SERVERPORT);       

    
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));    
    printf("Inserisci la stringa\n");
    scanf("%s",str1);

    write(socketfd,str1,sizeof(str1));

    read(socketfd, strMinuscola, sizeof(strMinuscola));
    read(socketfd, strMaiuscola,sizeof(strMaiuscola));
    printf("Risultato: \n - Maiuscola: %s\n - Minuscola: %s\n",strMaiuscola,strMinuscola);

    close(socketfd);
    return 0;
}