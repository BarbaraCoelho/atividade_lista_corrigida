/*
    Curso: Engenharia Eletronica
    Programacao de Computadores II - 2015/1
    Aluna: Barbara Coelho

                    Exercicio Pilha
*/

#ifndef FUNCOES_PILHA_H_INCLUDED
#define FUNCOES_PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct pilha Pilha;

struct no
{
    float info;
    struct no* prox;
};
struct pilha
{
    No* prim;
};

Pilha* cria (void);
void push (Pilha* p, float v);
float pop (Pilha* p);
int vazia (Pilha* p);
void libera (Pilha* p);
void imprime (Pilha* p);
No* ins_ini (No* l, float v);
No* ret_ini (No* l);

#endif // FUNCOES_PILHA_H_INCLUDED
