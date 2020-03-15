#include <stdio.h>
#include <stdlib.h>

//Função Objetivo
int** calculaFO(int b, int n, int **Tki, int **ai, int **tki, int **bXn){
    int i, j, **fo;
    for(i = 0; i < b; i++){
        for(j = 0; i < n; j++){
            if(tki[i][j] > 0){
                fo[i][j] = TKi[i][j] - ai[i][j] + tki[i][j];
            }
        }
    }
    return fo;
}

//Restrições


int R1(int** Tki, int** bi, int** tki, int N, int K){
    //Restrição 1: tki + Tki <= bi
    int i, j, valor = 0;
    for(i = 0; i < K; i++){
        for(j = 0; j < N; j++){
            if(tki[i][j] + Tki[i][j] <= bi[i]){
                valor = 1;
            }
        }
    }
    return valor;
}

int R2(int** Tki, int** ai, int N, int K){
    //Restrição 2: Trk >= ai
    int i, j, valor = 0;
    for(i = 0; i < K; i++){
        for(j = 0; j < N; j++){
            if(Tki[i][j] >= ai[i]){
                valor = 1;
            }
        }
    }
    return valor;
}

int R3(int** Tki, int** k, int** tki,int N, int K){
    //Restrição 3: ok <= Tki <= ck 
    int i, j, valor = 0;
    for(i = 0; i < K; i++){
        for(j = 0; j < N; j++){
            if(!(k[i][0] <= Tki[i][j] && Tki[i][j] <= k[i][1])){
                valor = 1;
            }
        }
    }
    return valor;

int R4(int** Tki, int** k, int** tki,int N, int K){
    //Restrição 4: ok <= Tki + tki <= ck
    int i, j, valor = 0;
    for(i = 0; i < K; i++){
        for(j = 0; j < N; j++){
            if(!(k[i][0] <= Tki[i][j] + tki[i][j] && Tki[i][j] + tki[i][j] <= k[i][1])){
                valor = 1;
            }
        }
    }
    return valor;
}