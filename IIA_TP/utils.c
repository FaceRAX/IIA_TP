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

// Gera a solução inicial
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

// Escreve solução no ecrã
void escreve_sol(float *sol, int tamSol) {
	for (int i = 0; i < tamSol; i++)
			printf("sol[%d] = %.2f\n", i, sol[i]);
}

// copia vector b para a (tamanho n)
void substitui(float a[], float b[], int n) {
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}

// Gera um valor inteiro aleatório entre min e max
int random_l_h(int min, int max) {
	return min + rand() % (max - min + 1);
}