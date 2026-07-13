#include <stdlib.h>
#include "ordenacao.h"
#include "estatisticas.h"

void bubbleSort(int vetor[], int tamanho)
{
    int i, j;
    int temp;

    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = 0; j < tamanho - i - 1; j++)
        {
            registrarComparacao();

            if (vetor[j] > vetor[j + 1])
            {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int vetor[], int tamanho)
{
    int i, j;
    int menor;
    int temp;

    for (i = 0; i < tamanho - 1; i++)
    {
        menor = i;

        for (j = i + 1; j < tamanho; j++)
        {
            registrarComparacao();

            if (vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }

        if (menor != i)
        {
            temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    }
}

// insertion_sort
void insertionSort(int vetor[], int tamanho) {
    int i, j, chave;

    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        /* desloca os elementos maiores que 'chave' uma posição para a direita */
        while (j >= 0) {
            registrarComparacao();          /* comparação vetor[j] > chave */
            if (vetor[j] > chave) {
                vetor[j + 1] = vetor[j];
                j--;
            } else {
                break;
            }
        }

        vetor[j + 1] = chave;
    }
}

// merge_sort
static void merge(int vetor[], int esq, int meio, int dir) {
    int i, j, k;
    int n1 = meio - esq + 1;   /* tamanho do sub-vetor esquerdo */
    int n2 = dir - meio;       /* tamanho do sub-vetor direito  */

    int *esquerda = malloc(n1 * sizeof(int));
    int *direita  = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) esquerda[i] = vetor[esq + i];
    for (j = 0; j < n2; j++) direita[j]  = vetor[meio + 1 + j];

    i = 0;
    j = 0;
    k = esq;

    /* intercala os dois sub-vetores de volta em vetor[esq..dir] */
    while (i < n1 && j < n2) {
        registrarComparacao();              /* comparação esquerda[i] x direita[j] */
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    /* copia o que sobrou (não precisa de comparação, só resta um lado) */
    while (i < n1) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }
    while (j < n2) {
        vetor[k] = direita[j];
        j++;
        k++;
    }

    free(esquerda);
    free(direita);
}

/*
 * mergeSortRec()
 * --------------
 * Divide o vetor ao meio recursivamente até sub-vetores de 1 elemento
 * (já ordenados por definição), e depois vai juntando tudo com merge().
 *
 * Complexidade: O(n log n) em todos os casos (melhor, médio e pior).
 */
static void mergeSortRec(int vetor[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;

        mergeSortRec(vetor, esq, meio);
        mergeSortRec(vetor, meio + 1, dir);
        merge(vetor, esq, meio, dir);
    }
}

/* Ponto de entrada que respeita a assinatura definida em ordenacao.h */
void mergeSort(int vetor[], int tamanho) {
    mergeSortRec(vetor, 0, tamanho - 1);
}
