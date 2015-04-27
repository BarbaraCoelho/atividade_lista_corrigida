#ifndef FUNCOES_LISTA_H_INCLUDED
#define FUNCOES_LISTA_H_INCLUDED

typedef struct lista Lista;
struct lista
{
    int dado;
    Lista* prox;
};

Lista* inicializada(void);
void insere(int dado,Lista**lst);
void insere_ordenado(Lista** lst,int num);
void imprime(Lista* lst);
void imprime_rec (Lista* lst);
void libera(Lista* lst);
Lista* busca(Lista* lst, int num);
void retira(Lista** lst,int num);


#endif // FUNCOES_LISTA_H_INCLUDED
