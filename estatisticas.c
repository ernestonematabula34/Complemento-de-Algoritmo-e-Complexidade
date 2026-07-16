#include <stdio.h>
#include <time.h>
#include "estatisticas.h"

/* Variáveis estáticas: só visíveis dentro deste ficheiro.
 * Isto evita que outros módulos mexam diretamente nelas — só podem
 * usar as funções abaixo (encapsulamento, mesmo em C). */
static clock_t inicioClock;
static clock_t fimClock;
static long contadorComparacoes = 0;

void iniciarCronometro(void) {
    inicioClock = clock();
}

double pararCronometro(void) {
    fimClock = clock();
    return (double)(fimClock - inicioClock) / CLOCKS_PER_SEC;
}

void resetContador(void) {
    contadorComparacoes = 0;
}

void registrarComparacao(void) {
    contadorComparacoes++;
}

long obterComparacoes(void) {
    return contadorComparacoes;
}

void mostrarResultados(const char *nomeAlgoritmo, double tempo, long comparacoes) {
    printf("\n--- Resultados: %s ---\n", nomeAlgoritmo);
    printf("Tempo de execucao : %.6f segundos\n", tempo);
    printf("Numero de comparacoes: %ld\n", comparacoes);
}

