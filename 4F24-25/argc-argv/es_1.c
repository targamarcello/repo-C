#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("ERRORE ARGOMENTI!!");
    exit(0);
  }
  int n = atoi(argv[1]);

  if (n <= 0)
  {
    printf("il valore inserito in argv deve essere positivo!!");
    exit(0);
  }
  for (int i = 0; i < n; i++)
  {
    if (i == 0 || i == n - 1)
    {
      for (int k = 0; k < n; k++)
      {
        printf("* ");
      }
    }
    else
    {
      for (int k = 0; k < n; k++)
      {
        if (k == 0 || k == n - 1)
        {
          printf("* ");
        }
        else
        {
          printf("  ");
        }
      }
    }
    printf("\n");
  }

  return 0;
}