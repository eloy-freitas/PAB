#include <stdio.h>
#include <stdlib.h>



int calcularFOBerco(int berco, int N, int **Tki, int **tki, int **ai, int **navios)
{
    int j, result = 0, fo = 0;

    for (j = 0; j < N; j++)
    {
        //printf("j = %d\t somaTki = %d\t somaAi = %d\t somatki = %d\t fo = %d\n",j, somaTki, somaAi, somatki, fo);
        if (navios[berco][j] == 1)
        {
            result = Tki[berco][j] - ai[0][j] + tki[berco][j];
            fo = fo + result;
        }
    }

    return fo;
}

/*Tem o objetivo de fazer o calculo da FO*/
int calcularFO(int K, int N, int **Tki, int **tki, int **ai, int **navios)
{
    int i, j, result = 0,fo = 0;
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N; j++)
        {
            //printf("j = %d\t somaTki = %d\t somaAi = %d\t somatki = %d\t fo = %d\n",j, somaTki, somaAi, somatki, fo);
            if (navios[i][j] == 1)
            {
                result = Tki[i][j] - ai[0][j] + tki[i][j];
                fo = fo + result;
            }
        }
    }

    return fo;
}

//Restrições

/*int R1(int** Tki, int** bi, int** tki, int N, int K){
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
}*/