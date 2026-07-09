#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

/* ---- Cronómetro ---- */
void iniciarCronometro();
double pararCronometro();   /* retorna o tempo decorrido em segundos */

/* ---- Contador de comparações ---- */
void resetContador();
void registrarComparacao(); /* chamar a cada comparação entre elementos */
long obterComparacoes();

/* ---- Apresentação de resultados ---- */
void mostrarResultados(const char *nomeAlgoritmo, double tempo, long comparacoes);

#endif /* ESTATISTICAS_H */
