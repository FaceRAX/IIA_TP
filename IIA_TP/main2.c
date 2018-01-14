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
	// Preenche matriz de adjacencias, o número de vértices a usar e o número de iterações a fazer com o trepa colinas
	grafo = init_dados(nome_fich, &vert, &num_iter);
	sol = malloc(sizeof(int)*vert); // Aloca espaço para a solução
	best = malloc(sizeof(int)*vert); // Aloca espaço para a melhor solução
	if (sol == NULL || best == NULL) {
		printf("Erro na alocacao de memoria");
		exit(1);
	}

















	// Faz um ciclo com o número de execuções definidas
	for (k = 0; k<runs; k++) {
		gera_sol_inicial(sol, vert); // Gera a solucao inicial
		escreve_sol(sol, vert); // Mostra a solucao inicial
		custo = trepa_colinas(sol, grafo, vert, num_iter); // Executa o algoritmo do trepa colinas
	  //Mostra a solução encontrada na repetição k e o seu custo
		printf("\nRepeticao %d:", k);
		escreve_sol(sol, vert);
		printf("Custo final: %2d\n", custo);
		mbf += custo; // Acumula o custo das soluções encontradas
		if (k == 0 || best_custo > custo) {
			best_custo = custo;
			substitui(best, sol, vert);
		}
	}






















	printf("\n\nMBF: %f\n", mbf / k); //Média dos custos de todas as melhores soluções encontradas
	// Mostra a melhor solução encontrada e o seu respectivo custo
	printf("\nMelhor solucao encontrada");
	escreve_sol(best, vert);
	printf("Custo final: %2d\n", best_custo);
	// Liberta a memória usada
	free(grafo);
	free(sol);
	free(best);
	return 0;
}
*/