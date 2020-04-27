
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

/*Retorna uma matriz com todos vizinhos de acordo com a matriz navios*/
int*** criarVizinhos(int** navios, int K, int N, int qtdVizinhos)
{
    int*** vizinhos = (int***) malloc(qtdVizinhos*sizeof(int**)); 
    
    int i;

    for (i = 0; i < qtdVizinhos; i++)
    {
        vizinhos[i] = criaMatriz(K, N);
    }
    for (i = 0; i < qtdVizinhos; i++)
    {
        copiarMatriz(navios, vizinhos[i], K, N);
    }
    for (i = 0; i < qtdVizinhos; i++)
    {
        sortearVizinho(K, N, navios, vizinhos[i]);
    }

    return vizinhos;
}

/*Retorna o vizinho com o menor custo*/
int** procurarMelhorVizinho(int** Tki, int*** vizinhos, int qtdVizinhos, int K, int N, int somaNavios){
    
    int** soma = criaMatriz(1, qtdVizinhos);
    int i, j, p = 0;

    for (i = 0; i < qtdVizinhos; i++)
    {
        soma[0][i] = somarCustosDosNavios(Tki, vizinhos[i], N, K);
    }
    printf("Soma de entrada = %d \n", somaNavios);
    for(i = 0; i < qtdVizinhos; i++){
       if(somaNavios > soma[0][i]){
           somaNavios = soma[0][i];
           p = i;
       }
    }
    
    printf("Menor soma entre os vizinhos = %d\nMelhor vizinho = %d\n", somaNavios, p);
    
    return vizinhos[p];
}

int refinarVizinhos(int** Tki, int** navios,int qtdVizinhos, int K, int N, int somaNavios){
    //int*** melhoresVizinhos = (int***) malloc(qtdVizinhos*sizeof(int**)); 
    int*** vizinhos = criarVizinhos(navios, K, N, qtdVizinhos);
    procurarMelhorVizinho(Tki, vizinhos, qtdVizinhos, K, N, somaNavios);
    /*int** aux = criaMatriz(K, N);
    int i = 0;
    for(i = 0; i <  qtdVizinhos; i++){
        copiarMatriz(procurarMelhorVizinho(Tki, vizinhos, qtdVizinhos, K, N, somaNavios), melhoresVizinhos[i], K, N);
        copiarMatriz(melhoresVizinhos[i], navios, K, N);
        vizinhos = criarVizinhos(navios, K, N, qtdVizinhos);
        imprimirMatriz(melhoresVizinhos[i], K, N);
    }
    return 0;*/
}

