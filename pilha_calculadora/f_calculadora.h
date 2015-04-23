/*
    Curso: Engenharia Eletronica
    Programacao de Computadores II - 2015/1
    Aluna: Barbara Coelho

                    Exercicio Pilha
*/

#ifndef F_CALCULADORA_H_INCLUDED
#define F_CALCULADORA_H_INCLUDED
#include <string.h>
#include <math.h>
#include "funcoes_pilha.h"

typedef struct calc Calc; /* define a interface da calculadora */

struct calc
{
    char f[21]; /* formato para impressão */
    Pilha* p;   /* pilha de operandos */
};

Calc* cria_calc (char* formato);
void operando (Calc* c, float v);
void operador (Calc* c, char op);
void libera_calc (Calc* c);

#endif // F_CALCULADORA_H_INCLUDED
