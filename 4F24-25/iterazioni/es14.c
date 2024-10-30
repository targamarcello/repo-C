#include <stdio.h>

int main(int argc, char *argv[])
{

	int N1, N2, i = 0, prodotto = 0;
	do
	{
		printf("Inserisci N1:\n");
		scanf("%d", &N1);
	} while (N1 < 1);

	do
	{
		printf("Inserisci N2\n");
		scanf("%d", &N2);
	} while (N2 < 1);

	do
	{
		prodotto = prodotto + N1;
		i = i + 1;
	} while (i < N2);

	printf("Il prodotto fra N1 e N2 è: %d", prodotto);
	return 0;
}