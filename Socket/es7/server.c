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

#define DIM 100
#define SERVERPORT 1313

int main() {
  struct sockaddr_in servizio, addr_remoto;
  int socketfd, soa, fromlen = sizeof(servizio);
  char str[DIM];

  servizio.sin_family = AF_INET;
  servizio.sin_addr.s_addr = htonl(INADDR_ANY);
  servizio.sin_port = htons(SERVERPORT);

  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
  listen(socketfd, 2);
  for (;;) {
    int dimensione;

    printf("\n\nServer in ascolto...");
    fflush(stdout);

    soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
    read(soa, &dimensione, sizeof(int));

    int vettore[dimensione];
    int pari = 0, dispari = 0;

    for (int i = 0; i < dimensione; i++) {
      if (vettore[i] % 2 == 0) {
        pari++;
      } else {
        dispari++;
      }
    }

    sprintf(str, "Pari: %d, Dispari: %d", pari, dispari);
    write(soa,str,sizeof(str));
    close(soa);
  }
  return 0;
}