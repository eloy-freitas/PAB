#include "../src/violacoes.c"

int bercosUsados(int K, int N, int **navios, int **Tki);
int naviosAtendidosPorBerco(int berco, int N, int **navios);
int naviosAtendidos(int K, int N, int **navios);
int violacoesJanelaTempoBerco(int berco, int N, int **navios, int **Tki, int **k, int **tki);
int totalViolacoesJanelaTempoBercos(int K, int N, int **navios, int **Tki, int **k, int **tki);
int violacoesJanelaTempoNavios(int berco, int N, int **navios, int **Tki, int **tki, int **bi);
int totalViolacoesJanelaTempoNavios(int K, int N, int **navios, int **Tki, int **tki, int **bi);
