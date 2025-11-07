#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define DIM 50
#define SERVERPORT 1313

void OrdinamentoAlfabetico(char *stringa, char *risultato) {
  int lunghezza = strlen(stringa);
  char scambio;

  strcpy(risultato, stringa);

  // Bubble sort per l'ordinamento
  int i, j;
  for (i = 0; i < lunghezza - 1; i++) {
    for (j = 0; j < lunghezza - i - 1; j++) {
      if (tolower(risultato[j]) > tolower(risultato[j + 1])) {
        // Scambio dei caratteri
        scambio = risultato[j];
        risultato[j] = risultato[j + 1];
        risultato[j + 1] = scambio;
      }
    }
  }
}

int main() {
  struct sockaddr_in servizio, addr_remoto;

  servizio.sin_family = AF_INET;
  servizio.sin_addr.s_addr = htonl(INADDR_ANY);
  servizio.sin_port = htons(SERVERPORT);

  int socketfd, soa ;
  socklen_t fromlen = sizeof(servizio);
  char str[DIM], risposta[DIM];

  socketfd = socket(AF_INET, SOCK_STREAM, 0);

  bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
  listen(socketfd, 10);

  for (; ;) {
    printf("\n\nServer in ascolto...");
    fflush(stdout);

    soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
    if (read(soa, str, sizeof(str)) > 0) {
      printf("\nStringa ricevuta: %s\n", str);
      OrdinamentoAlfabetico(str, risposta);
      write(soa, risposta, sizeof(risposta));
    }
    close(soa);
  }
  return 0;
}