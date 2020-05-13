#include "../src/berco.c"

Berco **criarBercos(int K, int N);
int povoarBercos(int K, int N, Berco **bercos, int **k, int **Tki, int **tki, int **ai, int **bi, int **navios);
int imprimirListaBercos(int K, int N, Berco **bercos);
int imprimirProgramacaoBercos(int K, int N, Berco **bercos, int **Tki, int **tki);