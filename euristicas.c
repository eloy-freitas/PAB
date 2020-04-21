#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#define MAX 10000

int **buscarPrimeirosNavios(int K, int N, int **ai)
{
    int i, j, aux1 = ai[0][0], aux2 = ai[0][1], p1 = 0, p2 = 1;
    int **vet = criaMatriz(1, K);
    //printf("aux1 = %d, p1 = %d, aux2 = %d, p2 = %d\n", aux1, vet[0][0], aux2, vet[0][1]);
    for (i = 0; i < K; i++){
        for (j = 0; j < N; j++){
            if (aux2 >= ai[0][j])
            {
                aux1 = aux2;
                aux2 = ai[0][j];
                p1 = p2;
                p2 = j;
               // printf("aux1 = %d, p1 = %d, aux2 = %d, p2 = %d, i = %d, j = %d\n", aux1, p1, aux2, p2, i, j);
            }
        }
        vet[0][i] = p1;
        vet[0][i + 1] = p2;
        aux2 = MAX;
        ai[0][p1] = MAX;
        ai[0][p2] = MAX;
        
    }
    return vet;
}

int euristicaConstrutiva(int K, int N, int **tki, int **ai)
{
    int **Tki = criaMatriz(K, N);
    //int **navios = criaMatriz(1, N);
    int **vet = buscarPrimeirosNavios(K, N, ai);
    imprimirMatriz(vet,1,K);
    return 0;
}

/*
int** calcularTempoEspera(int K, int N, int** Tki, int** ai){
    int** sub = criaMatriz(K,N);
    int i, j;
    for(i = 0; i < K; i++){
        for(j = 0; j < N; j++){
            if(Tki[i][j] != 0){
                sub[i][j] = Tki[i][j] - *ai[j];
            }      
        }
    }  
    return sub;
}

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
}

int calcularFO(int** soma, int** sub, int K, int N){
    int i, j, result = 0;;
    for(i = 0; i < K; i++){
        for(j = 0; j < N; j++){
            result += soma[i][j] + sub[i][j];     
        }
    }  
    return result;
}
*/