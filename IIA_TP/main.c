#include <stdio.h>
#include <stdlib.h>
#include "base.h"

int main(int argc, char** argv) {
	init_rand();
    char nome_fich[100];
	struct info EA_param;
	pchrom      pop = NULL, parents = NULL;
	chrom       best_run, best_ever;
	int         gen_actual, r, i, inv, mat[MAX_OBJ][1];
    int runs = DEFAULT_RUNS, select, tamArrMoedas, tamMaxSol, isempty, num_iter, custo, best_custo;
    float val, mbf = 0.0;
	float *moedas = malloc(sizeof(float)), *sol, *best;
FILE_LOADER:
	clrscr();
    printf("Nome do Ficheiro: ");
	scanf(" %[^\n]", nome_fich);
	//Carrega o ficheiro para a memoria
	init_iniciais(nome_fich, &tamArrMoedas, &val, &isempty);
	if (isempty)
		goto FILE_LOADER;
	moedas = (float *)realloc(moedas, tamArrMoedas * sizeof(float));
	init_dados(nome_fich, &tamArrMoedas, &val, moedas);
    if (runs <= 0)
        return 0;
	do {
		clrscr();
		printf("(Ficheiro carregado: %s)\n", nome_fich);
		printf("Que algoritmo pretende utilizar? \n");
		printf(" 1 - Trepa-Colinas \n");
		printf(" 2 - Evolutivo \n");
		printf(" 3 - Hibrido \n");
		printf(" 4 - Recarregar um ficheiro \n");
		printf(" 5 - Sair \n");
		scanf("%d", &select);
		if (select == 1) {
			clrscr();
			int k;
			/*printf("Nr. de iteracoes do trepa-colinas: ");
			scanf("%d", &num_iter);
			printf("Nr. maximo de moedas: ");
			scanf("%d", &tamMaxSol);*/
			num_iter = 1000;	//--->  PARA TESTES!!!...
			tamMaxSol = 100;	//--->  PARA TESTES!!!...
			sol = malloc(sizeof(int)*tamMaxSol); // Aloca espaço para a solução
			best = malloc(sizeof(int)*tamMaxSol); // Aloca espaço para a melhor solução

			for (k = 0; k < runs; k++) {
				clrscr();
				printf("Iteracao %d:\n", k);
				gera_sol_inicial(sol, tamMaxSol, moedas, tamArrMoedas); //Gera a solucao inicial
				printf("Solucao Inicial:\n");
				escreve_sol(sol, tamMaxSol); //Mostra a solucao inicial
				//Executa o algoritmo do trepa colinas
				custo = trepa_colinas(sol, tamMaxSol, moedas, tamArrMoedas, num_iter, val);
				//Mostra a solução encontrada na repetição k
				printf("----------------------------------------\nSolucao Final:\n");
				escreve_sol(sol, tamMaxSol);
				printf("Custo Final: %2d\n", custo);
				printf("Valor Final: %.2f\n", valor_total(sol, tamMaxSol));
				_getch();
				mbf += custo; //Acumula o custo das soluções encontradas (para poder calcular a média)
				if (k == 0 || best_custo > custo) {
					best_custo = custo;
					substitui(best, sol, tamMaxSol);
				}
			}

			printf("\n\nMBF: %f\n", mbf / k); //Média dos custos de todas as melhores soluções encontradas
											  // Mostra a melhor solução encontrada e o seu respectivo custo
			printf("\nMelhor solucao encontrada:\n");
			escreve_sol(best, tamMaxSol);
			printf("Custo final: %2d\n", best_custo);
			// Liberta a memória usada*/
			free(sol);
			free(best);
		}
		else if (select == 2) {
			EA_param = init_struct_type(tamArrMoedas, val, mat, moedas);
			for (r = 0; r < runs; r++)
			{
				printf("Repeticao %d\n", r + 1);
				// Geração da população inicial
				pop = init_pop(EA_param);
				// Avalia a população inicial
				evaluate(pop, EA_param, mat);
				// Aplicação do algoritmo trepa colinas para refinar a população inicial
				// Exercício 4.6(i)
				//        trepa_colinas(pop, EA_param, mat);
				// Como ainda não existe, escolhe-se como melhor solução a primeira da população (poderia ser outra qualquer)
				best_run = pop[0];
				// Encontra-se a melhor solução dentro de toda a população
				best_run = get_best(pop, EA_param, best_run);
				// Reserva espaço para os pais da população seguinte
				parents = malloc(sizeof(chrom)*EA_param.popsize);
				// Caso não consiga fazer a alocação, envia aviso e termina o programa
				if (parents == NULL)
				{
					printf("Erro na alocacao de memoria\n");
					exit(1);
				}
				// Ciclo de optimização
				gen_actual = 1;
				while (gen_actual <= EA_param.numGenerations)
				{
					// Torneio binário para encontrar os progenitores (ficam armazenados no vector parents)
					tournament(pop, EA_param, parents);
					// Torneio de k elementos, com k >= 2, para encontrar os progenitores (ficam armazenados no vector parents)
					// Exercício 4.5
					//            tournament_geral(pop, EA_param, parents);
					// Aplica os operadores genéticos aos pais (os descendentes ficam armazenados na estrutura pop)
					genetic_operators(parents, EA_param, pop);
					// Avalia a nova população (a dos filhos)
					evaluate(pop, EA_param, mat);
					// Aplicação do algoritmo trepa colinas para refinar a população final
					// Exercício 4.6(iii)
					//            trepa_colinas(pop, EA_param, mat);
					// Actualiza a melhor solução encontrada
					best_run = get_best(pop, EA_param, best_run);
					gen_actual++;
				}
				// Aplicação do algoritmo trepa colinas para refinar a população final
				// Exercício 4.6(ii)
				//        trepa_colinas(pop, EA_param, mat);
				// Contagem das soluções inválidas
				for (inv = 0, i = 0; i < EA_param.popsize; i++)
					if (pop[i].valido == 0)
						inv++;
				// Escreve resultados da repetição que terminou
				printf("\nRepeticao %d:", r);
				write_best(best_run, EA_param);
				printf("\nPercentagem Invalidos: %f\n", 100 * (float)inv / EA_param.popsize);
				mbf += best_run.fitness;
				if (r == 0 || best_run.fitness > best_ever.fitness)
					best_ever = best_run;
				// Liberta a memória usada
				free(parents);
				free(pop);
			}
			// Escreve resultados globais
			printf("\n\nMBF: %f\n", mbf / r);
			printf("\nMelhor solucao encontrada");
			write_best(best_ever, EA_param);
			_getch();
		}
	
		else if (select==3)
			printf ("option3");
		else if (select == 4)
			goto FILE_LOADER;
		else if (select == 5)
			goto FINISH;
		else
			printf("OPCAO INVALIDA!\n");
    } while (1);
FINISH:   
    return (0);
}