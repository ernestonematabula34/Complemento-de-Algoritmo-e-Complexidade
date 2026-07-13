[README.md](https://github.com/user-attachments/files/29867230/README.md)
# Comparação de Algoritmos de Ordenação

Projeto da disciplina **Complemento de Algoritmo e Complexidade** — Departamento de Ciências da Computação, Faculdade de Ciências, Universidade Agostinho Neto (UAN).

Aplicação em linguagem C que permite inserir ou gerar vetores de inteiros e ordená-los usando quatro algoritmos clássicos — **Bubble Sort**, **Selection Sort**, **Insertion Sort** e **Merge Sort** — comparando o tempo de execução e o número de comparações de cada um.

## Índice

- [Funcionalidades](#funcionalidades)
- [Estrutura do projeto](#estrutura-do-projeto)
- [Como compilar e executar](#como-compilar-e-executar)
- [Como usar](#como-usar)
- [Algoritmos implementados](#algoritmos-implementados)
- [Metodologia de comparação](#metodologia-de-comparação)
- [Equipa e divisão de tarefas](#equipa-e-divisão-de-tarefas)
- [Prazos](#prazos)

## Funcionalidades

- Inserção manual de elementos
- Geração automática de elementos aleatórios
- Exibição do vetor original e do vetor ordenado
- Ordenação por Bubble Sort, Selection Sort, Insertion Sort ou Merge Sort
- Execução de todos os algoritmos em sequência, sobre o mesmo vetor de entrada, para comparação direta
- Medição do tempo de execução (segundos) e do número de comparações de cada algoritmo

## Estrutura do projeto

```
.
├── main.c              # Ponto de entrada do programa
├── menu.h / menu.c      # Menu principal e integração dos algoritmos
├── operandovetores.h / operandovetores.c        # Entrada/saída de dados do vetor
├── estatisticas.h / estatisticas.c # Cronómetro e contador de comparações
├── ordenacao.h          # Interface comum aos 4 algoritmos de ordenação
├── ordenacao.c        # Implementação do Bubble Sort, Insertion Sort, Selection Sort e MergeSort
├── Makefile
└── README.md
```

Cada módulo tem uma responsabilidade única:

| Módulo | Responsabilidade |
|---|---|
| `menu` | Interface de texto e integração de todos os módulos |
| `operandovetores` | Preencher e mostrar o vetor |
| `estatisticas` | Medir tempo de execução e contar comparações |
| `ordenacao.h` | Contrato comum (assinatura) que os 4 algoritmos seguem |

## Como compilar e executar

Requisitos: `gcc` e `make`.

```bash
git clone <url-do-repositorio>
cd <pasta-do-projeto>
make
./ordenacao
```

Para limpar o executável gerado:

```bash
make clean
```

## Como usar

Ao executar o programa, é apresentado um menu:

```
===== Comparacao de Algoritmos de Ordenacao =====
1. Inserir elementos manualmente
2. Gerar elementos aleatorios
3. Exibir vetor original
4. Ordenar com Bubble Sort
5. Ordenar com Selection Sort
6. Ordenar com Insertion Sort
7. Ordenar com Merge Sort
8. Ordenar com TODOS e comparar
0. Sair
```

Fluxo típico: escolher a opção **1** ou **2** para preencher o vetor, depois a opção **8** para ver os quatro algoritmos ordenarem o mesmo vetor e comparar o tempo de execução e o número de comparações de cada um.

## Algoritmos implementados

| Algoritmo | Melhor caso | Pior caso | Complexidade espacial |
|---|---|---|---|
| Bubble Sort | O(n) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n) |

A análise detalhada do funcionamento, melhor caso, pior caso e justificação da complexidade de cada algoritmo está no relatório do projeto.

## Metodologia de comparação

Para garantir uma comparação justa entre os quatro algoritmos:

- Todos ordenam uma **cópia** do vetor original (`copiarVetor()`), nunca o vetor de entrada diretamente.
- O contador de comparações é reiniciado (`resetContador()`) antes de cada execução.
- O tempo é medido com `clock()` da biblioteca `time.h`, envolvendo apenas a chamada ao algoritmo.

## Autores

| Pessoa | Responsabilidade |
|---|---|
| Bruna Panzo | Bubble Sort e Selection Sort, com respetiva análise de complexidade | 
| Ernesto Nematabula | Estrutura do programa, menu, entradas/saídas, cronómetro, contador de comparações e integração final  |
| Raul Rana | Insertion Sort e Merge Sort, com respetiva análise de complexidade |

Introdução, conclusão, testes de integração e apresentação foram preparados em conjunto pelo grupo.
