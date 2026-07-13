#include <stdio.h>
#include <time.h>
#include "estatisticas.h"

/* Variáveis estáticas: só visíveis dentro deste ficheiro.
 * Isto evita que outros módulos mexam diretamente nelas — só podem
 * usar as funções abaixo (encapsulamento, mesmo em C). */
static clock_t inicio;
static clock_t fim;
static long contadorComparacoes = 0;

void iniciarCronometro() {
    inicio = clock();
}

//CLOCKS_PER_SEC e uma funcao de time.h
double pararCronometro() {
    fim = clock();
    return ((double)(fim - inicio) / CLOCKS_PER_SEC);
}

void resetContador() {
    contadorComparacoes = 0;
}

/* invoquem esta funcao nos vossos algoritmos para contar o
 * numero de ordenacoes feitos com cada algoritmo de ordenacao
 */
void registrarComparacao() {
    contadorComparacoes++;
}

long obterComparacoes(void) {
    return contadorComparacoes;
}

void mostrarResultados(const char *nomeAlgoritmo, double tempo, long comparacoes) {
    printf("\n--- Resultados: %s ---\n", nomeAlgoritmo);
    printf("Tempo de execução : %.20f ms\n", tempo);
    printf("Numero de comparações: %ld\n", comparacoes);
}
