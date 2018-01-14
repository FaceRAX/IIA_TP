#include "base.h"

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
	if (quantiaAtual > quantia && quantiaVizinha < quantiaAtual && quantiaVizinha >= quantia)
		return 1;
	if (quantiaAtual < quantia && quantiaVizinha > quantiaAtual && quantiaVizinha <= quantia)
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
				posSol = (rand() % tamSol);
				posMoedas = (rand() % tamArrMoedas );
			} while (solVizinha[posSol] == moedas[posMoedas]);
			solVizinha[posSol] = moedas[posMoedas];
		}
		else {
			int x = total_moedas(solVizinha, tamSol);
			if (x > 0) {
				do
					posSol = (rand() % tamSol);
				while (solVizinha[posSol] == 0.0);
				solVizinha[posSol] = 0.0;
			}
		}
	}
}

// Trepa colinas first-choice
// Parâmetros de entrada: Solucao, sol, Matriz de adjacencias, mat, Número de vértices, vert, Número de iterações, num_iter
// Parâmetros de saída: Custo da melhor solução encontrada
int trepa_colinas(float *sol, int tamSol, float *moedas, int tamArrMoedas, int num_iter, float quantia)
{
	int totalMoedas, NovoTotalMoedas;
	float *novaSol = malloc(sizeof(float)*tamSol);
	if (novaSol == NULL) {
		printf("Erro na alocacao de memoria.");
		exit(1);
	}

	totalMoedas = total_moedas(sol, tamSol); // Avalia solução inicial
	for (int i = 0; i < num_iter; i++) {
		gera_vizinho(sol, novaSol, tamSol, moedas, tamArrMoedas); // Gera solução vizinha
		NovoTotalMoedas = total_moedas(novaSol, tamSol); // Avalia solução vizinha
		if (solucao_e_melhor(sol, novaSol, tamSol, totalMoedas, NovoTotalMoedas, quantia)) {
			substitui(sol, novaSol, tamSol);
			totalMoedas = NovoTotalMoedas;
		}
	}

	free(novaSol);
	return totalMoedas;
}