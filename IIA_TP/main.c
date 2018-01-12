#include "base.h"

int main(int argc, char** argv) {

    char nome_fich[100];
    int runs, select, *num;
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
            runs = DEFAULT_RUNS;
            printf("Nome do Ficheiro: ");
			scanf(" %[^\n]", nome_fich);
        }
    //Se o nº de execuções for menor ou igual a 0, termina o programa
    if (runs <= 0)
        return 0;
    
    printf ("Que algoritmo pretende utilizar? \n");
    printf (" 1 - Trepa-Colinas \n");
    printf (" 2 - Evolutivo \n");
    printf (" 3 - Hibrido \n");
    do{
    scanf ("%d",&select);
    if (select==1){
        dados=init_dados(nome_fich,&num, &val,dados);
		for (int i = 0; i < num; i++)
		{
			printf("%.2f ", dados[i]);
		}
		printf("\n");
		_getch();
            return 0;}
    else if (select==2){
        printf("option2");
            return 0;}
    else if (select==3){
        printf ("option3");
        return 0;}
    else
        printf("OPCAO ERRADA!!!!\n");
    } while (select != 1 || select != 2 || select != 3);
    
    
    
    return (EXIT_SUCCESS);
}

