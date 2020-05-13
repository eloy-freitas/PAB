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

int imprimirDadosSolucao(int K, int N, clock_t tempo, int violacao1, int violacao2, int fo)
{

    tempo = clock() - tempo;
    printf("\n< ----------------------------- SOLUÇÃO ---------------------------- >\n");
    printf("Número de berços utilizados.........................: %d\n", K);
    printf("Número de navios atendidos..........................: %d\n", N);
    printf("Tempo total de operação.............................: %ld\n", tempo);
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
    printf("FO do berço.......................................: %d\n\n", fo);
    imprimirNaviosAtendidos(N, ordem);
    return 0;
}

int bercoProgramacaoToString(int berco, int navio, int **Tki, int **tki)
{
    int ha = 0, hd = 0;

    ha = Tki[berco][navio];
    hd = ha + tki[berco][navio];
    printf("\t\tNavio %d: \t\t HA: %d HD:%d\n", navio + 1, ha, hd);
    return 0;
}

