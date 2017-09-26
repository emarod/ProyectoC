#include <stdio.h>
#include <stdlib.h>
#include <lista.h>

int main()
{
    printf("Hello world!\n");
    TLista test = crear_lista();
    int num = 10;
    int num2 = 14;
    int num3 = 4;
    //int y = *((int *) e);
    //printf("Elemento--> %i",y);
    l_insertar(test,NULL,&num);
    printf("La cantidad de elementos en la lista es:%i\n",l_size(test));
    l_insertar(test,NULL,&num2);
    printf("La cantidad de elementos en la lista es:%i\n",l_size(test));
    l_insertar(test,NULL,&num3);
    printf("La cantidad de elementos en la lista es:%i\n",l_size(test));
    TPosicion pos = l_primera(test);
    TElemento pos_e = pos->elemento;
    TPosicion last = l_ultima(test);
    TElemento last_e = last->elemento;
    int y = *((int*)pos_e);
    printf("Tus primer pos es pos es %i \n",y);
    printf("Tus ultima pos es pos es %i \n",*((int*)last_e));
    l_eliminar(test,l_primera(test));
    printf("La cantidad de elementos en la lista es:%i\n",l_size(test));
    printf("Tus primer pos es pos es %i \n",*((int*)l_primera(test)->elemento));
    printf("Tus ultima pos es pos es %i \n",*((int*)l_ultima(test)->elemento));

    return 0;
}
