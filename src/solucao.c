typedef struct solucao
{
    int id, na, bu, v1, v2, fo;
    clock_t tempo;
    int **navios;
    Berco** bercos;
} Solucao;

Solucao criarSolucao(int id, int K, int N, clock_t tempo, int **navios, int **Tki, int **tki, int **k, int **ai, int **bi, Berco** bercos)
{
    Solucao so;
    tempo = clock() - tempo;
    so.id = id;
    so.tempo = tempo;
    so.bu = bercosUsados(K, N, navios, Tki);
    so.v1 = totalViolacoesJanelaTempoBercos(K, N, navios, Tki, k, tki);
    so.na = naviosAtendidos(K, N, navios);
    so.v2 = totalViolacoesJanelaTempoNavios(K, N, navios, Tki, tki, bi);
    so.fo = calcularFO(K, N, Tki, tki, ai, navios);
    so.bercos = bercos;
    so.navios = navios;
    return so;
}

int imprimirSolucao(Solucao so)
{
    imprimirDadosSolucao(so.id, so.bu, so.na, so.tempo, so.v1, so.v2, so.fo);
    return 0;
}