#include <stdio.h>
#include <stdlib.h>
#define Tamanhohabilidade 5
#define centrodahabilidade 2

int main() {

    // Letras para o topo do tabuleiro
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    // Tabuleiro Matriz 10x10
    char tabuleiro[10][10] = {0};
    
    // Posição dos navios
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Matrizes das habilidades
    int cone[Tamanhohabilidade][Tamanhohabilidade];
    int cruz[Tamanhohabilidade][Tamanhohabilidade];
    int octaedro[Tamanhohabilidade][Tamanhohabilidade];
    int centro = Tamanhohabilidade / 2;

    // Cruz
    printf("Cruz\n");
    for (int i = 0; i < Tamanhohabilidade; i++) {
        for (int j = 0; j < Tamanhohabilidade; j++) {
            if (i == centro || j == centro) { // Preenche a cruz
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0; // Preenche o resto com 0
            }
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }

    // Cone 
    printf("Cone\n");
    for (int i = 0; i < Tamanhohabilidade; i++) {
        for (int j = 0; j < Tamanhohabilidade; j++) {
            if (i >= centro && j >= centro - (i - centro) && j <= centro + (i - centro)) {
                cone[i][j] = 1; // Preenche a parte do cone
            } else {
                cone[i][j] = 0; // Preenche o resto com 0
            }
            printf("%d ", cone[i][j]);  
        }
        printf("\n");
    }

    // Octaedro
    printf("Octaedro\n");
    for (int i = 0; i < Tamanhohabilidade; i++) {
        for (int j = 0; j < Tamanhohabilidade; j++) {
            // Condição para formar o octaedro criando o padrão de losango
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1; // Preenche a área do octaedro
            } else {
                octaedro[i][j] = 0; // Preenche o resto com 0
            }
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }
   
    int linha_horizontal = 2, coluna_horizontal = 4;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }

    int linha_vertical = 5, coluna_vertical = 7;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
    }

    // Começa em (1,1)
    int inicio_diag1 = 1;
    for (int i = 0; i < 3; i++) {
        int l = inicio_diag1 + i;
        int c = inicio_diag1 + i;

        // Só coloca o navio se a posição estiver vazia
        if (tabuleiro[l][c] == 0) {
            tabuleiro[l][c] = 3;
        }
    }

    int linha_diag2 = 0, coluna_diag2 = 3;
    for (int i = 0; i < 3; i++) {
        int l = linha_diag2 + i;
        int c = coluna_diag2 - i;
        if (tabuleiro[l][c] == 0) {
            tabuleiro[l][c] = 3;
        }
    }

    // Imprimindo o cabeçalho do tabuleiro
    printf("Jogo de batalha naval\n");
    printf("  ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", linha[j]);
    }
    printf("\n");

    // Imprimindo o tabuleiro 
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
