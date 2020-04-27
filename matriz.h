
#include "matriz.c"

int padronizarMatriz(int** M, int K, int N, int inteiro);

int** criaMatriz(int K, int N);

int povoarMatriz(int** M, int K, int N);

int imprimirMatriz(int** M, int K, int N);

int *getLinha(int** M, int linha);

int copiarMatriz(int** source, int** target, int K, int N);

int limparMatriz(int** M, int K);
