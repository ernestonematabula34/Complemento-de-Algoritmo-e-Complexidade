#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "operandovetores.h"

int i;

/* Le uma linha inteira do teclado e tenta converte-la para um numero
 * inteiro dentro de [minimo, maximo]. Se a entrada nao for um numero
 * valido (letras, vazio, texto a mais) ou estiver fora do intervalo,
 * mostra uma mensagem de erro e pergunta outra vez -- nunca avanca com
 * um valor invalido nem trava o programa. */
static int lerInteiroValidado(const char *prompt, int minimo, int maximo) {
    char linha[64];
    long valor;
    char *fimConversao;

    while (1) {
        printf("%s", prompt);

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            /* entrada terminou inesperadamente (ex.: Ctrl+D); usa o minimo */
            return minimo;
        }

        linha[strcspn(linha, "\n")] = '\0'; /* remove o '\n' final */

        valor = strtol(linha, &fimConversao, 10);

        /* invalido se: nao converteu nada, ou sobrou texto a seguir ao numero */
        if (fimConversao == linha || *fimConversao != '\0') {
            printf("Entrada invalida. Escreve apenas um numero inteiro.\n");
            continue;
        }
        if (valor < minimo || valor > maximo) {
            printf("Valor fora do intervalo permitido [%d, %d]. Tenta novamente.\n", minimo, maximo);
            continue;
        }

        return (int) valor;
    }
}

/* Le 'tamanho' e depois cada elemento, um a um, do teclado -- com validação. */
void inserirManual(int vetor[], int *tamanho) {
    char prompt[64];
    snprintf(prompt, sizeof(prompt), "Quantos elementos deseja inserir? (1 a %d): ", TAMANHO_MAXIMO);
    *tamanho = lerInteiroValidado(prompt, 1, TAMANHO_MAXIMO);

    for (i = 0; i < *tamanho; i++) {
        char promptElemento[32];
        snprintf(promptElemento, sizeof(promptElemento), "Elemento [%d]: ", i);
        vetor[i] = lerInteiroValidado(promptElemento, INT_MIN, INT_MAX);
    }
}

/* Gera 'tamanho' inteiros aleatórios entre 0 e 999 -- com validação do tamanho. */
void gerarAleatorio(int vetor[], int *tamanho) {
    char prompt[64];
    snprintf(prompt, sizeof(prompt), "Quantos elementos aleatorios deseja gerar? (1 a %d): ", TAMANHO_MAXIMO);
    *tamanho = lerInteiroValidado(prompt, 1, TAMANHO_MAXIMO);

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
