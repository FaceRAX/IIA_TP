
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
	// Tamanho da popula��o
	int     popsize;
	// Probabilidade de muta��o
	float   pm;
	// Probabilidade de recombina��o
	float   pr;
	// Tamanho do torneio para sele��o do pai da pr�xima gera��o
	int     tsize;
	// Constante para avalia��o com penaliza��o
	float   ro;
	// N�mero de objetos que se podem colocar na mochila
	//int     numGenes;
	int 	moedas;		//N
						// Capacidade da mochila
	float     capacity;   //val
						  // N�mero de gera��es
	int     numGenerations;
};

// Individuo (solu��o)
typedef struct individual chrom, *pchrom;

struct individual
{
	// Solu��o (objetos que est�o dentro da mochila)
	int     p[MAX_OBJ];
	// Valor da qualidade da solu��o
	float   fitness;
	// 1 se for uma solu��o v�lida e 0 se n�o for
	int     valido;
};

void tournament(pchrom, struct info, pchrom);

void tournament_geral(pchrom, struct info, pchrom);

void genetic_operators(pchrom, struct info, pchrom);

void crossover(pchrom, struct info, pchrom);

void mutation(pchrom, struct info);

void mutacao_por_troca(pchrom, struct info);
