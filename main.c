
//#include "navios.h"
#include "euristicas.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int K, N;
    scanf("%d %d", &N, &K);
    if(K <= 20 && N <= 100){
        printf("aqui");
       int **kXn = criaMatriz(1,N); //matriz de controle de atendimento dos navios nos berços
       int **tki = criaMatriz(K,N); //matriz de tempo de atendimento do navio i no berço k
       int **ai = criaMatriz(1,N); //matriz de tempo previsto de chegada do navio i
       int **Tki = criaMatriz(K,N); //matriz de tempo de atracação do navio i no berço k (Construir com euristica de contrução)
       int **bi = criaMatriz(1,N); //matriz de tempo limite de espera para a partida do navio
       int **k = criaMatriz(K,2); //matriz de tempo de abertura e fechamento dos berços
        

       padronizarMatriz(kXn, K, N, 0);

       povoarMatriz(tki, K, N);
       povoarMatriz(k, K, 2);
       povoarMatriz(ai, 1, N);
       povoarMatriz(bi, 1, N);
       
       Tki = euristicaConstrutiva(N, K, tki, ai, kXn, k, bi);
       imprimirMatriz(Tki,K, N);
    }else{
        exit(0);
    }
    
    return 0;

}