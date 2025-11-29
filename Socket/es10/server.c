// SERVER
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define DIM 50
#define SERVERPORT 1313

int main() {
  struct sockaddr_in servizio, addr_remoto;
  servizio.sin_family = AF_INET;
  servizio.sin_addr.s_addr = htonl(INADDR_ANY);
  servizio.sin_port = htons(SERVERPORT);
  int socketfd, soa, fromlen = sizeof(servizio);
  int lettere, cifre, spazi, speciali;

  char str[DIM];
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
  listen(socketfd, 10);
  for (;;) {
    printf("\n\nServer in ascolto...");
    fflush(stdout);
    soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
    read(soa, str, sizeof(str));
    printf("\nStringa ricevuta: %s\n", str);

    for (int i = 0; i<strlen(str); i++) {
        char c= str[i];
        if((c>= 'A' && c<='Z') || (c>='a' && c<='z')){
            lettere++;
        }else if(c>='0' && c<='9'){
            cifre++;
        }else if(c== ' '){
            spazi++;
        }else{
            speciali++;
        }
    }
    write(soa,&lettere,sizeof(lettere));
    write(soa,&cifre ,sizeof(cifre));
    write(soa,&spazi,sizeof(spazi));
    write(soa,&speciali,sizeof(speciali));

    close(soa);
  }
  return 0;
}