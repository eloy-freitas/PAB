
//#include "navios.h"
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "construtiva.h"
#include "refinamento.h"

int main()
{
    int K, N;
    srand((unsigned)time(NULL));
    scanf("%d %d", &N, &K);
    if (K <= 20 && N <= 100)
    {
        int **navios = criaMatriz(K, N); //matriz de controle de atendimento dos navios nos berços
        int **tki = criaMatriz(K, N);    //matriz de tempo de atendimento do navio i no berço k
        int **ai = criaMatriz(1, N);     //matriz de tempo previsto de chegada do navio i
        int **Tki = criaMatriz(K, N);    //matriz de tempo de atracação do navio i no berço k (Construir com euristica de contrução)
        int **bi = criaMatriz(1, N);     //matriz de tempo limite de espera para a partida do navio
        int **k = criaMatriz(K, 2);      //matriz de tempo de abertura e fechamento dos berços

        //padronizarMatriz(kXn, K, N, 0);

        povoarMatriz(tki, K, N);
        povoarMatriz(k, K, 2);
        povoarMatriz(ai, 1, N);
        povoarMatriz(bi, 1, N);
        

        /*imprimirMatriz(tki,K, N);
       imprimirMatriz(k,K, 2);
       printf("matriz ai\n");
       imprimirMatriz(ai,1, N);
       imprimirMatriz(bi,1, N);*/
       
        sortearTempoEspera(K, N, Tki);
        navios = sortearNaviosCandidatos(K, N);
        corrigirMatrizNavios(K, N, navios);

        int soma = somarCustosDosNavios(Tki, navios, N, K);
        int qtdVizinhos = 10;
        printf("navios\t soma = %d\n", soma);
        imprimirMatriz(navios, K, N);

        

        refinarVizinhos(Tki, navios, qtdVizinhos, K, N, soma);
        //calcularTempoEspera(K, N, Tki);
        //imprimirMatriz(Tki, K, N);
    }
    else
    {
        exit(0);
    }

    return 0;
}