#include <stdio.h>
#include <stdlib.h>


//Função Objetivo
int** calculaFO(int b, int n, int **Tki, int **ai, int **tki, int **bXn){
    int i, j, **fo, naviosAtendidos = 0;
    for(i = 0; i < b; i++){
        for(j = 0; i < n; j++){
            if(tki[i][j] > 0){
                fo[i][j] = TKi[i][j] - ai[i][j] + tki[i][j];
                bXn[i][j] = 1;
            }
        }
    }
    return fo;
}

//Restrições

int confereTodosNaviosAtendidos(int n, int naviosAtendidos){
  //Função referente a restrição 1 do trabalho
  if(n == naviosAtendidos){
    return 1;
  }else{
    return 0;     
  }
}

int confereNaviosAtendidosPorBerco(int** bXn ,int n, int b, int naviosAtendidos){
    //Função referente a restrição 2 do trabalho
    int i, j, cont = 0, qtdBerco = 0;
    for(i = 0; i < b, i++){
       for(j = 0; j < n; j++){
           if(bNx[i][j] == 1){
               cont++;
               naviosAtendidos++;
               qtdBerco++;
           }
           if(cont != 1){
               break;
           }else{
               cont = 0;
           }
       }
    }
    if(confereTodosNaviosAtendidos(n, naviosAtendidos) && 
    confereLimiteNaviosPorBerco(qtdBerco)){
       return 1;
    }else{
        return 0;
    }
}

int confereLimiteNaviosPorBerco(int qtdBerco){
    //Função referente a restrição 3
    if(qtdBerco > 1){
        return 1
    }else{
         return 0;
    }
}

int atracarNavio(int b, int n, int** Tk1, int** ai, int**bXn){
    int i, j;
    for(i = 0; i < n: i++){
        for(j = 0; j < n; j++){
            if(Tki[i][j] >= ai){
               bXn[i][j] = 1;
            }
        }
    }
}