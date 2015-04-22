#ifndef FUNCOES_RET_H_INCLUDED
#define FUNCOES_RET_H_INCLUDED

typedef struct _lista_retangulo Lista_ret;
typedef struct retangulo Retangulo;
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
struct _lista_retangulo
{
    Retangulo* info;
    Lista_ret* prox_ret;
};

Lista_ret* inicializada (void);
void insere(Lista_ret**lst, int x1, int y1, int x2, int y2, int Thickness, int cor_r, int cor_g, int cor_b);
void imprime(Lista_ret* lst);
void libera(Lista_ret* lst);


#endif // FUNCOES_RET_H_INCLUDED
