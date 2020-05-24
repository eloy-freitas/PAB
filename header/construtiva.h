#include "../src/construtiva.c"

int calcularMatrizHoraAtracacao(int K, int N, int **Tki, int **ai, int **k, int **tki);
//int **criarMatrizOrdemNaviosAtendidosBerco(int berco, int N, int **Tki, int **navios);
int **criarMatrizOrdemNavios(int K, int N, int **Tki, int **navios);
int** sortearNaviosCandidatos(int K, int N, int** tki);
int **euristicaGulosa(int K, int N, int **Tki, int **tki, int ** ai, Berco **bercos);





