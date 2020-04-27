#include "construtiva.c"

int calcularTempoEspera(int K, int N, int** Tki);
int calcularFO(int K, int N, int** Tki, int** tki, int** ai, int** navios);
int sortearVizinho(int K, int N, int** navios, int** vizinho);
int corrigirMatrizNavios(int K, int N, int** navios);
int** sortearNaviosCandidatos(int K, int N);
int sortearTempoEspera(int K, int N, int** Tki);
int mudarUmBit(int** navios, int linha, int N);
int somarCustosDosNavios(int** Tki, int** navios, int N, int K);