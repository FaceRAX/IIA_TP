#include "base.h"

void clrscr()
{
	system("@cls||clear");
}

void init_rand(){
    srand((unsigned)time(NULL));
}

void init_iniciais(char *nome_fich, int *n, float *v, int *isempty) {
	FILE *f;
	f = fopen(nome_fich, "r");
	if (!f) {
		printf("Erro no acesso ao ficheiro\n");
		return 0;
	}
	if (fscanf(f, "%d %f\n", n, v) == 2)
		*isempty = 0;
	else {
		printf("ERRO: Nao foi possivel ler os primeiros parametros, escolha um ficheiro valido!\n");
		*isempty = 1;
	}
	fclose(f);
}

//Ler dados de ficheiro
void init_dados(char *nome_fich, int *n, float *v, float *dados) {
    FILE *f;
	float aux=0;
	int qtd=0;
	f = fopen(nome_fich, "r");
    if(!f) {
        printf("Erro no acesso ao ficheiro\n");
        return 0;
    }
	fscanf(f, "%d %f\n", n, v);
	while (fscanf(f, "%f", &aux) && qtd < *n) {
		dados[qtd] = aux;
		qtd++;
	}
	fclose(f);
}

struct info init_struct_type(int n, float v, int mat[][1], float *moedas) {
	struct info x;
	char defaultvalues = ' ';
	float aux = 0;
	int i, qtd = 0;
	printf("Utilizar valores por defeito? (S/N)\n");
	scanf(" %[^\n]", &defaultvalues);
	if (defaultvalues == 'S' || defaultvalues == 's')
	{
		x.popsize = def_popsize;
		x.pm = def_pm;
		x.pr = def_pr;
		x.tsize = def_tsize;
		x.ro = def_ro;
		x.moedas = n;
		x.capacity = v;
		x.numGenerations = def_max_gen;
	}
	else
	{
		printf("Tamanho da populacao: ");
		scanf("%f", &x.popsize);
		printf("Probabilidade de mutacao: ");
		scanf("%f", &x.pm);
		printf("Probabilidade de recombinacao: ");
		scanf("%f", &x.pr);
		printf("Tamanho do torneio para selecao do pai da proxima geracao: ");
		scanf("%d", &x.tsize);
		printf("Constante para avaliacao com penalizacao (ro): ");
		scanf("%f", &x.ro);
		x.moedas = n;
		x.capacity = v;
		printf("Numero de geracoes: ");
		scanf("%d", &x.numGenerations);
		for (i = 0; i < x.moedas; i++)
			mat[i][0] = moedas[i];
	}
	return x;
}