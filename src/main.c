
//#include "header/navios.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../header/matriz.h"
#include "../header/problema.h"

#include "../header/display.h"
//#include "../header/navio.h"
#include "../header/violacoes.h"
#include "../header/berco.h"
#include "../header/construtiva.h"
#include "../header/solucao.h"
//#include "../header/menu.h"

//#include "header/refinamento.h"

int main()
{
    int K, N, i;
    clock_t t;
    srand((unsigned)time(NULL));
    scanf("%d %d", &N, &K);
    if (K <= 20 && N <= 100)
    {
        t = clock();

        printf("Criando matriz de tempo de atendimento dos navios em cada berço...\n");
        int **tki = criaMatriz(K, N); //matriz de tempo de atendimento do navio i no berço k
        printf("Criando matriz de tempo previsto de chegada de cada navio...\n");
        int **ai = criaMatriz(1, N); //matriz de tempo previsto de chegada do navio i
        printf("Criando matriz de matriz de horário de atracação...\n");
        int **Tki = criaMatriz(K, N); //matriz de horário de atracação do navio i no berço k (Construir com euristica de contrução)
        printf("Criando matriz de tempo limite de espera...\n");
        int **bi = criaMatriz(1, N); //matriz de tempo limite de espera para a partida do navio
        printf("Criando matriz de tempo de abertura e fechamento dos berços...\n");
        int **k = criaMatriz(K, 2); //matriz de tempo de abertura e fechamento dos berços

        printf("Lendo instancia...\n");
        printf("Berços = %d\t Navios = %d\n", K, N);
        povoarMatriz(tki, K, N);
        povoarMatriz(k, K, 2);
        povoarMatriz(ai, 1, N);
        povoarMatriz(bi, 1, N);

        /*printf("Imprimindo matrizes do arquivo...\n");
        printf("Quantidade de Navios = %d\tQuantidade de berços = %d\n", N, K);
        printf("Matriz tki\n");
        imprimirMatriz(tki, K, N);
        printf("Matriz k\n");
        imprimirMatriz(k, K, 2);
        printf("Matriz ai\n");
        imprimirMatriz(ai, 1, N);
        printf("Matriz bi\n");
        imprimirMatriz(bi, 1, N);*/

        printf("Calculando matriz de horário de atracação...\n");
        calcularMatrizHoraAtracacao(K, N, Tki, ai, k, tki);
       
        int **navios = criaMatriz(K, N);
        Berco **bercos = criarBercos(K, N);

        navios = euristicaGulosa(K, N, Tki, tki, ai, bercos);
        Solucao so = criarSolucao(1, K, N, t, navios, Tki, tki, k, ai, bi, bercos);
        povoarBercos(K, N, bercos, k, Tki, tki, ai, bi, navios);

        imprimirSolucao(so);
        imprimirListaBercos(K, N, bercos);
        imprimirProgramacaoBercos(K, N, bercos, Tki, tki);
        //painel(K, N, Tki, tki, ai, bi, k, t);
        //printf("Imprimindo Tki...\n");
        //imprimirMatriz(Tki, K, N);
    }
    else
    {
        exit(0);
    }

    return 0;
}