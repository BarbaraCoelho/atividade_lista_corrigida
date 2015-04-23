/*
    Curso: Engenharia Eletronica
    Programacao de Computadores II - 2015/1
    Aluna: Barbara Coelho

                    Exercicio Pilha
*/

#include "funcoes_pilha.h"

/* função auxiliar: insere no início */
No* ins_ini (No* l, float v)
{
    No* p = (No*) malloc(sizeof(No));
    p->info = v;
    p->prox = l;
    return p;
}
/* função auxiliar: retira do início */
No* ret_ini (No* l)
{
    No* p = l->prox;
    free(l);
    return p;
}

Pilha* cria (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

void push (Pilha* p, float v)
{
    p->prim = ins_ini(p->prim,v);
}

float pop (Pilha* p)
{
    float v;
    if (vazia(p))
    {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }
    v = p->prim->info;
    p->prim = ret_ini(p->prim);
    return v;
}

int vazia (Pilha* p)
{
    return (p->prim==NULL);
}

void libera (Pilha* p)
{
    No* q = p->prim;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

/* imprime: versão com lista */
void imprime (Pilha* p)
{
    No* q;
    for (q=p->prim; q!=NULL; q=q->prox)
    printf("%f\n",q->info);
}
