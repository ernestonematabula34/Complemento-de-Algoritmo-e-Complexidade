#include <stdlib.h>
#include <time.h>
#include "menu.h"

int main() { 
    /* inicializa gerador de aleatorios uma unica vez, 
    evita que a cada execucao do programa os numeros gerados aleatoriamente sejam os mesmos*/
    srand((unsigned int) time(NULL)); 
   
    menuPrincipal();
    
    return 0;
}
