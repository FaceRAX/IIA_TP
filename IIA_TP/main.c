#include "base.h"
#include "TrepaColinas.h"

int main(int argc, char** argv) {
	init_rand();
    char nome_fich[100];
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
	init_dados(nome_fich, &tamArrMoedas, &val, moedas);
    if (runs <= 0)
        return 0;
	do {
		clrscr();
		printf ("(Ficheiro carregado: %s)\n", nome_fich);
		printf ("Que algoritmo pretende utilizar? \n");
		printf (" 1 - Trepa-Colinas \n");
		printf (" 2 - Evolutivo \n");
		printf (" 3 - Hibrido \n");
		printf (" 4 - Recarregar um ficheiro \n");
		printf (" 5 - Sair \n");
		scanf ("%d", &select); 
		if (select==1){
			clrscr();
			int k;
			/*printf("Nr. de iteracoes do trepa-colinas: ");
			scanf("%d", &num_iter);
			printf("Nr. maximo de moedas: ");
			scanf("%d", &tamMaxSol);*/
			num_iter = 5000;	//--->  PARA TESTES!!!...
			tamMaxSol = 10;	//--->  PARA TESTES!!!...
			sol = malloc(sizeof(int)*tamMaxSol); // Aloca espaço para a solução
			best = malloc(sizeof(int)*tamMaxSol); // Aloca espaço para a melhor solução
			
			for (k = 0; k < runs; k++) {
				clrscr();
				printf("Iteracao %d:\n", k);
				do
					gera_sol_inicial(sol, tamMaxSol, moedas, tamArrMoedas); //Gera a solucao inicial
				while (total_moedas(sol, tamMaxSol) == 0);
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
		else if (select==2)
			printf("option2");
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