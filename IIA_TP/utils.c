#include "base.h"

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

int flip()
{
	if ((((float)rand()) / RAND_MAX) < 0.5)
		return 0;
	else
		return 1;
}

pchrom init_pop(struct info d)
{
	int     i, j;
	pchrom  indiv;

	indiv = malloc(sizeof(chrom)*d.popsize);
	if (indiv == NULL)
	{
		printf("Erro na alocacao de memoria\n");
		exit(1);
	}
	for (i = 0; i<d.popsize; i++)
	{
		for (j = 0; j<d.moedas; j++)
			indiv[i].p[j] = flip();
	}
	return indiv;
}

chrom get_best(pchrom pop, struct info d, chrom best)
{
	int i;

	for (i = 0; i<d.popsize; i++)
	{
		if (best.fitness < pop[i].fitness)
			best = pop[i];
	}
	return best;
}

float rand_01()
{
	return ((float)rand()) / RAND_MAX;
}

void write_best(chrom x, struct info d)
{
	int i;

	printf("\nBest individual: %4.1f\n", x.fitness);
	for (i = 0; i<d.moedas; i++)
		printf("%d", x.p[i]);
	putchar('\n');
}