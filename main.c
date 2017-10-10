#include <stdio.h>
#include <stdlib.h>
#include <lista.h>
#include <lista_ordenada.h>
#include <trie.h>
#include <string.h>

int comparador2(TElemento a,TElemento b){
    printf("Comparador \n");
    char charA = ((TNodo) a)->rotulo;
	char charB = ((TNodo) b)->rotulo;
	printf("Letra %c es menor que %c?? \n\n",charA,charB);

    if(charA>charB) {return 1;}
    else
    {
        if(charA<charB) {
            printf("Letra %c es menor que %c \n",charA,charB);
            return -1;
        }
        else {return 0;}
    }
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
    TNodo ch = malloc(sizeof(TNodo));
    ch->rotulo = 'e';
    TNodo ch2 = malloc(sizeof(TNodo));
    ch2->rotulo = 'z';
    TNodo ch3 = malloc(sizeof(TNodo));
    ch3->rotulo = 'j';
    TListaOrdenada test_ord= crear_lista_ordenada(&comparador2);
    lo_insertar(test_ord,&ch);
    printf("La cantidad de elementos en la lista es:%i\n",lo_size(test_ord));
    lo_insertar(test_ord,&ch2);
    printf("La cantidad de elementos en la lista es:%i\n",lo_size(test_ord));
    lo_insertar(test_ord,&ch3);
    printf("La cantidad de elementos en la lista es:%i\n",lo_size(test_ord));
    printf("La primer pos es %c \n",((TNodo)lo_primera(test_ord)->elemento)->rotulo);
    printf("La ultima pos es %c \n",((TNodo)lo_ultima(test_ord)->elemento)->rotulo);

    //char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    //TTrie trie= crear_trie();
    printf("Pertenece el Hello al trie? ");
    //tr_insertar(trie,greeting);
    //int i = tr_pertenece(trie,greeting);
    //printf("Pertenece el Hello al trie? %i",i);

    return 0;

}
