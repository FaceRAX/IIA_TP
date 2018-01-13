#include "base.h"

//Apaga ecra
void clrscr()
{
	system("@cls||clear");
}

//gera números aleatórios
void init_rand(){
    srand((unsigned)time(NULL));
}

//Ler dados de ficheiro
int* init_dados(char *nome_fich, int *n, float *v, float *dados, int *isempty) {
    
    FILE *f;
	float aux=0;
	int qtd=0;
	f = fopen(nome_fich, "r");
    if(!f)
    {
        printf("Erro no acesso ao ficheiro\n");
        return 0;
    }
	if(fscanf(f, "%d %f\n", n, v) == 2)
		*isempty = 0;
	else
	{
		printf("ERRO: Nao foi possivel ler os primeiros parametros, escolha um ficheiro valido!\n");
		*isempty = 1;
	}
	while (fscanf(f, "%f", &aux) && qtd < *n) 
	{
		
		if (qtd != 0)
			dados = realloc(dados, sizeof(dados) + sizeof(float));
		dados[qtd] = aux;
		qtd++;
	}
	return dados;
    
    
}