//Preencher todas as posições da matriz de entrada com um inteiro
int padronizarMatriz(int **M, int K, int N, int inteiro)
{
    int i, j;

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            M[i][j] = inteiro;
        }
    }
    return 0;
}
//aloca espaço para uma matriz de ordem K por N
int **criaMatriz(int K, int N)
{
    int i = 0;
    int **M = (int **)malloc(K * sizeof(int *));
    for (i = 0; i < K; i++)
    {
        M[i] = (int *)malloc(N * sizeof(int));
    }
    //padronizarMatriz(M, k, n, 0);
    return M;
}
//preenche a matriz de entrada lendo a entrada
int povoarMatriz(int **M, int K, int N)
{
    int valor = 0, i = 0, j = 0;
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &valor);
            M[i][j] = valor;
        }
    }
    return 0;
}

//imprime a matriz
int imprimirMatriz(int **M, int K, int N)
{
    int i = 0, j = 0;
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d \t", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

//retorna a linha da matriz
int *getLinha(int **M, int linha)
{
    return M[linha];
}

//copia o conteúdo da matriz source para a target
int copiarMatriz(int **source, int **target, int K, int N)
{
    int i = 0, j = 0;
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            target[i][j] = source[i][j];
        }
    }
    return 0;
}

int limparMatriz(int **M, int K)
{
    int i = 0;
    for (i = 0; i < K; i++)
    {
        free(M[i]);
    }
    return 0;
}

int ordernarMatriz(int **M, int K, int N)
{
    int i, j, aux = 0, cont = 0;

    for (i = 0; i < K; i++)
    {
        while (cont < N)
        {
            for (j = 0; j < N; j++)
            {
                if (M[i][j] > M[i][j + 1])
                {
                    aux = M[i][j];
                    M[i][j] = M[i][j + 1];
                    M[i][j + 1] = aux;
                    if(j == N - 1){
                        M[i][j] = aux;
                    }
                    //printf("aux = %d\t M[%d][%d] = %d \n", aux, i, j, M[i][j]);
                }
            }
            
            cont++;
        }
    }
    return 0;
}

int getColuna(int **M, int K, int N, int valor){
    int i, aux = 0;
    
    for (i = 0; i < N; i++)
    {
       if(M[K][i] == valor){
           aux = i;
           break;
       }
    }
    
    return aux;
}

/*Tem o objetivo de mudar 1 bit aleatório na linha da 
matriz navios de N colunas passados por parâmetros*/
int mudarUmBit(int **navios, int linha, int N)
{
    int sorteio = 0;

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
