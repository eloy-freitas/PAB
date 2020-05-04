
//#include "header/navios.h"
#include <stdio.h>
#include <stdlib.h>
#include "../header/matriz.h"
#include "../header/problema.h"
#include "../header/violacoes.h"
#include "../header/construtiva.h"
#include "../header/display.h"





//#include "header/refinamento.h"

int main()
{
    int K, N;
    srand((unsigned)time(NULL));
    scanf("%d %d", &N, &K);
    if (K <= 20 && N <= 100)
    {
        printf("Criando matriz de controle de navios...\n");
        int **navios = criaMatriz(K, N); //matriz de controle de atendimento dos navios nos berços
        printf("Criando matriz de tempo de atendimento dos em cada berço navios...\n");
        int **tki = criaMatriz(K, N); //matriz de tempo de atendimento do navio i no berço k
        printf("Criando matriz de tempo previnsto de chegada...\n");
        int **ai = criaMatriz(1, N); //matriz de tempo previsto de chegada do navio i
        printf("Criando matriz de matriz de tempo de atracação...\n");
        int **Tki = criaMatriz(K, N); //matriz de tempo de atracação do navio i no berço k (Construir com euristica de contrução)
        printf("Criando matriz de tempo limite de espera...\n");
        int **bi = criaMatriz(1, N); //matriz de tempo limite de espera para a partida do navio
        printf("Criando matriz de tempo de abertura e fechamento dos berços...\n");
        int **k = criaMatriz(K, 2); //matriz de tempo de abertura e fechamento dos berços

        printf("Lendo arquivo...\n");
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

        printf("Calculando matriz Tki...\n");

        int **aj = criaMatriz(1, N);
        copiarMatriz(ai, aj, 1, N);

        ordernarMatriz(aj, 1, N);
        calcularMatrizHoraAtracacao(K, N, Tki, ai, aj, k, tki);
        limparMatriz(aj, 1);

       /* printf("Imprimindo Tki...\n");
        imprimirMatriz(Tki, K, N);*/

        printf("Criando uma solução inicial para Tki\n");
        navios = sortearNaviosCandidatos(K, N);
        corrigirMatrizNavios(K, N, navios);
        int fo = calcularFO(K, N, Tki, tki, ai, navios);
  
        /*printf("Matriz navios\n");
        imprimirMatriz(navios, K, N);*/

        int bu = bercosUsados(K, N, navios, Tki);
        int v1 = totalViolacoesJanelaTempoBercos(K, N, navios, Tki, k, tki);
        int na = naviosAtendidos(K, N, navios);
        int v2 = totalViolacoesJanelaTempoNavios(K, N, navios, Tki, tki, bi);

        imprimirDadosSolucao(bu, na, 0, v1, v2, fo);
        imprimirBercos(K, N, k, navios, Tki, tki, bi, ai);
        criarMatrizOrdemNavios(K, N, Tki, navios);
       

        /*
        int soma = somarCustosDosNavios(Tki, navios, N, K);
        int qtdVizinhos = 10;
        

        int*** vizinhos = (int***) malloc(qtdVizinhos*sizeof(int**));
        printf("Criando vetor de vizinhos(total de vizinhos = %d)...\n", qtdVizinhos);
        printf("Imprimindo vizinhos...\n");
        vizinhos = criarVizinhos(navios, K, N, qtdVizinhos);
      
        printf("Procurando melhor vizinho...\n");
        procurarMelhorVizinho(Tki, vizinhos, qtdVizinhos, K, N, soma);
        //calcularTempoEspera(K, N, Tki);
        //imprimirMatriz(Tki, K, N);*/
    }
    else
    {
        exit(0);
    }

    return 0;
}