/*
    Curso: Engenharia Eletrônica
    Programação de Computadores II - 2015/1
    Aluna: Bárbara Coelho

                          Lista Encadeada - Retangulo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_ret.h"

int main()
{
    Lista_ret*lst = inicializada();             //inicializa em NULL
    insere(&lst, 1, 1, 4, 4, 3, 255, 0 , 0);    // insere os parametros do retangulo
    imprime(lst);                               //imprime os valores
    libera(lst);                                //libera lista
    lst=NULL;
    imprime(lst);
    return 0;
}
