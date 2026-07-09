#include <stdio.h>
#include <stdlib.h>
#include "operandovetores.h"

int i;

/* Lê 'tamanho' e depois cada elemento, um a um, do teclado. */
void inserirManual(int vetor[], int *tamanho) {
    printf("Quantos elementos deseja inserir? (max %d): ", TAMANHO_MAXIMO);
    scanf("%d", tamanho);

    if (*tamanho <= 0 || *tamanho > TAMANHO_MAXIMO) {
        printf("Tamanho invalido. A usar 10 por omissao.\n");
        *tamanho = 10;
    }

    for (i = 0; i < *tamanho; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
}

/* Gera 'tamanho' inteiros aleatórios entre 0 e 999. */
void gerarAleatorio(int vetor[], int *tamanho) {
    printf("Quantos elementos aleatorios deseja gerar? (max %d): ", TAMANHO_MAXIMO);
    scanf("%d", tamanho);

    if (*tamanho <= 0 || *tamanho > TAMANHO_MAXIMO) {
        printf("Tamanho invalido. A usar 10 por omissao.\n");
        *tamanho = 10;
    }

    for (i = 0; i < *tamanho; i++) {
        vetor[i] = rand() % 1000;
    }
}

void exibirVetor(const int vetor[], int tamanho) {
    printf("[ ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

/* Copia o vetor original para uma cópia de trabalho.Assim  
   os 4 algoritmos ordenam sempre o MESMO vetor
de entrada, garantindo comparações justas entre eles. 
 */
void copiarVetor(const int origem[], int destino[], int tamanho) {
    for (i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}
