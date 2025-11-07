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

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM];
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    listen(socketfd,10);
    for (; ;)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);
        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        read(soa,str,sizeof(str));
        printf("\nStringa ricevuta: %s\n",str);
        close(soa);
    }
   return 0;   
}
