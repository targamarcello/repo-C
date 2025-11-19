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
  struct sockaddr_in servizio,addr_remoto;
  int socketfd, soa, fromlen = sizeof(servizio);
  char str[DIM], str2[DIM];

  servizio.sin_family = AF_INET;
  servizio.sin_addr.s_addr = htonl(INADDR_ANY);
  servizio.sin_port = htons(SERVERPORT);

  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
  listen(socketfd, 2);

  for (;;) {
    printf("\n\nServer in ascolto...");
    fflush(stdout);

    soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
    read(soa, str, DIM);
    read(soa, str2, DIM);

    int len1 = strlen(str);
    int len2 = strlen(str2);

    if (len1 > len2) {
      strcpy(str, "La prima stringa è più lunga");
    } else if (len2 < len1) {
      strcpy(str, "La seconda stringa è più lunga");
    } else {
      strcpy(str, "Le stringhe sono lunghe uguale");
    }

    write(soa, str, sizeof(str));
    close(soa);
  }
  return 0;
}