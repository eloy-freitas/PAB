#define MAX 10000

int calcularMatrizHoraAtracacao(int K, int N, int **Tki, int **ai, int **aj, int **k, int **tki)
{
    int i, j, navio = 0, soma = 0, valor = 0;
    int** ak = criaMatriz(1,N);
    copiarMatriz(ai, ak, 1, N);

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            valor = aj[0][j];
            navio = getColuna(ak, 0, N, valor);
            ak[0][navio] = MAX;
            // printf("navio = %d\n", valor);

            if (j == 0)
            {
                if (ai[0][navio] < k[i][0])
                {
                    soma = soma + k[i][0];
                }
                if (ai[0][navio] > k[i][0])
                {
                    soma = soma + ai[0][navio];
                }
                Tki[i][navio] = soma;
                soma = soma + tki[i][navio];
            }
            else
            {

                if (ai[0][navio] > soma)
                {
                    Tki[i][navio] = ai[0][navio];
                    soma = soma + tki[i][navio];
                }
                else
                {
                    Tki[i][navio] = soma;
                    soma = soma + tki[i][navio];
                }
            }
            
            //printf("soma = %d, navio = %d, tki = %d\n", soma, navio, tki[i][navio]);
        }
        copiarMatriz(ai, ak, 1, N);
        soma = 0;
    }
    limparMatriz(ak, 1);
    return 0;
}

/*Tem o objetivo de sortear os N navios para os K berços*/
int **sortearNaviosCandidatos(int K, int N)
{
    int i, j, sorteio;
    int **navios = criaMatriz(K, N);
    padronizarMatriz(navios, K, N, 0);

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < (N / K); j++)
        {
            sorteio = rand() % N;
            navios[i][sorteio] = 1;
        }
    }

    return navios;
}

/*Tem o objetivo de corrigir a matriz navios, caso um navio ocupe dois berços*/
int corrigirMatrizNavios(int K, int N, int **navios)
{
    int i, j, k, sorteio, cont = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < K; j++)
        {
            cont = cont + navios[j][i];
        }
        if (cont == 0)
        {
            sorteio = rand() % K;
            navios[sorteio][i] = 1;
        }
        if (cont > 1)
        {
            for (k = 0; k < K; k++)
            {
                if (k == 1)
                {
                    navios[k][i] = 0;
                    break;
                }
            }
        }
        cont = 0;
    }
    return 0;
}



/*Tem o objetivo de povoar a matriz Tki com números aleatórios de 1 a 200
int sortearTempoEspera(int K, int N, int **Tki)
{
    int i = 0, j = 0, sorteio = 0;

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            sorteio = rand() % 200;
            Tki[i][j] = sorteio;
        }
    }
    return 0;
}*/

/*Tem o objetivo de mudar 2 bits aleatórios na linha da 
matriz navios de N colunas passados por parâmetros
int mudarDoisBits(int **navios, int linha, int N)
{
    int i = 0, j = 0, sorteio1 = 0, sorteio2 = 0;

    sorteio1 = rand() % N;
    sorteio2 = rand() % N;
    while (sorteio1 == sorteio2)
    {
        sorteio2 = rand() % N;
    }
    //printf("sorteio= %d\n", sorteio);
    if (navios[linha][sorteio1] == 0)
    {
        navios[linha][sorteio1] = 1;
    }
    else
    {
        navios[linha][sorteio1] = 0;
    }

    if (navios[linha][sorteio2] == 0)
    {
        navios[linha][sorteio2] = 1;
    }
    else
    {
        navios[linha][sorteio2] = 0;
    }
    return 0;
}*/