#include "../src/solucao.c"

Solucao** criarSolucoes(int qtd, int K, int N);
int povoarSolucoes(int qtd, Solucao **solucoes, int K, int N, int **Tki, int **tki, int **ai, int **bi, int **k);
int imprimirSolucao(int id, int K, int N, int **tki, int **Tki, Solucao **solucoes);