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
