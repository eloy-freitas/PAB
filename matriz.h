
#include "matriz.c"

int padronizarMatriz(int** M, int K, int N, int inteiro);

int** criaMatriz(int K, int N);

int povoarMatriz(int** M, int K, int N);

int imprimirMatriz(int** M, int K, int N);

int *getLinha(int** M, int linha);

int copiarMatriz(int** source, int** target, int K, int N);

int limparMatriz(int** M, int K);

int ordernarMatriz(int** M, int K, int N);

int getColuna(int **M, int K, int N, int valor);

int mudarUmBit(int **navios, int linha, int N);
