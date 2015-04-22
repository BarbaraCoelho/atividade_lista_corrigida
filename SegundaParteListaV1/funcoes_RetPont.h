#ifndef FUNCOES_RETPONT_H_INCLUDED
#define FUNCOES_RETPONT_H_INCLUDED

typedef struct _lista_retangulo Lista_ret;

struct color
{
    unsigned int r;
    unsigned int g;
    unsigned int b;
};

struct retangulo
{
    int x1;
    int y1;
    int x2;
    int y2;
    struct color cor;
    int Thickness;
};

struct _lista_retangulo
{
    struct retangulo ret;
    Lista_ret* prox_ret;
};

Lista_ret* inicializada (void);
void insere(Lista_ret**lst, int x1, int y1, int x2, int y2, int Thickness, int cor_r, int cor_g, int cor_b);
void imprime(Lista_ret* lst);
void libera(Lista_ret* lst);

#endif // FUNCOES_RETPONT_H_INCLUDED
