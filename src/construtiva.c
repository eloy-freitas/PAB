#define MAX 10000

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


/*Essa função faz o cálculo da matriz Tki apartir da entrada*/
int calcularMatrizHoraAtracacao(int K, int N, int **Tki, int **ai, int **k, int **tki)
{
    int i, j, navio = 0, soma = 0, valor = 0;
    int **ak = criaMatriz(1, N);
    int **aj =  criaMatriz(1, N);

    copiarMatriz(ai, ak, 1, N);
    copiarMatriz(ai, aj, 1, N);
    ordernarMatriz(aj, 1, N);

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            valor = aj[0][j];
            navio = getColuna(ak, 0, N, valor);
            ak[0][navio] = MAX;
            // printf("navio = %d\n", valor);

            if (j == 0)                        //Se for o primeiro navio, a soma (referente ao horário em que o berço está ocupado) 
            {                                  
                if (ai[0][navio] < k[i][0])
                {
                    soma = soma + k[i][0];     //com o valor de abertura do berço, se o navio chegar antes que o berço abrir
                }
                if (ai[0][navio] > k[i][0])
                {
                    soma = soma + ai[0][navio]; //com o valor de chegada do navio, se ele chegar depois que o berço abrir
                }
                Tki[i][navio] = soma;           //automaticamente o primeiro navío recebe esse o valor da soma
                soma = soma + tki[i][navio];
            }
            else                                 //automaticamente o primeiro navío recebe esse o valor da soma
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
        //k[i][1] = soma;
        copiarMatriz(ai, ak, 1, N);
        soma = 0;
    }
    limparMatriz(ak, 1);
    return 0;
}

/*Tem o objetivo de corrigir a matriz de navios atendidos, caso um navio ocupe dois berços é feito um novo sorteio*/
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
                if (navios[k][i] == 1)
                {
                    navios[k][i] = 0;
                }
            }
            sorteio = rand() % K;
            navios[sorteio][i] = 1;
        }
        cont = 0;
    }
    return 0;
}

/*Retorna uma matriz com a ordem dos navios atendidos em cada berço*/
int **criarMatrizOrdemNaviosAtendidosBerco(int berco, int N, int **Tki, int **navios)
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
    //imprimirMatriz(ordem, 1, N);
    return ordem;
}

/*Tem o objetivo de criar um vetor com a ordem de atendimento de todos os navios
/*int **criarMatrizOrdemNavios(int K, int N, int **Tki, int **navios)
{
    int **ordemNavios = criaMatriz(1, N);
    padronizarMatriz(ordemNavios, 1, N, MAX);
    int **ordem = criaMatriz(1, N);

    int i, j, l = 0, na, last = 0;
    for (i = 0; i < K; i++)
    {
        ordem = criarMatrizOrdemNaviosAtendidosBerco(i, N, Tki, navios);
        na = naviosAtendidosPorBerco(i, N, navios);
        while (ordemNavios[0][last] != MAX)
        {
            last++;
        }
        for (j = last; j < last + na; j++)
        {
            ordemNavios[0][j] = ordem[0][l];
            l++;
        }
        l = 0;
    }

    // imprimirMatriz(ordemNavios, 1, N);
    return ordemNavios;
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