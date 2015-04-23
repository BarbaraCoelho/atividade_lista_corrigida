/*
    Curso: Engenharia Eletronica
    Programacao de Computadores II - 2015/1
    Aluna: Barbara Coelho

                    Exercicio Pilha
*/

#include "funcoes_pilha.h"
#include "f_calculadora.h"

int main()
{
    char c;
    float v;
    Calc* calc;
    /* cria calculadora com precisão de impressão de duas casas decimais*/
    calc = cria_calc("%.2f\n");
    while (c!='q')
    {
        /* le proximo caractere nao branco */
        scanf(" %c",&c);
        /* verifica se e' operador valido */
        if (c=='+' || c=='-' || c=='*' || c=='/')
        {
            operador(calc,c);
        }
        /* devolve caractere lido e tenta ler número */
        else
        {
            ungetc(c,stdin);
            if (scanf("%f",&v) == 1)
                operando(calc,v);
        }
    }
    libera_calc(calc);
    return 0;
}
