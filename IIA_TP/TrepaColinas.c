#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TrepaColinas.h"

#define PROB 0.01 // probabilidade fixa do algoritmo do trepa-colinas probabilístico




int total_moedas(float *sol, int tamSol) {
	int total = 0;
	for (int i = 0; i < tamSol; i++) {
		if (sol[i] != 0.0)
			total++;
	}
	return total;
}

int solucao_e_melhor(float *solAtual, float *solVizinha, int tamSol, int totalMoedas, int totalMoedasTmp, float quantia) {
	float quantiaAtual = valor_total(solAtual, tamSol);
	float quantiaVizinha = valor_total(solVizinha, tamSol);
	if (quantiaAtual > quantia && quantiaVizinha < quantiaAtual)
		return 1;
	if (quantiaAtual < quantia && quantiaVizinha > quantiaAtual)
		return 1;
	if (quantiaAtual == quantia && totalMoedasTmp < totalMoedas)
		return 1;
	return 0;
}
// Gera um vizinho à distância 1 (troca um vértice de cada grupo)
// Parâmetros de entrada: Solução actual, a, Solução vizinha, b, Número de vértices, n
void gera_vizinho(float *solAtual, float *solVizinha, int tamSol, float *moedas, int tamArrMoedas)
{
	int posSol = (rand() % (tamSol - 1));
	int posMoedas;

	for (int i = 0; i < tamSol; i++)
		solVizinha[i] = solAtual[i];
	for (int i = 0; i < 2; i++) {
		if (rand() % 100 < 50) {
			do {
				posSol = (rand() % (tamSol - 1));
				posMoedas = (rand() % (tamArrMoedas - 1));
			} while (solVizinha[posSol] == moedas[posMoedas]);
			solVizinha[posSol] = moedas[posMoedas];
		}
		else {
			do {
				posSol = (rand() % (tamSol - 1));
			} while (solVizinha[posSol] == 0.0);
			solVizinha[posSol] = 0.0;
		}
	}
}

// Trepa colinas first-choice
// Parâmetros de entrada: Solucao, sol, Matriz de adjacencias, mat, Número de vértices, vert, Número de iterações, num_iter
// Parâmetros de saída: Custo da melhor solução encontrada
int trepa_colinas(float *sol, int tamSol, float *moedas, int tamArrMoedas, int num_iter, float quantia)
{
	int totalMoedas, NovoTotalMoedas, i;
	float *novaSol = malloc(sizeof(float)*tamSol);

	if (novaSol == NULL) {
		printf("Erro na alocacao de memoria.");
		exit(1);
	}
	totalMoedas = total_moedas(sol, tamSol); // Avalia solução inicial
	for (i = 0; i < num_iter; i++) {
		gera_vizinho(sol, novaSol, tamSol, moedas, tamArrMoedas); // Gera solução vizinha
		// Ficha 7 - 4.3 ----------> gera_vizinho2(sol, nova_sol, vert);
		NovoTotalMoedas = total_moedas(novaSol, tamSol); // Avalia solução vizinha
		// Fica com a solução vizinha se o custo diminuir (problema de minimização) em relação à solução atual
		if (solucao_e_melhor(sol, novaSol, tamSol, totalMoedas, NovoTotalMoedas, quantia)) {
			substitui(sol, novaSol, tamSol);
			totalMoedas = NovoTotalMoedas;
		}
		//printf("%d -> %.2f\n", totalMoedas, valor_total(sol, tamSol));
	}
	free(novaSol);
	return totalMoedas;
}

// Trepa colinas first-choice
// Parâmetros de entrada: Solucao, sol, Matriz de adjacencias, mat, Número de vértices, vert, Número de iterações, num_iter
// Parâmetros de saída: Custo da melhor solução encontrada
/*int trepa_colinas_probabilistico(int sol[], int *mat, int vert, int num_iter)
{
	int *nova_sol, custo, custo_viz, i;
	nova_sol = malloc(sizeof(int)*vert); // Aloca espaço em memória para guardar a nova solução
	if (nova_sol == NULL) {
		printf("Erro na alocacao de memoria");
		exit(1);
	}
	custo = total_moedas(sol, mat, vert); // Avalia solução inicial
	for (i = 0; i < num_iter; i++) {
		gera_vizinho(sol, nova_sol, vert); // Gera solução vizinha
		custo_viz = calcula_fit(nova_sol, mat, vert); // Avalia solução vizinha
		// Fica com a solução vizinha se o custo diminuir (problema de minimização) em relação à solução atual
		if (custo_viz <= custo) {
			substitui(sol, nova_sol, vert);
			custo = custo_viz;
		}
		else if (rand_01() < PROB) {
				substitui(sol, nova_sol, vert);
				custo = custo_viz;
		}
	}
	free(nova_sol);
	return custo; // Devolve o custo da melhor solução encontrada
}*/