#include <stdio.h>
#include <stdlib.h>

int padronizarMatriz(int **M, int k, int n, int inteiro){
    int i, j;
    
    for(i = 0; i < k; i++){
        for(j = 0; j < n; j++){
            M[i][j] = inteiro;
            
        }
    }
    return 0;
} 

int** criaMatriz(int k, int n){
    int i = 0;
    int **M = (int**) malloc(k*sizeof(int*));
    for(i = 0; i < k; i++){
        M[i] = (int*) malloc(n*sizeof(int));
    }
    //padronizarMatriz(M, k, n, 0);
    return M;
}

int povoarMatriz(int **M, int k, int n){
    int valor = 0, i = 0, j = 0;
    for(i = 0; i < k; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &valor);
            M[i][j] = valor;
        }
    }
    return 0;
}

int imprimirMatriz(int** M, int k, int n){
    int i = 0, j = 0;
    for(i = 0; i < k; i++){
        for(j = 0; j < n; j++){
            printf("%d \t", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int* getLinha(int** M, int linha){
    return M[linha];
}










