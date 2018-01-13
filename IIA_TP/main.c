#include "base.h"

int main(int argc, char** argv) {
	
    char nome_fich[100];
    int runs, select, num, isempty;
    float val; 
	float *dados = malloc(sizeof(float));
    //Lê argumentos de entrada
    if (argc == 3)
	{
		runs = atoi(argv[2]);
		strcpy(nome_fich, argv[1]);
	}
	else
        // Se o número de execuções do processo não for colocado nos argumentos de entrada, define-o com um valor por defeito
        if (argc == 2)
        {
            runs = DEFAULT_RUNS;
            strcpy(nome_fich, argv[1]);
        }
        // Se o nome do ficheiro de informações não for colocado nos argumentos de entrada, pede-o novamente
        else
        {
FILE_LOADER:
            runs = DEFAULT_RUNS;
            printf("Nome do Ficheiro: ");
			scanf(" %[^\n]", nome_fich);
        }
	//Carrega o ficheiro para a memoria
	init_iniciais(nome_fich, &num, &val,&isempty);
	if (isempty)
		goto FILE_LOADER;
	else
	{
		dados = realloc(dados, num * sizeof(float));
	}
	dados = init_dados(nome_fich, &num, &val, dados);
    //Se o nº de execuções for menor ou igual a 0, termina o programa
    if (runs <= 0)
        return 0;
RESTARTER:
	clrscr();
	printf ("(Ficheiro carregado: %s)\n",nome_fich);
    printf ("Que algoritmo pretende utilizar? \n");
    printf (" 1 - Trepa-Colinas \n");
    printf (" 2 - Evolutivo \n");
    printf (" 3 - Hibrido \n");
	printf (" 4 - Recarregar um ficheiro \n");
	printf (" 5 - Sair \n");
    do{
    scanf ("%d",&select); 
    if (select==1){
		printf("%d ", num);
		printf("%.2f\n", val);
		_getch();
		for (int i = 0; i < num; i++)
		{
			printf("%.2f ", dados[i]);
		}
		printf("\n");
		_getch();
		goto RESTARTER;
            }
    else if (select==2){
        printf("option2");
		goto RESTARTER;
            }
    else if (select==3){
        printf ("option3");
		goto RESTARTER;
        }
	else if (select == 4) {
		goto FILE_LOADER;
	}
	else if (select == 5){
		goto FINISH;
		}
    else
        printf("OPCAO INVALIDA!\n");
    } while (1);
    
    
FINISH:   
    return (EXIT_SUCCESS);
}