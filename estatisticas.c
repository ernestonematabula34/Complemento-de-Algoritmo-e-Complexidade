#include <stdio.h>
#include <time.h>
#include "estatisticas.h"

/* Variáveis estáticas: só visíveis dentro deste ficheiro.
 * Isto evita que outros módulos mexam diretamente nelas — só podem
 * usar as funções abaixo (encapsulamento, mesmo em C). */ 
static long contadorComparacoes = 0;
static struct timespec inicio, fim;

void iniciarCronometro() {
    clock_gettime(CLOCK_MONOTONIC, &inicio);
}

//CLOCKS_PER_SEC e uma funcao de time.h
double pararCronometro() {
    clock_gettime(CLOCK_MONOTONIC, &fim);
    double segundos = (fim.tv_sec - inicio.tv_sec)
                     + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
    return segundos;
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
    printf("Tempo de execução : %.8f segundos\n", tempo);
    printf("Numero de comparações: %ld\n", comparacoes);
}
