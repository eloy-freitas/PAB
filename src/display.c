#define MAX 10000

int imprimirNaviosAtendidos(int berco, int N, int **navios, int **Tki, int na)
{
    int **linha = criaMatriz(1, N);
    int **ordem = criaMatriz(1, N);

    copiarLinha(Tki, linha, berco, N);
    copiarLinha(Tki, ordem, berco, N);

    int i, j;
    for (i = 0; i < N; i++)
    {
        if (navios[berco][i] == 0)
        {
            ordem[0][i] = MAX;
            linha[0][i] = MAX;
        }
    }
    ordernarMatriz(ordem, 1, N);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (ordem[0][i] != MAX && (ordem[0][i] == linha[0][j]))
            {
                ordem[0][i] = j;
                linha[0][j] = MAX;
            }
        }
    }
    // imprimirMatriz(ordem, 1, N);

    printf("Sequência de navios...: I --> ");
    for (i = 0; i < N; i++)
    {
        if (ordem[0][i] != MAX)
        {
            printf("%d --> ", ordem[0][i]);
        }
        else
        {
            printf("F\n\n");
            break;
        }
    }

    limparMatriz(linha, 1);

    return 0;
}

int imprimirDadosSolucao(int K, int N, int tempo, int violacao1, int violacao2, int fo)
{

    printf("\n< ----------------------------- SOLUÇÃO ---------------------------- >\n");
    printf("Número de berços utilizados.........................: %d\n", K);
    printf("Número de navios atendidos..........................: %d\n", N);
    printf("Tempo total de operação.............................: %d\n", tempo);
    printf("Total de viol. nas jan. de tempo dos berços.........: %d\n", violacao1);
    printf("Total de viol. nas jan. de tempo dos navios.........: %d\n", violacao2);
    printf("FO da solução.......................................: %d\n\n", fo);

    return 0;
}

int bercoToString(int K, int na, int ko, int kc, int violacao1, int violacao2, int fo)
{
    printf("Berço %d\n", K + 1);
    printf("Número de navios atendidos..................: %d\n", na);
    printf("Horário de abertura.........................: %d\n", ko);
    printf("Horário de fechamento.........................: %d\n", kc);
    printf("Total de viol. nas jan. de tempo dos berços.........: %d\n", violacao1);
    printf("Total de viol. nas jan. de tempo dos navios.........: %d\n", violacao2);
    printf("FO do berco.......................................: %d\n\n", fo);

    return 0;
}

int imprimirBercos(int K, int N, int **k, int **navios, int **Tki, int **tki, int **bi, int **ai)
{

    int i, na = 0, v1 = 0, v2 = 0, fo = 0, total = 0;

    for (i = 0; i < K; i++)
    {
        na = naviosAtendidosPorBerco(i, N, navios);
        v1 = violacoesJanelaTempoBerco(i, N, navios, Tki, k, tki);
        v2 = violacoesJanelaTempoNavios(i, N, navios, Tki, tki, bi);
        fo = calcularFOBerco(i, N, Tki, tki, ai, navios);
        total = total + fo;
        bercoToString(i, na, k[i][0], k[i][1], v1, v2, fo);
        imprimirNaviosAtendidos(i, N, navios, Tki, na);
    }

    return 0;
}
