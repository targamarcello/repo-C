//SERVER
#include <stdio.h>      
#include <stdlib.h>     
#include <sys/socket.h>  
#include <sys/types.h>   
#include <netinet/in.h>  
#include <netdb.h>    
#include <string.h>     
#include <fcntl.h>       
#include <signal.h>     
#include <errno.h>      
#include <ctype.h>      
#include <unistd.h>     

#define DIM 50
#define SERVERPORT 1313

void minuscolo(char *str){
    for(int i=0; i<str[i]; i++){
        str[i] = tolower((char)str[i]);
    }
}

void maiuscolo(char *str){
    for(int i=0; i<str[i]; i++){
        str[i] = tolower((char)str[i]);
    }
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM],strMinuscola[DIM],strMaiuscola[DIM];

    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    

    socketfd=socket(AF_INET,SOCK_STREAM,0);
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    listen(socketfd,2);
    for (; ;)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);
        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        read(soa,str,sizeof(str));

        strcpy(strMinuscola,str);
        strcpy(strMaiuscola,str);
        minuscolo(strMinuscola);
        maiuscolo(strMaiuscola);

        write(soa,strMinuscola,sizeof(strMinuscola));
        write(soa,strMaiuscola,sizeof(strMaiuscola));

        close(soa);
    }
   return 0;   
}