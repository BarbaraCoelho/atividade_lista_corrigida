#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_allegro.h"


int main()
{
    int width = 640;
	int height = 480;
	ALLEGRO_DISPLAY *display = NULL;
	if(!al_init()){
        printf("Falha");
        return -1;
	}										            //initialize Allegro
	display = al_create_display(width, height);			//create our display object
	if(!display)										//test display object
		return -1;
	al_init_primitives_addon();

    Lista_het*lst = inicializada();
    insere_ret(&lst, 90, 150, 400, 300, 3, 255, 0 , 0);
    imprime(lst);
    insere_ret(&lst, 100, 10, 200, 100, 3, 255, 0 , 0);
    imprime(lst);
    insere_circ(&lst,300,300,100,5,0, 0, 255);
    imprime(lst);

    draw(lst);

    al_flip_display();
	al_rest(4.0);
	al_destroy_display(display);

    libera(lst);
    lst=NULL;

    return 0;
}
