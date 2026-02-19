#include <stdio.h>

#define TAM 10         
#define TAM_NAVIO 3  


int main() {

    // *** Declaração do tabuleiro***
   
    int tabuleiro[TAM][TAM];


    // Inicializa todas as posições com 0


    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

       // *** Definição das coordenadas iniciais***
 
  
    int linhaNavio1 = 2;
    int colunaNavio1 = 4;  // Navio 1 será horizontal

    int linhaNavio2 = 5;
    int colunaNavio2 = 1;  // Navio 2 será vertical

    // Variável de controle para detectar problemas
    int posicaoInvalida = 0;


    // ***Validação do navio horizontal***

        if (colunaNavio1 + TAM_NAVIO > TAM) {
        printf("Erro: Navio 1 ultrapassa os limites!\n");
        posicaoInvalida = 1;
    } else {

        // Verifica sobreposição

        for(int i = 0; i < TAM_NAVIO; i++) {
            if(tabuleiro[linhaNavio1][colunaNavio1 + i] != 0) {
                printf("Erro: Navio 1 sobrepoe outro navio!\n");
                posicaoInvalida = 1;
            }
        }
    }

    // ***Validação do navio vertical***
   

    if (linhaNavio2 + TAM_NAVIO > TAM) {
        printf("Erro: Navio 2 ultrapassa os limites!\n");
        posicaoInvalida = 1;
    } else {
        for(int i = 0; i < TAM_NAVIO; i++) {
            if(tabuleiro[linhaNavio2 + i][colunaNavio2] != 0) {
                printf("Erro: Navio 2 sobrepoe outro navio!\n");
                posicaoInvalida = 1;
            }
        }
    }

   
    // ***Posicionamento dos navios, só acontece se não houver erro.***

    if (!posicaoInvalida) {

        // Navio 1 - Horizontal
        // Preenche 3 posições na mesma linha
        for(int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaNavio1][colunaNavio1 + i] = 3;
        }

        // Navio 2 - Vertical
        // Preenche 3 posições na mesma coluna
        for(int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaNavio2 + i][colunaNavio2] = 3;
        }


        //  ***Impressão do tabuleiro, Exibe a matriz.***
       
        printf("\nTABULEIRO BATALHA NAVAL\n\n");

        for(int i = 0; i < TAM; i++) {
            for(int j = 0; j < TAM; j++) {
                printf("%d ", tabuleiro[i][j]); 
            }
            printf("\n");
        }

    } else {
        // Caso alguma validação falhe
        printf("Programa encerrado por posicao invalida.\n");
    }

    return 0;
}