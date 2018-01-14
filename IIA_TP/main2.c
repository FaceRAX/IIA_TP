/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define DEFAULT_RUNS 10

int main2(int argc, char *argv[])
{
	char    nome_fich[100];
	int     vert, num_iter, k, runs = 0, custo, best_custo;
	int     *grafo, *sol, *best;
	float   mbf = 0.0;
	init_rand();
	// Preenche matriz de adjacencias, o n�mero de v�rtices a usar e o n�mero de itera��es a fazer com o trepa colinas
	grafo = init_dados(nome_fich, &vert, &num_iter);
	sol = malloc(sizeof(int)*vert); // Aloca espa�o para a solu��o
	best = malloc(sizeof(int)*vert); // Aloca espa�o para a melhor solu��o
	if (sol == NULL || best == NULL) {
		printf("Erro na alocacao de memoria");
		exit(1);
	}

















	// Faz um ciclo com o n�mero de execu��es definidas
	for (k = 0; k<runs; k++) {
		gera_sol_inicial(sol, vert); // Gera a solucao inicial
		escreve_sol(sol, vert); // Mostra a solucao inicial
		custo = trepa_colinas(sol, grafo, vert, num_iter); // Executa o algoritmo do trepa colinas
	  //Mostra a solu��o encontrada na repeti��o k e o seu custo
		printf("\nRepeticao %d:", k);
		escreve_sol(sol, vert);
		printf("Custo final: %2d\n", custo);
		mbf += custo; // Acumula o custo das solu��es encontradas
		if (k == 0 || best_custo > custo) {
			best_custo = custo;
			substitui(best, sol, vert);
		}
	}






















	printf("\n\nMBF: %f\n", mbf / k); //M�dia dos custos de todas as melhores solu��es encontradas
	// Mostra a melhor solu��o encontrada e o seu respectivo custo
	printf("\nMelhor solucao encontrada");
	escreve_sol(best, vert);
	printf("Custo final: %2d\n", best_custo);
	// Liberta a mem�ria usada
	free(grafo);
	free(sol);
	free(best);
	return 0;
}
*/