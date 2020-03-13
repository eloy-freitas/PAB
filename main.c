#include "matriz.h"
#include "navios.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int b, n;
    scanf("%d %d", &n, &b);
   
    int **navios = criaMatriz(1,n);
    int **bercos = criaMatriz(1,b);
    int **tki = criaMatriz(b,n); //matriz de tempo de atendimento do navio i no berço k
    int **ai = criaMatriz(1,n); //matriz de tempo previsto de chegada do navio i
    int **Tki = criaMatriz(b,n); //matriz de tempo de atracação do navio i no berço k
    int **bi = criaMatriz(1,n); //matriz de tempo limite de espera para a partida do navio
    int **ok = criaMatriz(b,2); //matriz de tempo de abertura e fechamento dos berços
    
    povoarMatriz(Tki, b, n);
    povoarMatriz(ok, b, 2);
    povoarMatriz(ai, 1, n);
    povoarMatriz(bi, 1, n);

    imprimirMatriz(navios,b,n);
    imprimirMatriz(horariosDeAbertura,b,2);
    imprimirMatriz(vetorNavios,1,n);
    return 0;

}