#include <stdio.h>
#include <stdlib.h>

// Declarando as Structs
int criarCampo(int campo[9][9]);
int criarBombas(int campo[9][9], int bombas[9][2]);
int mostrarCampos(int campo[9][9]);
int result(resultado);

// Função Principal
int main(){

    int j, i, campo[9][9], bombas[9][2], resultado = 0, x, y, vitoria = 0;

    // Criando o campo completo
    criarCampo(campo);

    criarBombas(campo, bombas);

    printf("O Campo esta zerado, onde voce deseja jogar?\n");

    do{
        // Criando o Jogo
        mostrarCampos(campo);

        // Fazendo a jogada
        printf("Coordenadas X >>>");
        scanf("%d", &x);

        printf("Coordenadas Y >>>");
        scanf("%d", &y);

        // Conferindo o jogo
        if(campo[x][y] == 1){
            resultado = 1;
        }else if(campo[x][y] == 2){
            printf("Posicao ja ocupada, jogue novamente\n");
        }else{
            campo[x][y] = 2;
            vitoria += 1;
        }

        // Vendo se o jogo acabou
        if(vitoria ==  81){
            resultado = 2;
        }
    }while(resultado == 0);

    // Conferindo o resultado
    result(resultado);

    return 0;
}

// Funções do Jogo

// Gera o Campo Limpo
int criarCampo(int campo[9][9]){
    int i, j;
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            campo[i][j] = 0;
        }
    }
}

// Coloca bombas no campo
int criarBombas(int campo[9][9], int bombas[9][2]){
    int i;

    for(i = 0; i < 9; i++){
        bombas[i][0] = rand() % (9 + 1 - 0) + 0;
        bombas[i][1] = rand() % (9 + 1 - 0) + 0;

        if(campo[bombas[i][0]][bombas[i][1]] == 1){
            campo[bombas[i][0]+1][bombas[i][1]] = 1;
        }else{
            campo[bombas[i][0]][bombas[i][1]] = 1;
        }
    }
}

// Mostra o campo com as marcações
int mostrarCampos(int campo[9][9]){
    int i, j;
    
    printf("    0 1 2 3 4 5 6 7 8 \n");
    for(i = 0; i < 9; i++){
        printf("%d ", i);
        for(j = 0; j < 9; j++){
            if(campo[i][j] == 2){
                printf("X|");
            }else{
                printf(" |");
            }
        }
        printf("\n   -------------------\n");
    }
}

// Conferindo o Resultado
int result(int resultado){
    if(resultado == 1){
        printf("Nao foi dessa vez, porem tente novamente da proxima vez\n");
    }else if(resultado == 2){
        printf("Parabens, voce ganhou o jogo, deseja jogar novamente?\n");
    }
}