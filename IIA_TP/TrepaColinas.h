
int total_moedas(float *sol, int tamSol);
int solucao_e_melhor(float *solAtual, float *solVizinha, int tamSol, int totalMoedas, int totalMoedasTmp, float quantia);
void gera_vizinho(float *solAtual, float *solVizinha, int tamSol, float *moedas, int tamArrMoedas);
int trepa_colinas(float *sol, int tamSol, float *moedas, int tamArrMoedas, int num_iter, float quantia);