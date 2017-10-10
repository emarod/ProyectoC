#include <stdio.h>
#include <stdlib.h>
#include <lista.h>
#include <lista_ordenada.h>
#include <trie.h>
#include <string.h>

/**int main()
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
}**/

int funcionComparador(TElemento i, TElemento ii){
    int respuesta;
    int n1= (int)i;
    int n2= (int)ii;

    printf("%i,%i",n1,n2);

    if(n1>n2) respuesta= 1;
    if(n1<n2) respuesta= -1;
    if(n1==n2) respuesta=0;

    return respuesta;

}

int main(){
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

    //TEST LISTA ORDENADA
    printf("----------TEST LISTA ORDENADA---------\n");
    TListaOrdenada test_ord= crearlistaordenada(funcionComparador);
    lo_insertar(test_ord,&num);
    printf("La cantidad de elementos en la lista es:%i\n",lo_size(test_ord));
    lo_insertar(test_ord,&num2);
    printf("La cantidad de elementos en la lista es:%i\n",lo_size(test_ord));
    lo_insertar(test_ord,&num3);
    printf("La cantidad de elementos en la lista es:%i\n",lo_size(test_ord));
    TPosicion pos_ord = lo_primera(test_ord);
    TElemento pos_e_ord = pos_ord->elemento;
    TPosicion last_ord = lo_ultima(test_ord);
    TElemento last_e_ord = last_ord->elemento;
    int y_ord = *((int*)pos_e_ord);
    printf("Tus primer pos es pos es %i \n",y_ord);
    printf("Tus ultima pos es pos es %i \n",*((int*)last_e_ord));
    lo_eliminar(test_ord,lo_primera(test_ord));
    printf("La cantidad de elementos en la lista es:%i\n",lo_size(test_ord));
    printf("La primer pos es %i \n",*((int*)lo_primera(test_ord)->elemento));
    printf("La ultima pos es %i \n",*((int*)lo_ultima(test_ord)->elemento));



    //char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    TTrie trie= crear_trie();
    printf("Pertenece el Hello al trie? ");
    //tr_insertar(trie,greeting);
    //int i = tr_pertenece(trie,greeting);
    //printf("Pertenece el Hello al trie? %i",i);

    return 0;

}

/**int main()
{
    printf("Hello world!\n");
    TListaOrdenada test = crearlistaordenada(int (*funcionComparador)(char *,char *));
    int num = 10;
    int num2 = 14;
    int num3 = 4;
    //int y = *((int *) e);
    //printf("Elemento--> %i",y);
    lo_insertar(test,&num);
    printf("La cantidad de elementos en la lista es:%i\n",lo_size(test));
    lo_insertar(test,&num2);
    printf("La cantidad de elementos en la lista es:%i\n",lo_size(test));
    lo_insertar(test,&num3);
    printf("La cantidad de elementos en la lista es:%i\n",lo_size(test));
    TPosicion pos = lo_primera(test);
    TElemento pos_e = pos->elemento;
    TPosicion last = lo_ultima(test);
    TElemento last_e = last->elemento;
    int y = *((int*)pos_e);
    printf("Tus primer pos es pos es %i \n",y);
    printf("Tus ultima pos es pos es %i \n",*((int*)last_e));
    lo_eliminar(test,lo_primera(test));
    printf("La cantidad de elementos en la lista es:%i\n",lo_size(test));
    printf("Tus primer pos es pos es %i \n",*((int*)lo_primera(test)->elemento));
    printf("Tus ultima pos es pos es %i \n",*((int*)lo_ultima(test)->elemento));

    return 0;
    }**/
