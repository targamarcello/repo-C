/*Progettare un algoritmo che risolva il seguente problema. Si richieda 
all’utente di inserire una serie di terne di dati numerici (A, B, C). 
Il programma deve terminare quando uno dei valori inseriti è minore di
zero. Si scartino le terne nelle quali i valori non sono in ordine
strettamente crescente, ovvero quelle terne per cui non valga A < B < C.
Su tutte le terne non scartate si calcoli il massimo e il minimo dei
valori inseriti. Si stampino a video tali valori massimi e minimi prima
di terminare il programma.*/

#include <stdio.h>
#include <limits.h>
int main(int argc, char *argv[])
{
	int num1, num2, num3, min = INT_MAX, max = 0;

	do
	{
		printf("Inserisci num1\n");
		scanf("%d", &num1);
		printf("Inserisci num2\n");
		scanf("%d", &num2);
		printf("Inserisci num3\n");
		scanf("%d", &num3);

		if (num1 < num2 && num2 < num3)
		{

			if (num1 < min)
				min = num1;
			if (num3 > max)
				max = num3;
		}
		else
		{
			printf("LA TERNA NON È VALIDA!!!\n");
		}

	} while (num1 >= 0 && num2 >= 0 && num3 >= 0);

	printf("Massimo: %d\n", max);
	printf("Minimo: %d\n", min);

	return 0;
}