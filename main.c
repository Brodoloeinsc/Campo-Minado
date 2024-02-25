#include <stdio.h>

int main(){

    // 0 ponto vazio
    // 1 ponto com bomba
    // 2 ponto marcado préviamente

    int campo[9][9], bombas[9][2];
    
    bombas[0][0] = rand() % (9 + 1 - 0) + 0;
    bombas[0][1] = rand() % (9 + 1 - 0) + 0;

    campo[bombas[0][0]][bombas[0][1]] = 1;

    return 0;
}