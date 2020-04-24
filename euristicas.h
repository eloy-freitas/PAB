#include "euristicas.c"

int calcularTempoEspera(int K, int N, int** Tki);
int calcularFO( int K, int N, int** Tki, int** tki, int** ai);
//int refinarVizinhos(int K, int N, int** Tki);
int** sortearVizinhos(int K, int N, int numVizinhos, int linha);
