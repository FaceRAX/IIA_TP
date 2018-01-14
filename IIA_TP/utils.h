float valor_total(float *sol, int tamSol);
void gera_sol_inicial(float *sol, int tamSol, float *dados, int tamDados);
void escreve_sol(float *sol, int tamSol);
void substitui(float a[], float b[], int n);
int random_l_h(int min, int max);

struct info init_struct_type(int n, float v, int mat[][1], float *moedas);

pchrom init_pop(struct info);

chrom get_best(pchrom, struct info, chrom);

void write_best(chrom, struct info);

void init_rand();

int random_l_h(int, int);

float rand_01();

int flip();

void clrscr();

void evaluate(pchrom, struct info, int mat[][1]);

void init_iniciais(char *nome_fich, int *n, float *v, int *isempty);
