
/*Tem o objetivo de somar o peso total da combinação disposta na matriz navios lendo os valores do peso na matriz Tki*/
int somarCustosDosNaviosNoBerco(int linha, int N, int **navios, int **Tki)
{
    int soma = 0, j;

    for (j = 0; j < N; j++)
    {
        if (navios[linha][j] == 1)
        {
            soma = soma + Tki[linha][j];
        }
    }

    return soma;
}

/**/
int totalViolacoesJanelaTempoBercos(int K, int N, int **navios, int **Tki, int **k, int **tki)
{

    int violacoes = 0, i, j;
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (navios[i][j] == 1 && !(k[i][0] <= Tki[i][j] && Tki[i][j] <= k[i][1]) && !(k[i][0] <= Tki[i][j] + tki[i][j] && Tki[i][j] + tki[i][j] <= k[i][1]))
            {
                violacoes++;
            }
        }
    }

    return violacoes;
}

int totalViolacoesJanelaTempoNavios(int K, int N, int **navios, int **Tki, int **tki, int **bi)
{
    int violacoes = 0, i, j;

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (navios[i][j] == 1 && !(Tki[i][j] + tki[i][j] < bi[0][j]))
            {
                violacoes++;
            }
        }
    }
    return violacoes;
}

int violacoesJanelaTempoNavios(int berco, int N, int **navios, int **Tki, int **tki, int **bi)
{
    int violacoes = 0, i, j;

    for (j = 0; j < N; j++)
    {
        if (navios[berco][j] == 1 && !(Tki[berco][j] + tki[berco][j] < bi[0][j]))
        {
            violacoes++;
        }
    }

    return violacoes;
}

int bercosUsados(int K, int N, int **navios, int **Tki)
{
    int violacoes = 0, i, soma = 0;
    for (i = 0; i < K; i++)
    {
        soma = somarCustosDosNaviosNoBerco(i, N, navios, Tki);
        if (soma == 0)
        {
            violacoes++;
        }
    }
    return K - violacoes;
}

int naviosAtendidos(int K, int N, int **navios)
{
    int i, j, soma = 0;

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (navios[i][j] == 1)
            {
                soma = soma + navios[i][j];
            }
        }
    }

    return soma;
}

int naviosAtendidosPorBerco(int berco, int N, int **navios)
{
    int j, soma = 0;

    for (j = 0; j < N; j++)
    {
        soma = soma + navios[berco][j];
    }
    return soma;
}
/*
int violacoesJanelaTempoBerco(int berco, int N, int **navios, int **Tki, int **k, int **tki)
{

    int violacoes = 0, j;

    for (j = 0; j < N; j++)
    {
        if (navios[berco][j] == 1 && (k[berco][0] >= Tki[berco][j] && Tki[berco][j] >= k[berco][1]) && (k[berco][0] >= Tki[berco][j] + tki[berco][j] && Tki[berco][j] + tki[berco][j] >= k[berco][1]))
        {
            violacoes++;
        }
    }

    return violacoes;
}
*/
