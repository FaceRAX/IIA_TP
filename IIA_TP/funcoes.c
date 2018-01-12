#include "base.h"

//gera números aleatórios
void init_rand(){
    srand((unsigned)time(NULL));
}

//Ler dados de ficheiro
int* init_dados(char *nome_fich, int *n, float *v, float *dados) {
    
    FILE *f;
	float aux=0;
	int qtd=0;
	f = fopen(nome_fich, "r");
    if(!f)
    {
        printf("Erro no acesso ao ficheiro\n");
        return 0;
    }
	fscanf(f, "%d %f\n", n, v);
	while (fscanf(f, "%f", &aux) && qtd < *n) 
	{
		
		if (qtd != 0)
			dados = realloc(dados, sizeof(dados) + sizeof(float));
		dados[qtd] = aux;
		qtd++;
	}
    printf("%d ",*n);
    printf("%.2f\n",*v);
	_getch();
	return dados;
    
    
}