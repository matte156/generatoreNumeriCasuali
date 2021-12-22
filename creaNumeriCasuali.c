#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"creaNumeriCasuali.h"

#define MAXDIGITS 8				//numero massimo di cifre da usare

// converte il flusso di input in integer e lo restituisce
unsigned int getNumber()
{
	unsigned int number;
	char buffer[MAXDIGITS];
	int counter = 0;
	
	printf("Quanti numeri vuoi generare\n");
	while((buffer[counter]=getchar())>='0' && buffer[counter]<='9' && counter<(MAXDIGITS-1) && buffer[counter]!='\n')
		counter++;
	buffer[++counter]='\0';
	number=atoi(buffer);
	return number;
}

// genera tot numero(specificato negli arguments) di numeri casuali e restituisce un puntatore ad essi
int * getRandomsWithParameter(int n)
{
	unsigned int nToGenerate;
	unsigned int * random;
	int i = 0;

	nToGenerate=n;

	random=malloc(sizeof(int)*(nToGenerate+1));
	if(random==NULL)
	{
		printf("Error\n");
		exit(1);
	}

	srand(time(0));

	random[i++] = nToGenerate;
	for( ; i < nToGenerate + 1; i++)
		random[i] = rand();

	return random;
}

/* lancia la funzione generateRandoms utilizzando come parametro il numero ottenuto dalla funzione getNumber. Restituisce  	*
 * un puntatore a numeri casuali												*/
int * getRandoms()
{
	unsigned int nToGenerate;
	int * randoms;

	nToGenerate=getNumber();
	randoms = getRandomsWithParameter(nToGenerate);

	return randoms;	
}
