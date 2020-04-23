#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#define MAX 10000

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

int calcularTempoEspera(int K, int N, int** Tki){
    int** navios = sortearNaviosCandidatos(K, N);
    int i, j;
    for(i = 0; i < K; i++){
        for(j = 0; j < N; j++){
            if(navios[i][j] == 0){
                Tki[i][j] = 0;
            }      
        }
    }  
    return 0;
}
/*
int** calcularTempoServico(int K, int N, int** Tki, int** tki){
    int** soma = criaMatriz(K,N);
    int i, j;
    for(i = 0; i < K; i++){
        for(j = 0; j < N; j++){
            if(Tki[i][j] != 0){
                soma[i][j] = Tki[i][j] + tki[i][j];
            }      
        }
    }  
    return soma;
}*/

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
