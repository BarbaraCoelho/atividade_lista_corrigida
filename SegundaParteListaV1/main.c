/*
    Curso: Engenharia Eletrônica
    Programação de Computadores II - 2015/1
    Aluna: Bárbara Coelho

                          Lista Encadeada - Retangulo ponteiro
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_RetPont.h"

int main()
{
    Lista_ret*lst = inicializada();
    insere(&lst, 1, 1, 4, 4, 3, 255, 0 , 0);
    imprime(lst);
    insere(&lst, 1, 4, 8, 8, 7, 255, 0 , 0);
    imprime(lst);
    libera(lst);
    lst=NULL;
    imprime(lst);
    return 0;
}
