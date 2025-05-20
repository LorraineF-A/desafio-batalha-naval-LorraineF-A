#include <stdio.h>
#include <stdbool.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Nível Novato - Posicionamento dos Navios

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com 0s (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
} 

// Função para verificar se a posição do navio é válida
bool posicaoValida(int linha, int coluna, int tamanho, bool vertical, int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Verifica se está dentro dos limites do tabuleiro
    if (vertical) {
        if (linha + tamanho - 1 >= TAMANHO_TABULEIRO) return false;
    } else {
        if (coluna + tamanho - 1 >= TAMANHO_TABULEIRO) return false;
    }
    
    // Verifica se não há sobreposição com outros navios
    for (int i = 0; i < tamanho; i++) {
        if (vertical) {
            if (tabuleiro[linha + i][coluna] != 0) return false;
        } else {
            if (tabuleiro[linha][coluna + i] != 0) return false;
        }
    }
    
    return true;
} 

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, bool vertical) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (vertical) {
            tabuleiro[linha + i][coluna] = 3;
        } else {
            tabuleiro[linha][coluna + i] = 3;
        }
    }
} 

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
} 

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro com água (0s)
    inicializarTabuleiro(tabuleiro);
    
    // Coordenadas dos navios (definidas no código)
    // Navio horizontal: linha 2, coluna 3
    int linha_horizontal = 2, coluna_horizontal = 3;
    bool vertical_horizontal = false;
    
    // Navio vertical: linha 5, coluna 7
    int linha_vertical = 5, coluna_vertical = 7;
    bool vertical_vertical = true;
    
    // Posiciona o navio horizontal (se a posição for válida)
    if (posicaoValida(linha_horizontal, coluna_horizontal, TAMANHO_NAVIO, vertical_horizontal, tabuleiro)) {
        posicionarNavio(tabuleiro, linha_horizontal, coluna_horizontal, vertical_horizontal);
    } else {
        printf("Posição inválida para o navio horizontal!\n");
        return 1;
    }
    
    // Posiciona o navio vertical (se a posição for válida)
    if (posicaoValida(linha_vertical, coluna_vertical, TAMANHO_NAVIO, vertical_vertical, tabuleiro)) {
        posicionarNavio(tabuleiro, linha_vertical, coluna_vertical, vertical_vertical);
    } else {
        printf("Posição inválida para o navio vertical!\n");
        return 1;
    }
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
} 
    