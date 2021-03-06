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