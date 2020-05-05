#define MAX 10000

int imprimirNaviosAtendidos(int N, int **ordem)
{
    int i;

    printf("Sequência de navios...: I --> ");
    for (i = 0; i < N; i++)
    {
        if (ordem[0][i] != MAX)
        {
            printf("%d --> ", ordem[0][i] + 1);
        }
        else
        {
            printf("F\n\n");
            break;
        }
    }

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

int bercoToString(int K, int N, int na, int ko, int kc, int violacao1, int violacao2, int fo, int **ordem)
{
    printf("Berço %d\n", K + 1);
    printf("Número de navios atendidos..................: %d\n", na);
    printf("Horário de abertura.........................: %d\n", ko);
    printf("Horário de fechamento.........................: %d\n", kc);
    printf("Total de viol. nas jan. de tempo dos berços.........: %d\n", violacao1);
    printf("Total de viol. nas jan. de tempo dos navios.........: %d\n", violacao2);
    printf("FO do berco.......................................: %d\n\n", fo);
    imprimirNaviosAtendidos(N, ordem);
    return 0;
}

int bercoProgramacaoToString(int berco, int navio, int **Tki, int **tki)
{
    int i, ha = 0, hd = 0;

    ha = Tki[berco][navio];
    hd = ha + tki[berco][navio];
    printf("\tNavio %d: \t\t HA: %d HD:%d\n", navio + 1, ha, hd);
    return 0;
}

int imprimirBercos(int K, int N, int **k, int **navios, int **Tki, int **tki, int **bi, int **ai, int **ordemNavios)
{

    int i, j, na = 0, v1 = 0, v2 = 0, fo = 0, total = 0, navio = 0;
    int **ordem = criaMatriz(1, N);
    for (i = 0; i < K; i++)
    {
        na = naviosAtendidosPorBerco(i, N, navios);
        v1 = violacoesJanelaTempoBerco(i, N, navios, Tki, k, tki);
        v2 = violacoesJanelaTempoNavios(i, N, navios, Tki, tki, bi);
        fo = calcularFOBerco(i, N, Tki, tki, ai, navios);
        total = total + fo;
        ordem = criarMatrizOrdemNaviosAtendidosBerco(i, N, Tki, navios);
        bercoToString(i, N, na, k[i][0], k[i][1], v1, v2, fo, ordem);
    }
    //imprimirMatriz(ordemNavios, 1, N);
    printf("Programação:\n\n");
    for (i = 0; i < K; i++)
    {
        printf("Berço %d\n", i + 1);
        printf("\tH. abertura: %d\n", k[i][0]);
        for (j = 0; j < N; j++)
        {
            navio = ordemNavios[0][j];
            if(navios[i][navio] == 1){
                 bercoProgramacaoToString(i, navio, Tki, tki);
            }
        }
        
        printf("\tH. fechamento: %d\n", k[i][1]);
        //printf("na = %d\t last = %d\n", na, last);
    }

    return 0;
}
