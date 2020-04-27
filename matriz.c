//Preencher todas as posições da matriz de entrada com um inteiro
int padronizarMatriz(int** M, int K, int N, int inteiro)
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
int** criaMatriz(int K, int N)
{
    int i = 0;
    int** M = (int** )malloc(K * sizeof(int *));
    for (i = 0; i < K; i++)
    {
        M[i] = (int *)malloc(N * sizeof(int));
    }
    //padronizarMatriz(M, k, n, 0);
    return M;
}
//preenche a matriz de entrada lendo a entrada
int povoarMatriz(int** M, int K, int N)
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
int imprimirMatriz(int** M, int K, int N)
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
int *getLinha(int** M, int linha)
{
    return M[linha];
}

//copia o conteúdo da matriz source para a target
int copiarMatriz(int** source, int** target, int K, int N)
{
    int i = 0, j = 0;
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (source[i][j] == 1)
            {
                target[i][j] = 1;
            }
            else
            {
                target[i][j] = 0;
            }
        }
    }
    return 0;
}

int limparMatriz(int** M, int K)
{
    int i = 0;
    for (i = 0; i < K; i++)
    {
        free(M[i]);
    }
    return 0;
}
