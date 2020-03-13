#include "navios.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int b, n;
    scanf("%d %d", &n, &b);
   
    int **navios = criaMatriz(b,n);
    int **horariosDeAbertura = criaMatriz(b,2);
    int **vetorNavios = criaMatriz(1,n);
    povoarMatriz(navios,b,n);
    povoarMatriz(horariosDeAbertura,b,2);
    povoarMatriz(vetorNavios,1,n);
    imprimirMatriz(navios,b,n);
    imprimirMatriz(horariosDeAbertura,b,2);
    imprimirMatriz(vetorNavios,1,n);
    return 0;

}