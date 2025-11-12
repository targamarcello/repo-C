#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313
#define BUFFER_SIZE 1024

int ControlloStringa(char stringa[], char carattere)
{
  int ripetizioniChar = 0;
  for (int i = 0; i < strlen(stringa); i++)
  {
    if (stringa[i] == carattere)
    {
      ripetizioniChar++;
    }
  }
  return ripetizioniChar;
}

int main()
{
  struct sockaddr_in servizio, indirizzo_remoto;
  int socketTrasporto, client;
  socklen_t fromlen = sizeof(indirizzo_remoto);
  char stringa[DIM];
  char carattere;
  char buffer[BUFFER_SIZE];
  int caratteriContati;

  servizio.sin_family = AF_INET;
  servizio.sin_addr.s_addr = htonl(INADDR_ANY);
  servizio.sin_port = htons(SERVERPORT);

  socketTrasporto = socket(AF_INET, SOCK_STREAM, 0);
  if (socketTrasporto < 0)
  {
    perror("Errore nella creazione del socket");
    exit(1);
  }

  bind(socketTrasporto, (struct sockaddr *)&servizio, sizeof(servizio));

  listen(socketTrasporto, 10);
  for (;;)
  {
    printf("Server in ascolto sulla porta %d...", SERVERPORT);
    fflush(stdout);

    client =
        accept(socketTrasporto, (struct sockaddr *)&indirizzo_remoto, &fromlen);

    read(client, stringa, sizeof(stringa));
    read(client, &carattere, sizeof(carattere));

    printf("Stringa dal client: %s\n", stringa);
    caratteriContati = ControlloStringa(stringa, carattere);

    sprintf(buffer, "%d", caratteriContati);
    write(client, buffer, strlen(buffer));

    close(client);
  }
  return 0;
}