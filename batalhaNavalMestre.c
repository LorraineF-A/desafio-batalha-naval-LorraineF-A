#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Nível Mestre - Habilidades especiais e áreas de efeito.  

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5 

// Funções para o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
bool posicaoValida(int linha, int coluna, int tamanho, char orientacao, int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao);
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);

// Funções para habilidades
void criarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]);
void criarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]);
void criarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]);
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
                      int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
                      int centroX, int centroY); 

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona alguns navios (como no exemplo anterior)
    posicionarNavio(tabuleiro, 2, 3, 'H'); // Horizontal
    posicionarNavio(tabuleiro, 5, 7, 'V'); // Vertical
    posicionarNavio(tabuleiro, 1, 1, 'D'); // Diagonal principal
    posicionarNavio(tabuleiro, 3, 8, 'd'); // Diagonal secundária
    
    // Cria matrizes de habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);
    
    // Aplica habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4);     // Cone no centro
    aplicarHabilidade(tabuleiro, cruz, 7, 2);     // Cruz na parte inferior esquerda
    aplicarHabilidade(tabuleiro, octaedro, 2, 7); // Octaedro perto de um navio
    
    // Exibe o tabuleiro com as áreas de efeito
    exibirTabuleiro(tabuleiro);
    
    return 0;
} 

// Implementação das funções do tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
} 

bool posicaoValida(int linha, int coluna, int tamanho, char orientacao, int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < tamanho; i++) {
        int novaLinha = linha;
        int novaColuna = coluna;
        
        switch (orientacao) {
            case 'H': novaColuna += i; break;
            case 'V': novaLinha += i; break;
            case 'D': novaLinha += i; novaColuna += i; break;
            case 'd': novaLinha += i; novaColuna -= i; break;
        }
        
        if (novaLinha < 0 || novaLinha >= TAM_TABULEIRO || 
            novaColuna < 0 || novaColuna >= TAM_TABULEIRO) {
            return false;
        }
        
        if (tabuleiro[novaLinha][novaColuna] != AGUA) {
            return false;
        }
    }
    return true;
}

void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < 3; i++) { // Navios de tamanho 3
        int novaLinha = linha;
        int novaColuna = coluna;
        
        switch (orientacao) {
            case 'H': novaColuna += i; break;
            case 'V': novaLinha += i; break;
            case 'D': novaLinha += i; novaColuna += i; break;
            case 'd': novaLinha += i; novaColuna -= i; break;
        }
        
        tabuleiro[novaLinha][novaColuna] = NAVIO;
    }
}

void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval com Habilidades:\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\nLegenda:\n");
    printf("0 - Água\n3 - Navio\n5 - Área de habilidade\n");
}

// Implementação das funções de habilidades
void criarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Cone: forma triangular apontando para baixo
            if (j >= i && j < TAM_HABILIDADE - i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void criarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Cruz: linha e coluna central
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void criarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Octaedro: forma de losango
            int dist = abs(i - centro) + abs(j - centro);
            if (dist <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
                      int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
                      int centroX, int centroY) {
    int offset = TAM_HABILIDADE / 2;
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int x = centroX - offset + i;
            int y = centroY - offset + j;
            
            // Verifica se está dentro dos limites do tabuleiro
            if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO) {
                // Se a posição na matriz de habilidade for 1, marca no tabuleiro
                if (habilidade[i][j] == 1) {
                    // Não sobrescreve os navios, apenas marca a água
                    if (tabuleiro[x][y] == AGUA) {
                        tabuleiro[x][y] = HABILIDADE;
                    }
                }
            }
        }
    }
} 