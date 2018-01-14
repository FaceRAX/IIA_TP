#include "utils.h"
int total_moedas(float *sol, int tamSol);
void gera_vizinho(float *solAtual, float *solVizinha, int tamSol, float *moedas, int tamArrMoedas);
void gera_vizinho2(int a[], int b[], int n);
int trepa_colinas(float *sol, int tamSol, float *moedas, int tamArrMoedas, int num_iter, float quantia);
//int trepa_colinas_probabilistico(int sol[], int *mat, int vert, int num_iter);