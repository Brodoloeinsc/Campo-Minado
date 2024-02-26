#include <stdio.h>
#include <stdlib.h>

int main(){

    // 0 ponto vazio
    // 1 ponto com bomba
    // 2 ponto marcado préviamente

    int j, i, campo[9][9], bombas[9][2], resultado = 0, x, y, vitoria = 0;

    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            campo[i][j] = 0;
        }
    }

    for(i = 0; i < 9; i++){
        bombas[i][0] = rand() % (9 + 1 - 0) + 0;
        bombas[i][1] = rand() % (9 + 1 - 0) + 0;

        if(campo[bombas[i][0]][bombas[i][1]] == 1){
            campo[bombas[i][0]+1][bombas[i][1]] = 1;
        }else{
            campo[bombas[i][0]][bombas[i][1]] = 1;
        }
    }

    printf("O Campo esta zerado, onde voce deseja jogar?\n");

    do{
        printf("    0 1 2 3 4 5 6 7 8 \n");
        for(i = 0; i < 9; i++){
            printf("%d ", i);
            for(j = 0; j < 9; j++){
                printf(" |");
            }
            printf("\n   -------------------\n");
        }
        printf("Coordenadas X >>>");
        scanf("%d", &x);

        printf("Coordenadas Y >>>");
        scanf("%d", &y);

        if(campo[x][y] == 1){
            resultado = 1;
        }else if(campo[x][y] == 2){
            printf("Posicao ja ocupada, jogue novamente\n");
        }else{
            campo[x][y] = 2;
            vitoria += 1;
        }

        if(vitoria ==  81){
            resultado = 2;
        }

    }while(resultado == 0);

    if(resultado == 1){
        printf("Nao foi dessa vez, porem tente novamente da proxima vez\n");
    }else if(resultado == 2){
        printf("Parabens, voce ganhou o jogo, deseja jogar novamente?\n");
    }

    return 0;
}