#ifndef FUNCOES_ALLEGRO_H_INCLUDED
#define FUNCOES_ALLEGRO_H_INCLUDED

#define PI 3.14159

enum {CIRC=0,RET};
typedef struct _lista_Heterogenea Lista_het;
typedef struct retangulo Retangulo;
typedef struct circulo Circulo;
struct color
{
    float r;
    float g;
    float b;
};
struct retangulo
{
    float x1;
    float y1;
    float x2;
    float y2;
    struct color cor;
    float Thickness;
};
struct circulo
{
    float cx;
    float cy;
    float r;
    struct color cor;
    float Thickness;
};
struct _lista_Heterogenea
{
    int tipo;
    void *info;
    Lista_het* prox_het;
};

Lista_het* inicializada (void);
void insere_circ(Lista_het**lst, float cx, float cy, float r, float Thickness, float cor_r, float cor_g, float cor_b);
void insere_ret(Lista_het**lst, float x1, float y1, float x2, float y2, float Thickness, float cor_r, float cor_g, float cor_b);
void imprime(Lista_het*lst);
void libera(Lista_het* lst);
void draw (Lista_het*lst);

#endif // FUNCOES_ALLEGRO_H_INCLUDED
