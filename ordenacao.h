#ifndef ORDENACAO_H
#define ORDENACAO_H

/*
 *   - Sempre que fizerem uma comparação entre dois elementos do vetor
 *     (ex.: if (vetor[j] > vetor[j+1])), chamem registrarComparacao()
 *     (declarada em estatisticas.h) logo antes ou depois da comparação.
 *   - Não chamem iniciarCronometro()/pararCronometro() dentro do próprio
 *     algoritmo — isso é feito pelo menu, que envolve a chamada
 *     ao algoritmo com o cronómetro, para manter tudo consistente.
 */

void bubbleSort(int vetor[], int tamanho);
void selectionSort(int vetor[], int tamanho);
void insertionSort(int vetor[], int tamanho);
void mergeSort(int vetor[], int tamanho);

/* Tipo "ponteiro para função de ordenação", usado pelo menu para tratar
 * qualquer um dos 4 algoritmos de forma genérica. */
typedef void (*FuncaoOrdenacao)(int vetor[], int tamanho);

#endif /* ORDENACAO_H */
