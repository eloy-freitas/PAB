#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#define MAX 10000

/*int refinarVizinhos(int K, int N, int** Tki, int berco){
    int** vizinhos = sortearVizinhos(K, N);
    int i, j, soma = 0, somaProx = 0, melhor = 0;
    soma = somarElementosDaLinha(Tki, vizinhos, N, berco, 0);
    for(i = 0; i < K; i++){
       for(j = 0; j < N; j++){
           if(vizinhos[i][j] == 1){
               somaProx = somarElementosDaLinha(Tki, vizinhos, N, ;
               if(soma > somaProx){
                   soma = somaProx;
                   melhor = i;
               }
           }
        }  
    }  
    printf("soma = %d \t melhor vizinho = %d", soma, melhor);
    return 0;
}*/



int somarElementosDaLinha(int** Tki, int** vizinhos, int N, int linhaTki, int linhaVizinhos){
    int i, result = 0; 
    for(i = 0; i < N; i++){
        if(vizinhos[linhaVizinhos][i] == 1){
            result = result + Tki[linhaTki][i];
        }
        
    }
    return result;
}

int mudarUmBit(int** navios, int linha, int N){
    int i = 0, j = 0, sorteio = 0;
    
    sorteio = rand() % N;
    if(navios[linha][sorteio] == 0){
        navios[linha][sorteio] = 1;
        
    } else{
        navios[linha][sorteio] = 0;
    }
    return 0;
}

int sortearTempoEspera(int K, int N, int** Tki){
    int i = 0, j = 0, sorteio = 0;
    srand( (unsigned)time(NULL));
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

int** sortearNaviosCandidatos(int K, int N)
{
    int i, j, sorteio, cont = 0;
    int **navios = criaMatriz(K, N);
    padronizarMatriz(navios, K, N, 0);
    srand( (unsigned)time(NULL) );
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < (N / K); j++)
        {   
            sorteio = rand() % N;
            navios[i][sorteio] = 1;
        }
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j <  K; j++)
        {   
            cont = cont + navios[j][i];
        }
        if(cont == 0){
            sorteio = rand() % K;
            navios[sorteio][i] = 1;
        }if(cont > 1){
            sorteio = rand() % K;
            navios[sorteio][i] = 0;
        }
        cont = 0;
    }

    return navios;
}

int** sortearVizinhos(int K, int N, int numVizinhos, int linha){
    int** navios = sortearNaviosCandidatos(K, N);
    int** vizinhos = criaMatriz(numVizinhos, N);
    padronizarMatriz(vizinhos, numVizinhos, N, 0);
   
     
    srand( (unsigned)time(NULL));
    int i, j;

    for(i = 0; i < numVizinhos; i++){
        for(j = 0; j < numVizinhos; j++){
            if(getLinha(navios, linha)[j] == 1){
                vizinhos[i][j] = 1;
            }   
        }       
    }  
     printf("antes de mudar um bit\n");
     imprimirMatriz(vizinhos, numVizinhos, N);
    for(i = 0; i < numVizinhos; i++){
        mudarUmBit(vizinhos, i, N);
        
    }  
    printf("depois de mudar um bit\n");
    imprimirMatriz(vizinhos, numVizinhos, N);
   
   
    return vizinhos;
}


int calcularFO(int K, int N, int **Tki, int **tki, int **ai)
{
    int i, j, result = 0;

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (Tki[i][j] != MAX)
            {
                Tki[i][j] = Tki[i][j] - ai[0][j];
            }
        }
    }

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (Tki[i][j] != MAX)
            {
                Tki[i][j] = Tki[i][j] + tki[i][j];
            }
        }
    }

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (Tki[i][j] != MAX)
            {
                result = result + Tki[i][j];
            }
        }
    }

    return result;
}
