#include <stdio.h>
#include <stdlib.h>

int **criaMatriz(int b, int n){
    int i = 0;
    int **M = (int**) malloc(b*sizeof(int*));
    for(i = 0; i < b; i++){
        M[i] = (int*) malloc(n*sizeof(int));
    }
    return M;
}

int zerarMatriz(int** M, int b, int n){
    for(i = 0; i < b; i++){
        for(j = 0; j < n; j++){
            M[i][j] = 0;
        }
    }
    return 0;
} 

int povoarMatriz(int **M, int b, int n){
    int valor = 0, i = 0, j = 0;
    for(i = 0; i < b; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &valor);
            M[i][j] = valor;
        }
    }
    return 0;
}

int imprimirMatriz(int** M, int b, int n){
    int i = 0, j = 0;
    for(i = 0; i < b; i++){
        for(j = 0; j < n; j++){
            printf("%d \t", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}



