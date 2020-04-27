


/*Tem o objetivo de somar o peso total da combinação disposta 
na matriz navios lendo os valores do peso na matriz Tki*/
int somarCustosDosNavios(int** Tki, int** navios, int N, int K)
{
    int i, j, result = 0;
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (navios[i][j] == 1)
            {
                result = result + Tki[i][j];
            }
        }
    }
    return result;
}
/*Tem o objetivo de mudar 1 bit aleatório na linha da 
matriz navios de N colunas passados por parâmetros*/
int mudarUmBit(int** navios, int linha, int N)
{
    int i = 0, j = 0, sorteio = 0;

    sorteio = rand() % N;
    //printf("sorteio= %d\n", sorteio);
    if (navios[linha][sorteio] == 0)
    {
        navios[linha][sorteio] = 1;
    }
    else
    {
        navios[linha][sorteio] = 0;
    }
    return 0;
}


/*Tem o objetivo de mudar 2 bits aleatórios na linha da 
matriz navios de N colunas passados por parâmetros*/
int mudarDoisBits(int** navios, int linha, int N)
{
    int i = 0, j = 0, sorteio1 = 0, sorteio2 = 0;

    sorteio1 = rand() % N;
    sorteio2 = rand() % N;
    while(sorteio1 == sorteio2){
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
}

/*Tem o objetivo de povoar a matriz Tki com números aleatórios de 1 a 200*/
int sortearTempoEspera(int K, int N, int** Tki)
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
}

/*Tem o objetivo de sortear os N navios para os K berços*/
int** sortearNaviosCandidatos(int K, int N)
{
    int i, j, sorteio, cont = 0;
    int** navios = criaMatriz(K, N);
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
int corrigirMatrizNavios(int K, int N, int** navios)
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
/*Tem o objetivo de copiar a matriz navios e salvar na matriz vizinho. 
Em seguida cada linha muda 1 bit de valor na matriz vizinho */
int sortearVizinho(int K, int N, int** navios, int** vizinho)
{

    int i, j;

    copiarMatriz(navios, vizinho, K, N);

    for (i = 0; i < K; i++)
    {
        mudarUmBit(vizinho, i, N);
    }

    return 0;
}
