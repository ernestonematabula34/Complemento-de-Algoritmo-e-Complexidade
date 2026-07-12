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
    int opcao;

    do {
        mostrarOpcoes();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirManual(vetor, &tamanho);
                break;
            case 2:
                gerarAleatorio(vetor, &tamanho);
                break;
            case 3:
                if (tamanho == 0) {
                    printf("Vetor ainda vazio. Insira ou gere elementos primeiro.\n");
                } else {
                    printf("Vetor original:\n");
                    exibirVetor(vetor, tamanho);
                }
                break;
            case 4:
                if (tamanho > 0) executarOrdenacao("Bubble Sort", bubbleSort, vetor, tamanho);
                else printf("Vetor vazio.\n");
                break;
            case 5:
                if (tamanho > 0) executarOrdenacao("Selection Sort", selectionSort, vetor, tamanho);
                else printf("Vetor vazio.\n");
                break;
            case 6:
                //if (tamanho > 0) executarOrdenacao("Insertion Sort", insertionSort, vetor, tamanho);
                //else printf("Vetor vazio.\n");
                break;
            case 7:
                //if (tamanho > 0) executarOrdenacao("Merge Sort", mergeSort, vetor, tamanho);
                //else printf("Vetor vazio.\n");
                break;
            case 8:
                 if (tamanho > 0) {
                    executarOrdenacao("Bubble Sort", bubbleSort, vetor, tamanho);
                    executarOrdenacao("Selection Sort", selectionSort, vetor, tamanho);
                   // executarOrdenacao("Insertion Sort", insertionSort, vetor, tamanho);
                   // executarOrdenacao("Merge Sort", mergeSort, vetor, tamanho);
                } else {
                    printf("Vetor vazio.\n");
                }
                break;
            case 0:
                printf("A sair...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}
