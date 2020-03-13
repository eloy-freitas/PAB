#include <stdio.h>
#include <stdlib.h>

int** calculaFO(int b, int n, **int Tki, **int ai, **int tki){
    int i, j, **fo;
    for(i = 0; i < b; i++){
        for(j = 0; i < n; j++){
            if(tki[i][j] != 0){
                fo[i][j] = TKi[i][j] - ai[i][j] + tki[i][j];
            }
        }
    }
    return fo;
}

