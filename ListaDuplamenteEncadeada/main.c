#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_dupEnc.h"

int main()
{
    int tipo;
    float x,y;
    Lista_het*lst = inicializada();
    //Lista_het* end1 = inicializada();
    insere_ret(&lst, 50, 400, 400, 50, 10, 255, 0 , 0);
    imprime(lst);
    insere_circ(&lst, 200, 200, 40, 50, 255, 0 , 0);
    imprime(lst);

    printf("Entre com o Tipo CIRC(0) ou RET(1):\n");
    scanf("%d",&tipo);
    printf("Entre com os dados x e y, respectivamente, para retirar:\n");
    scanf("%f",&x);
    scanf("%f",&y);
    printf("\n");
    lst = retira_het(lst,x,y,tipo);
    imprime(lst);

    /*end1 = busca(lst,x,y,tipo);
    if(end1 != NULL)
        printf("\nEncontra-se no endereço %p.\n",end1);
    else
        printf("\nEndereço nao encontrado\n");*/

    libera(lst);
    lst=NULL;

    return 0;
}

