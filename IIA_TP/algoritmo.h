
#define MAX_OBJ 1000		// Numero maximo de objectos
#define def_popsize 100
#define def_pm 0.01
#define def_pr 0.3
#define def_tsize 2
#define def_max_gen 1500 //numgen
#define def_ro 0.2
#define def_cap 250

// EStrutura para armazenar parametros
struct info
{
	// Tamanho da população
	int     popsize;
	// Probabilidade de mutação
	float   pm;
	// Probabilidade de recombinação
	float   pr;
	// Tamanho do torneio para seleção do pai da próxima geração
	int     tsize;
	// Constante para avaliação com penalização
	float   ro;
	// Número de objetos que se podem colocar na mochila
	//int     numGenes;
	int 	moedas;		//N
						// Capacidade da mochila
	float     capacity;   //val
						  // Número de gerações
	int     numGenerations;
};

// Individuo (solução)
typedef struct individual chrom, *pchrom;

struct individual
{
	// Solução (objetos que estão dentro da mochila)
	int     p[MAX_OBJ];
	// Valor da qualidade da solução
	float   fitness;
	// 1 se for uma solução válida e 0 se não for
	int     valido;
};

void tournament(pchrom, struct info, pchrom);

void tournament_geral(pchrom, struct info, pchrom);

void genetic_operators(pchrom, struct info, pchrom);

void crossover(pchrom, struct info, pchrom);

void mutation(pchrom, struct info);

void mutacao_por_troca(pchrom, struct info);
