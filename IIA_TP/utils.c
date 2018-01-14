#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

float valor_total(float *sol, int tamSol) {
	float total = 0;
	for (int i = 0; i < tamSol; i++)
		total += sol[i];
	return total;
}

// Gera a solu��o inicial
void gera_sol_inicial(float *sol, int tamSol, float *dados, int tamDados) {
	int x, i;
	int qtdInicial = (tamSol * ((rand() % 101) / 100.00));

	for (i = 0; i < tamSol; i++)
		sol[i] = 0.0;
	for (i = 0; i < qtdInicial; i++) {
		do
			x = random_l_h(0, tamSol - 1);
		while (sol[x] != 0.0);
		sol[x] = dados[random_l_h(0, tamDados - 1)];
	}
}

// Escreve solu��o no ecr�
// Par�metros de entrada: Solu��o, sol, N�mero de vertices, vert
void escreve_sol(float *sol, int tamSol)
{
	for (int i = 0; i < tamSol; i++)
			printf("sol[%d] = %.2f\n", i, sol[i]);
	printf("\n");
}

// copia vector b para a (tamanho n)
// Par�metros de entrada: Solu��o que ser� substitu�da, a, Solu��o que ir� substituir, b, N�mero de vertices, n
void substitui(int a[], int b[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		a[i] = b[i];
}

// Gera um valor inteiro aleat�rio entre min e max
// Par�metros de entrada: Valor inferior do intervalo, min, Valor superior do intervalo, max
// Par�metros de sa�da: Valor aleat�rio entre min e max
int random_l_h(int min, int max)
{
	return min + rand() % (max - min + 1);
}

// Gera um valor inteiro aleat�rio entre 0 e 1
// Par�metros de sa�da: Valor aleat�rio entre 0 e 1
float rand_01()
{
	return ((float)rand()) / RAND_MAX;
}
