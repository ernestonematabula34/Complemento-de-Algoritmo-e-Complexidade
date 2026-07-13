#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "operandovetores.h"
#include "estatisticas.h"
#include "ordenacao.h"

static void executarOrdenacao(const char *nome, FuncaoOrdenacao algoritmo,
                               const int original[], int tamanho) {
    int copia[TAMANHO_MAXIMO];
    copiarVetor(original, copia, tamanho);

    resetContador();
    iniciarCronometro();
    algoritmo(copia, tamanho);
    double tempo = pararCronometro();

    printf("\nVetor ordenado (%s):\n", nome);
    exibirVetor(copia, tamanho);
    mostrarResultados(nome, tempo, obterComparacoes());
}

static void mostrarOpcoes(void) {
    printf("\n===== Comparador de Algoritmos de Ordenacao =====\n");
    printf("1. Inserir elementos manualmente\n");
    printf("2. Gerar elementos aleatorios\n");
    printf("3. Exibir vector original\n");
    printf("4. Ordenar com Bubble Sort\n");
    printf("5. Ordenar com Selection Sort\n");
    printf("6. Ordenar com Insertion Sort\n");
    printf("7. Ordenar com Merge Sort\n");
    printf("8. Ordenar com TODOS e comparar\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void menuPrincipal() {
    int vetor[TAMANHO_MAXIMO];
    int tamanho = 0;
    char linha[16];
    char opcao;

    do {
        mostrarOpcoes();

        /* Le a linha toda como texto. Isto evita o ciclo infinito que
         * acontece com scanf("%d", ...) quando a pessoa escreve uma letra
         * em vez de um numero. */
        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            break; /* entrada terminou (ex.: Ctrl+D) */
        }

        /* remove o '\n' que o fgets deixa no fim da linha */
        linha[strcspn(linha, "\n")] = '\0';

        /* validacao: tem de ser exactamente um caracter (o digito da opcao) */
        if (strlen(linha) != 1) {
            printf("Opcao invalida. Escreve apenas um numero entre 0 e 8.\n");
            opcao = '\0';
            continue;
        }
        opcao = linha[0];

        switch (opcao) {
            case '1':
                inserirManual(vetor, &tamanho);
                break;
            case '2':
                gerarAleatorio(vetor, &tamanho);
                break;
            case '3':
                if (tamanho == 0) {
                    printf("Vetor ainda vazio. Insira ou gere elementos primeiro.\n");
                } else {
                    printf("Vetor original:\n");
                    exibirVetor(vetor, tamanho);
                }
                break;
            case '4':
                if (tamanho > 0) executarOrdenacao("Bubble Sort", bubbleSort, vetor, tamanho);
                else printf("Vetor vazio.\n");
                break;
            case '5':
                if (tamanho > 0) executarOrdenacao("Selection Sort", selectionSort, vetor, tamanho);
                else printf("Vetor vazio.\n");
                break;
            case '6':
                if (tamanho > 0) executarOrdenacao("Insertion Sort", insertionSort, vetor, tamanho);
                else printf("Vetor vazio.\n");
                break;
            case '7':
                if (tamanho > 0) executarOrdenacao("Merge Sort", mergeSort, vetor, tamanho);
                else printf("Vetor vazio.\n");
                break;
            case '8':
                 if (tamanho > 0) {
                    executarOrdenacao("Bubble Sort", bubbleSort, vetor, tamanho);
                    executarOrdenacao("Selection Sort", selectionSort, vetor, tamanho);
                    executarOrdenacao("Insertion Sort", insertionSort, vetor, tamanho);
                    executarOrdenacao("Merge Sort", mergeSort, vetor, tamanho);
                } else {
                    printf("Vetor vazio.\n");
                }
                break;
            case '0':
                printf("A sair...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != '0');
}
