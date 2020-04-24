#include "matriz.c"

int** criaMatriz(int k, int n);
int povoarMatriz(int **M, int k, int n);
int imprimirMatriz(int** M, int k, int n);
int zerarMatriz(int** M, int k, int n);
int padronizarMatriz(int** M, int k, int n, int inteiro);
int** somarMatrizes(int K, int N, int** A, int I, int J, int** B);
int* getLinha(int** M, int linha);