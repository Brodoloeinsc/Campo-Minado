#include <stdio.h>

int main(){

    // 0 ponto vazio
    // 1 ponto com bomba
    // 2 ponto marcado préviamente

    int j, i, campo[9][9], bombas[9][2];

    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            campo[i][j] = 0;
        }
    }

    for(i = 0; i < 9; i++){
        bombas[i][0] = rand() % (9 + 1 - 0) + 0;
        bombas[i][1] = rand() % (9 + 1 - 0) + 0;

        campo[bombas[i][0]][bombas[i][1]] = 1;
    }

    

    return 0;
}