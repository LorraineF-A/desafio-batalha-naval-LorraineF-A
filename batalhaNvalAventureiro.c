#include <stdio.h>
#include <stdbool.h>

// Desafio Batalha Naval - MateCheck
//Nível Aventureiro - Tabuleiro Completo e Navios Diagonais 

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3 

// Função para inicializar o tabuleiro com 0s (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
} 

// Função para verificar se a posição do navio é válida
bool posicaoValida(int linha, int coluna, int tamanho, char orientacao, int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Verifica se está dentro dos limites do tabuleiro
    for (int i = 0; i < tamanho; i++) {
        int novaLinha = linha;
        int novaColuna = coluna;
        
        // Calcula a próxima posição baseada na orientação
        switch (orientacao) {
            case 'H': // Horizontal
                novaColuna += i;
                break;
            case 'V': // Vertical
                novaLinha += i;
                break;
            case 'D': // Diagonal principal (linha e coluna aumentam)
                novaLinha += i;
                novaColuna += i;
                break;
            case 'd': // Diagonal secundária (linha aumenta, coluna diminui)
                novaLinha += i;
                novaColuna -= i;
                break;
        }
        
        // Verifica limites
        if (novaLinha < 0 || novaLinha >= TAMANHO_TABULEIRO || 
            novaColuna < 0 || novaColuna >= TAMANHO_TABULEIRO) {
            return false;
        }
        
        // Verifica sobreposição
        if (tabuleiro[novaLinha][novaColuna] != AGUA) {
            return false;
        }
    }
    
    return true;
} 

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                    int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int novaLinha = linha;
        int novaColuna = coluna;
        
        switch (orientacao) {
            case 'H': // Horizontal
                novaColuna += i;
                break;
            case 'V': // Vertical
                novaLinha += i;
                break;
            case 'D': // Diagonal principal
                novaLinha += i;
                novaColuna += i;
                break;
            case 'd': // Diagonal secundária
                novaLinha += i;
                novaColuna -= i;
                break;
        }
        
        tabuleiro[novaLinha][novaColuna] = NAVIO;
    }
} 

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval:\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
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
    
    // Definindo os navios (coordenadas e orientações)
    // Navio 1: Horizontal
    int linha1 = 2, coluna1 = 3;
    char orientacao1 = 'H';
    
    // Navio 2: Vertical
    int linha2 = 5, coluna2 = 7;
    char orientacao2 = 'V';
    
    // Navio 3: Diagonal principal (\)
    int linha3 = 1, coluna3 = 1;
    char orientacao3 = 'D';
    
    // Navio 4: Diagonal secundária (/)
    int linha4 = 3, coluna4 = 8;
    char orientacao4 = 'd';
    
    // Posiciona os navios (com validação)
    if (!posicaoValida(linha1, coluna1, TAMANHO_NAVIO, orientacao1, tabuleiro)) {
        printf("Erro: Navio 1 (horizontal) em posição inválida!\n");
        return 1;
    }
    posicionarNavio(tabuleiro, linha1, coluna1, orientacao1);
    
    if (!posicaoValida(linha2, coluna2, TAMANHO_NAVIO, orientacao2, tabuleiro)) {
        printf("Erro: Navio 2 (vertical) em posição inválida!\n");
        return 1;
    }
    posicionarNavio(tabuleiro, linha2, coluna2, orientacao2);
    
    if (!posicaoValida(linha3, coluna3, TAMANHO_NAVIO, orientacao3, tabuleiro)) {
        printf("Erro: Navio 3 (diagonal \\) em posição inválida!\n");
        return 1;
    }
    posicionarNavio(tabuleiro, linha3, coluna3, orientacao3);
    
    if (!posicaoValida(linha4, coluna4, TAMANHO_NAVIO, orientacao4, tabuleiro)) {
        printf("Erro: Navio 4 (diagonal /) em posição inválida!\n");
        return 1;
    }
    posicionarNavio(tabuleiro, linha4, coluna4, orientacao4);
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
} 