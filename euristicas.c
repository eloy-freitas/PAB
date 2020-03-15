#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int **euristicaConstrutiva(int N, int K, int** tki, int** ai, int** kXn, int** k, int** bi){
    int** Tki = criaMatriz(K,N);
    int** navios = criaMatriz(1,N);
    padronizarMatriz(navios,1,N,1);
    int i, j, candidato = 0;
    for(i = 0; i < K; i++){
        for(j = 0; j < N; j++){
            if(navios[j] == (int*)1 && ai[j] + tki[i][j] <= bi[i] && k[i][0] <= ai[i]){
                Tki[i][j] = bi[i] - tki[i];
                kXn[i][j] = 1;  
                break;
            }
        }
    }
    int aux = N;
    while(aux > 0){
        int sorteio = rand() % N;
        for(j = 0; j < K; j++){
            if(navios[sorteio] == (int*)1){
                Tki[j][sorteio] = (int) (bi[sorteio] - tki[j][sorteio]);
                aux--;
            }
        }
        
    }
    return Tki;
    
}