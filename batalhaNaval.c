#include <stdio.h> 

int main(){
    //Letras para o topo do tabuleiro
    char linha [10]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    //Tabuleiro Matrix 10x10
    char tabuleiro[10][10] = {0};
    //Posicao dos navios
    int navio_horizontal[3] = {3,3,3};
    int navio_vertical[3] = {3,3,3};

    int linha_horizontal =2, coluna_horizontal = 4;
    for (int i = 0; i < 3; i++){
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }

    int linha_vertical = 5, coluna_vertical = 7;
    for (int i = 0; i < 3; i++){
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
    }

    //Imprimindo o cabeçalho do tabuleiro
    printf("Jogo de batalha naval\n");
    printf("  ");
    for (int j = 0; j < 10; j++){
        printf("%c ", linha [j]);
    }
    printf("\n");

    //Imprimindo o tabuleiro
    for (int i = 0; i < 10; i++)
    {
    printf("%2d ", i + 1);
            for(int j = 0; j < 10; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
        printf("\n");
    }

    return 0;
    
}
