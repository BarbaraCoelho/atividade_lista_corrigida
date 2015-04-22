#include <stdio.h>
#include <stdlib.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "funcoes_allegro.h"

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

void draw (Lista_het*lst)
{
    Lista_het* p;
	for (p=lst; p!=NULL; p=p->prox_het)
    {
        if(p->tipo == 1)
        {
            Retangulo *r = (Retangulo*) p->info;
            al_draw_rectangle(r->x1, r->y1, r->x2, r->y2, al_map_rgb(r->cor.r, r->cor.g, r->cor.b), r->Thickness);
        }
        else if(p->tipo == 0)
        {
            Circulo* c = (Circulo*) p->info;
            al_draw_circle(c->cx, c->cy, c->r, al_map_rgb(c->cor.r, c->cor.g, c->cor.b), c->Thickness);
        }
    }
}
