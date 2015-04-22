#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_dupEnc.h"

Lista_het* inicializada (void)
{
    return NULL;
}

void insere_circ(Lista_het**lst, float cx, float cy, float r, float Thickness, float cor_r, float cor_g, float cor_b)
{
    Circulo* c = (Circulo*)malloc(sizeof(Circulo));
    Lista_het* novo = (Lista_het*)malloc(sizeof(Lista_het));
    if (novo==NULL) exit(EXIT_FAILURE);
    c->cx = cx;
    c->cy = cy;
    c->r = r;
    c->cor.r = cor_r;
    c->cor.g = cor_g;
    c->cor.b = cor_b;
    c->Thickness = Thickness;

    novo->tipo = CIRC;
    novo->info = c;
    novo->prox_het = *lst;
    novo->ant_het = NULL;
    *lst = novo;
}

void insere_ret(Lista_het**lst, float x1, float y1, float x2, float y2, float Thickness, float cor_r, float cor_g, float cor_b)
{
    Retangulo* r = (Retangulo*)malloc(sizeof(Retangulo));
    Lista_het* novo = (Lista_het*)malloc(sizeof(Lista_het));
    if (novo==NULL) exit(EXIT_FAILURE);
    novo->info = r;
    r->x1 = x1;
    r->y1 = y1;
    r->x2 = x2;
    r->y2 = y2;
    r->cor.r = cor_r;
    r->cor.g = cor_g;
    r->cor.b = cor_b;
    r->Thickness = Thickness;

    novo->tipo = RET;
    novo->info = r;
    novo->prox_het = *lst;
    novo->ant_het = NULL;
    *lst = novo;
}

void imprime(Lista_het*lst)
{
    Lista_het *p;
    for (p=lst; p!=NULL; p=p->prox_het)
    {
        switch (p->tipo)
        {
            case RET:
            {
                Retangulo *r = (Retangulo*) p->info;
                printf("Retangulo:\n x1: %.2f\n y1: %.2f\n x2: %.2f\n y2: %.2f\n Cor(%.2f,%.2f,%.2f)\n Thickness: %.2f\n",r->x1,r->y1,r->x2,r->y2,r->cor.r,r->cor.g,r->cor.b,r->Thickness);
            }
            break;
            case CIRC:
            {
                Circulo* c = (Circulo*) p->info;
                printf("Circulo:\n cx: %.2f\n cy: %.2f\n r: %.2f\n Cor(%.2f,%.2f,%.2f)\n Thickness: %.2f\n",c->cx,c->cy,c->r,c->cor.r,c->cor.g,c->cor.b,c->Thickness);
            }
            break;
        }
    }
    printf("-----------------------------------------------------------------------------\n");
}

void libera(Lista_het* lst)
{
    Lista_het* p = lst;
    while(p!=NULL)
    {
        Lista_het* t=p->prox_het;
        free(p);
        p=t;
    }
}

Lista_het* busca (Lista_het*lst,float x,float y,int tipo)
{
    Lista_het* p;
    if(tipo == CIRC)
    {
        for (p = lst; p != NULL; p = p->prox_het)
        {
             Circulo* c = (Circulo*) p->info;
            if ((c->cx == x) && (c->cy == y))
                return p;
        }
    }
    else if(tipo == RET)
    {
        for (p = lst; p != NULL; p = p->prox_het)
        {
            Retangulo *r = (Retangulo*) p->info;
            if ((r->x1 == x) && (r->y1 == y))
                return p;
        }
    }
    return NULL;
}

Lista_het* retira_het (Lista_het* lst, float x, float y, int tipo)
{
    Lista_het* p = busca(lst,x,y,tipo);
    if (p == NULL)
        return lst;
    if (lst == p)
        lst = p->prox_het;
    else
        p->ant_het->prox_het = p->prox_het;
    if (p->prox_het != NULL)
        p->prox_het->ant_het = p->ant_het;
    free(p);
    return lst;
}

float Area (Lista_het *p)
{
    float a;
    switch (p->tipo)
    {
        case RET:
        {
            Retangulo *r = (Retangulo*) p->info;
            a = ((r->x2)-(r->x1))*((r->y1)-(r->y2));
        }
        break;
        case CIRC:
        {
            Circulo *c = (Circulo*) p->info;
            a = PI * (c->r) * (c->r);
        }
        break;
    }
    return a;
}
